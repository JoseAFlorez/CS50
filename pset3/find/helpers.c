/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // binary search
    int min = 0;
    int max = n - 1;
    int midpoint = (min + max)/2;
    bool result;
    
    while (min <= max)
    {
        if (values[midpoint] < value)
            min = midpoint + 1;
        else if (values[midpoint] > value)
            max = midpoint -1;
        else if (values[midpoint] == value)
        {
            result = true;        
            break;
        }
        midpoint = (min + max)/2;
    }
    if (min > max)
        result = false;
    return result;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // bubble sort
    int swap;
    for (int j = 0; j < (n - 1) ; j++)
    {
        for (int k = 0; k <  n - j - 1 ; k++)
        {
            if (values[k] > values[k+1])
                {
                swap        = values[k];
                values[k]   = values[k+1];
                values[k+1] = swap;
                }    
        }
    }
    return;
}
