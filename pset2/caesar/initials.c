#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // printf("Please write your full name: ");
    string s = get_string();

    // has it processed the first letter? Set to false before first letter
    bool firstLetter = false;

    // make sure a string is returned
    if (s != NULL)
    {
        // iterate over the characters in s in succession
        for (int i = 0, n = strlen(s); i < n; i++)
        {
            // is it a letter, not a space?
            if (isalpha(s[i]))
            {
                if (firstLetter == false)
                {
                    // capitalise letters if lower case
                    firstLetter = true;
                    printf("%c", toupper(s[i]));
                }
            }
            // if symbolises end of word, so switch bool back to false
            if (s[i] == ' ')
            {
                firstLetter = false;
            }
        }
        // move cursor down a line
        printf("\n");
    }
}