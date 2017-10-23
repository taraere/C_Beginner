#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int inp;

    do
    {
    printf("Choose a height lower than 24: ");
    inp = get_int();
    }
    while (inp < 0 || inp > 24);

    for (int i = 0; i < inp; i ++)
    {
        for(int k = inp-i-1; k != 0; k --)
        {
            printf(" ");
        }
        for(int j = 0; j <= i; j ++)
        {
            printf("#");
        }
        printf("  ");
        for(int j = 0; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}


//first row, 1 #, 7 space
//2#, 6 spaces
//3#, 5 spaces

// for (initialization; condition; update) {}