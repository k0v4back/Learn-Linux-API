/*
 * calloc() and malloc() differ only in that calloc() returns a pointer to initialized memory,
 * while malloc() returns a pointer to non-initialized memory
 */

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10

int main(void)
{
    int * numbers;

    numbers = (int *)calloc(COUNT, sizeof(int));
    if(!numbers)
    {
        fprintf(stderr, "Allocation error");
        exit(1);
    }

    return 0;
}

