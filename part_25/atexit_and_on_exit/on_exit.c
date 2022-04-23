/*
 * By using on_exit(int status, void *arg) you can give exit status and agrument
 */

#include <stdio.h>
#include <stdlib.h>

static void exit_func(int exit_status, void *arg)
{
    printf("Exit status:%d\nArg:%d\n", exit_status, (int)arg);
}

int main(void)
{
    if(on_exit(exit_func, (void *)10)){
        printf("Failed to register on_exit()\n");
        exit(EXIT_FAILURE);
    }

    exit(2);
}
