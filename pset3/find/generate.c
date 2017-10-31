/**
 * generate.c
 *
 * Generates pseudorandom numbers in [0,MAX), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 */

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// upper limit on range of integers that can be generated
#define LIMIT 65536
#define _XOPEN_SOURCE

int main(int argc, string argv[])
{
    // check correct number of arguments, must be 2 or 3
    if (argc != 2 && argc != 3)
    {
        printf("Usage: ./generate n [s]\n");
        return 1;
    }

    // store middle argument as integer to retrieve for the for statement size
    int n = atoi(argv[1]);

    // if 3rd arg provided, choose long random num generator with seed value of 3rd arg
    if (argc == 3)
    {
        srand48((long) atoi(argv[2]));
    }
    // else there are two, so use long random num generator without an assigned seed
    else
    {
        srand48((long) time(NULL));
    }

    // make the list of 'random' double integer numbers of length of second argument, range [0, 1)
    // use another random number generator for each value, and multiply by largest range
    // of int that can be generated.
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
