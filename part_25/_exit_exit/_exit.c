/*
 * exit() function is a library function that uses _exit()
 * but calling handler (atexit() and on_exit()),
 * flush stdio buffer
 */

#include <unistd.h>
#include <stdio.h>

int main(void)
{
    printf("This message will not be printed in output\n");

    _exit(0);

    return 0;
}
