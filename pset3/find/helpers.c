/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 * by TARA ELSEN
 *
 * Search finds value in values. return true if found, otherwise return false.
 * Use linear sort to order lowest to highest values.
 */

#include <cs50.h>

#include "helpers.h"

#define MAX 65536

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first, last, mid;

    if (n < 0) {
        return false;
    }

    first = 0;
    last = n - 1;
    mid = (first+last)/2;

    // while (int i = 0; i < n; i++) {
    while (first <= last)
    {
        if (values[mid] < value)
            first = mid + 1;

        else if (values[mid] == value)
            return true;

        else
            (last = mid - 1);

        mid = (first + last)/2;
    }

    return false;
}

/**
 * Sorts array of n values.
 */

void sort(int values[], int n)
{
    // create empty array
    int ind[MAX] = {0};
    // Sorted array of values is new_values
    int new_values[n];
    // j is counter of new_values
    int j = 0;

    for(int i = 0; i < MAX; i++)
    {
        if (i == values[i])
        {
            ind[i]++;
        }

        if (ind[i] != 0)
        {
            for (int k = 0; k < MAX; k++)
            {
                new_values[j]=i;
                j++;
            }
        }
    }
    // return;
}