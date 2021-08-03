/*
 * Determine the ID of its parent process the calling process
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t parent_pid;

    parent_pid = getppid();
    printf("Process ID = %d \n", (int)parent_pid);
    
    return 0;
}
