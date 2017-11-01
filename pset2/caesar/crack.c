/*
by Tara Elsen
crack function finds out the hash of a password

generate array of up to five bites, last bite is \0

Iteratate over the characters of hash with for

Explained: for the DES-based algorithm, the salt
consists of two characters from the alphabet ./0-9A-Za-z,
and the result of crypt will be those two characters
followed by 11 more from the same alphabet, 13 in total.
?Only the first 8 characters in the key are significant??

guess words -> check their hashes against segments of hash given

take salt, first two characters of hash
*/

#define _XOPEN_SOURCE // for crypt

#include <cs50.h> // used for get_string
#include <stdio.h> // used for printf
#include <string.h> // used for strlen
#include <ctype.h> // used for isalpha
#include <stdlib.h> // for atoi
#include <crypt.h> // for crypt

int main(int argc, char* argv[])
{

    // accept only two arguments from command line
    // hash is max 13 characters. First two elements are the salt,
    // the other 11 are the key

    if (argc != 2)
    {
        printf("Usage: ./crack hash \n");
        return 1;
    }

    // make second command line argument into string
    char* hash = argv[1];
    char salt[3];
    strncpy(salt, hash, 2);
    salt[2] = '\0'; // null terminates destination

    char* key = hash + 2; // just key without salt

    printf("key: %s\n", key);
    printf("salt: %s\n", salt);

    char* abAB = "abcdefghijklmnopqrstuvwxyzQWERTYUIOPASDFGHJKLZXCVBNM";

    for (int i = 0, n = strlen(abAB); i < n; i++)
    {
        //check for every length
        char tri1[2] = {abAB[i], 0};

        // produce my own encrpyted key with salt
        char* cr1 = crypt(tri1, salt);

        // if own key is equal to key provided, print out the string tried.
        if (strcmp(cr1, hash) == 0)
        {
            printf("%s\n", tri1);
            return 0;
        }

        for (int j = 0, m = strlen(abAB); j < m; j++)
        {
            char tri2[3] = {abAB[i], abAB[j], 0};
            char* cr2 = crypt(tri2, salt);

            if (strcmp(cr2, hash) == 0)
            {
                printf("%s\n", tri2);
                return 0;
            }

            // this didn't work - do you know why???
            // int comp2 = strcmp(cr2, hash);
            // if (comp2 == 0)
            // {
            //     printf("%s", tri2);
            //     printf("test");
            //     return 0;
            // }

            for (int k = 0, p = strlen(abAB); k < p; k++)
            {
                char tri3[4] = {abAB[i],abAB[j],abAB[k], 0};
                char* cr3 = crypt(tri3, salt);

                if (strcmp(cr3, hash) == 0)
                {
                    printf("%s\n", tri3);
                    return 0;
                }

                for (int l = 0, q = strlen(abAB); l < q; l++)
                {
                    char tri4[5] = {abAB[i],abAB[j],abAB[k],abAB[l], 0};
                    // produce my own encrpyted key with salt
                    char* cr4 = crypt(tri4, salt);

                    // if own key is equal to key provided, print out the string tried.
                    if (strcmp(cr4, hash) == 0)
                    {
                        printf("%s\n", tri4);
                        return 0;
                    }
                }
            }
        }
    }

    printf("\n");
    return 1;
}