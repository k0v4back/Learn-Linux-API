#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t my_pid = getpid();
    printf("PID: %d\n", my_pid);
    
    sleep(5);
    kill(my_pid, SIGSEGV); 

    return 0;
}
