/*
caesar fun by Tara Elsen

main takes two arguments, e.g: ./caesar key
where the key is an integer.

Prompts for plaintext to encypher with they key
by moving it by so many characters to the right.

*/
#include <cs50.h> // used for get_string
#include <stdio.h> // used for printf
#include <string.h> // used for strlen
#include <ctype.h> // used for isalpha
#include <stdlib.h> // for atoi

// argc = number of strings in argv, and must be two
// (argc means must have no more than two arguments passed in)
// string argv = array of strings

int main(int argc, string argv[])
{
    // accept only two arguments from command line
    if (argc != 2)
    {
        printf("Oops you made an error. Please provide two arguments.");
        return 1;
    }

    // turn key into integer
    int k = atoi(argv[1]);

    // prompt user for string in plaintext
    printf("plaintext: ");
    string p = get_string();

    // now for the good stuff.
    printf("ciphertext: ");
    // for-loop to get index. If letter, perform calculation
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if (isalpha(p[i]))
        {
            if (isupper(p[i]))
            {
                printf("%c", (((p[i] - 65 + k) % 26) + 65));
            }
            if (islower(p[i]))
            {
                /* 'a' begins at 97 so minus, apply modulo and key
                 and*/
                printf("%c", (((p[i] - 97 + k) % 26) + 97));
            }
        }
        else
        {
            // leave other characters as they were
            printf("%c", p[i]);
        }
    }
    printf("\n");
    return 0;
}