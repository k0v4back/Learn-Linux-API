/*
 * Set interval for timer int ms
 * signal SIGALRM will call signal handler
 */

#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define INTERVAL_MS 1000

void sig_handler(int signal)
{
    printf("SIGINT signal = %d\n", signal);
}

int main(void)
{
    struct itimerval interval_val;

    if (signal(SIGALRM, sig_handler) == SIG_ERR) {
        perror("Unable to catch SIGALRM");
        exit(1);
    }

    interval_val.it_value.tv_sec = INTERVAL_MS/1000;
    interval_val.it_value.tv_usec = (INTERVAL_MS*1000) % 1000000;
    interval_val.it_interval = interval_val.it_value;

    if (setitimer(ITIMER_REAL, &interval_val, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }

    while (1) 
        pause();

    return 0;
}

