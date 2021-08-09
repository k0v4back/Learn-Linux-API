/*
 * times() returns information about the time of the process
 */

#include <stdio.h>
#include <sys/times.h>
#include <time.h>
#include <stdlib.h>

int main(void)
{
    struct tms * buf;
    clock_t tck; /* number of ticks */

    tck = times(buf);
    if(tck == -1)
    {
        fprintf(stderr, "times() ERROR!");
        exit(1);
    }
    
    puts("----------RESULT----------");
    printf("tms_utime=%lu\ntms_stime=%lu\ntms_cutime=%lu\ntms_cstime=%lu\n",
           buf->tms_utime, buf->tms_stime, buf->tms_cutime, buf->tms_cstime);

    return 0;
}
