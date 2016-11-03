/**
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
 */
 
#define _XOPEN_SOURCE

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// constant
#define LIMIT 65536

int main(int argc, string argv[])
{
    // TODO: if there is less then 1 or more then 2 arguments, it shows an error
    if (argc != 2 && argc != 3)
    {
        printf("Usage: generate n [s]\n");
        return 1;
    }

    // TODO: the int N gets the number of the rnd numbers
    int n = atoi(argv[1]);

    // TODO: if entered 2 args, then put in the parameter of the func "strand48" an arg from the second parameter
    if (argc == 3)
    {
        srand48((long int) atoi(argv[2]));
    }
    else //else put as a parameter the time
    {
        srand48((long int) time(NULL));
    }

    // TODO: printing the int rnd numbers of N times
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", (int) (drand48() * LIMIT));
    }

    // success
    return 0;
}
