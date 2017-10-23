#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    int i;

    do
    {
        printf("C: ");
        i = get_int();
        float f = round(((i*9)/5)+32);
        printf("F: %.1f\n", f);
    }
    while (i > -274);

    printf("That's too low to calculate!\n");

    return 0;
}