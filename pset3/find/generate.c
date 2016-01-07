/***************************************************************************
 * generate.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Generates pseudorandom numbers in [0,LIMIT), one per line.
 *
 * Usage: generate n [s]
 *
 * where n is number of pseudorandom numbers to print
 * and s is an optional seed
 ***************************************************************************/
 
// standard libraries
#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // Verify that the command line has two or three values, 
    // this is, the numbers of numbers and the seed
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // Change the variable type of argv[1] this is the number of number wanted,
    // it's stored as a string, and is needed as an int
    int n = atoi(argv[1]);

    // If argc is equal to three means that the user has given a seed, 
    // so the program feeds it to the srand48 function that provides the seed 
    // to the dran48 function. If argc is 2 there's no seed, so time(NULL) 
    // provides a diferent seed every time
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else
    {
        srand48((long int) time(NULL));
    }

    // the drand48 function creates the random numbers, this needs to be 
    // done as many times as numbers are needed, drand48 output is a number 
    // from 0 to 1 so it's multiplied by the LIMIT
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
