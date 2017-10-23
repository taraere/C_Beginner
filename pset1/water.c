#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("Whole minutes in shower: ");
    int i = get_int();
    printf("You used %i (little) bottles of water while showering!\n", i * 12);
}