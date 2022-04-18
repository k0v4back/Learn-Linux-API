#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
    pid_t my_pid = getpid();
    char *pid_info = strsignal(my_pid);

    printf("PID: %d\n", my_pid);
    printf("IFNO: %s\n", pid_info); 

    return 0;
}
