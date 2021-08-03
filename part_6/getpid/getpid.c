/*
 * get process identification
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid;

    pid = getpid();
    printf("Process ID = %d \n", (int)pid);
    
    return 0;
}
