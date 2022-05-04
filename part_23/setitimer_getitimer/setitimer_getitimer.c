#include <sys/time.h>
#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define INTERVAL_MS 2000

void sig_handler(int signal)
{
    printf("SIGINT signal = %d\n", signal);
}

static void display_times()
{
    struct itimerval itv;

    if(getitimer(ITIMER_REAL, &itv) == -1){
        perror("error calling getitimer()");
        exit(1);
    }

    printf("%6.2f %6.2f \n",
            itv.it_value.tv_sec + itv.it_value.tv_usec / 1000000.0,
            itv.it_interval.tv_sec + itv.it_interval.tv_usec / 1000000.0
    );
}

int main(void)
{
    struct itimerval itv;

    if (signal(SIGALRM, sig_handler) == SIG_ERR) {
        perror("Unable to catch SIGALRM");
        exit(1);
    }

    itv.it_value.tv_sec = INTERVAL_MS/1000; 
    itv.it_value.tv_usec = (INTERVAL_MS*1000) % 1000000;
    itv.it_interval = itv.it_value;

    if (setitimer(ITIMER_REAL, &itv, NULL) == -1) {
        perror("error calling setitimer()");
        exit(1);
    }

    for(;;){
        display_times();
        sleep(1);
    }

    return 0;
}
