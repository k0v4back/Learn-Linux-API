/*
 * An exit handler is a function provided by the programmer that is
 * registered at some stage of the process lifecycle and then automatically
 * generated during its normal completion by the exit() function.
 *
 * Handlers outputs are ignored if the program directly 
 * calls _exit() or if the process crashes with a signal.
 *
 * If you are using atexit() you don't know param of exit(param);
 * And you cann`t give param for error handler
 */

#include <stdio.h>
#include <stdlib.h>

static void atexit_one(void)
{
    printf("Called atexit_one()\n");
}

int main(void)
{
    if(atexit(atexit_one) != 0){
        printf("atexit() registration failed\n");
        exit(EXIT_FAILURE);
    }

    exit(2);
}
