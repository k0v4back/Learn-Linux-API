/*
 * Use malloc() and free()
 */

#include <stdio.h>
#include <stdlib.h>

#define NUM 10

int main(void)
{
    int * numbers;
   
    /* alloc memory for array */
    numbers = (int *)malloc(sizeof(int) * NUM);
    
    /* insert data to array */
    for(unsigned i = 0; i < NUM; i++)
        numbers[i] = i + 1;

    /* print data from array */
    for(unsigned i = 0; i < NUM; i++)
        printf("#%d -> %d \n", i, numbers[i]);

    /* free memory from heap */
    free(numbers);

    return 0;
}
    
