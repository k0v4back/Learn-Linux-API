/*
 * Checking for Process Existence
 */

#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <errno.h>

#define PID_OF_PROC 10

int main(void)
{
    kill(PID_OF_PROC, 0);
    
    if(errno == ESRCH)
       printf("Proccess of pid=%d doesn't exist\n", PID_OF_PROC); 
    printf("Proccess of pid=%d exist errno = %d\n", PID_OF_PROC); 
    
    return 0;
}
