#include <stdio.h>
#include <errno.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signal)
{
    /* Better not to use I/O operations in handler */
    printf("SIGINT signal = %d\n", signal);
}

int main(void)
{
    printf("PID: %d\n", getpid());

    if(signal(SIGINT, sig_handler) == SIG_ERR)
        perror("signal");
    if(signal(SIGQUIT, sig_handler) == SIG_ERR)
        perror("signal");

    printf("Waiting for signal\n");
    while(1){
        sleep(1);
    }
}
