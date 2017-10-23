#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("O hai! How much change is owed? ");
    float f = get_float();
    // round
    int i = round(f * 100);

    int leftover_quarters = i % 25;
    int leftover_dimes = leftover_quarters % 10;
    int leftover_nickels = leftover_dimes % 5;

    int quarters = i / 25;
    int dimes = (leftover_quarters) / 10;
    int nickels = (leftover_dimes) / 5;
    int cents = leftover_nickels;

    printf("I owe you %i coins!\n", quarters + dimes + nickels + cents);
}