/*
 * realloc () is used to resize (usually increase) a block memory
 * previously allocated by one of the functions from the malloc package.
 */

#include <stdio.h>
#include <stdlib.h>

#define COUNT 10
#define INCREASE 5

void fill_array(int * array, unsigned start_num, unsigned end_num);
void print_array(int * array, unsigned start_num, unsigned end_num);
void error_handler(int * ptr, char * message);

int main(void)
{
    int * numbers;

    /* allocated memory for array */
    numbers = (int *)malloc(COUNT * sizeof(int));
    error_handler(numbers, "Allocation memory ERROR");
    fill_array(numbers, 0, COUNT);

    /* add some memory for array */
    numbers = (int *)realloc(numbers, sizeof(int) * INCREASE);
    error_handler(numbers, "Allocation memory ERROR");
    fill_array(numbers, COUNT, COUNT + INCREASE);

    /* print resul array */
    print_array(numbers, 0, COUNT + INCREASE);

    return 0;
}

void fill_array(int * array, unsigned start_num, unsigned end_num)
{
    for(unsigned i = start_num; i < end_num; i++)
        array[i] = i+1;
}

void print_array(int * array, unsigned start_num, unsigned end_num)
{
    for(unsigned i = start_num; i < end_num; i++)
        printf("#%d -> %d \n", i, array[i]);
}

void error_handler(int * ptr, char * message)
{
    if(!ptr)
    {
        fprintf(stderr, "%s", message);
        exit(1);
    }
}
