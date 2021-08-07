#include <bits/types/struct_timeval.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main(void)
{
    struct timeval * tv;
    struct timezone * tz;

    if(gettimeofday(tv, tz) == -1)
    {
        fprintf(stderr, "gettimeofday ERROR");
        exit(1);
    }

    printf("tv_sec=%ld\ntv_usec=%ld\n", tv->tv_sec, tv->tv_usec);

    return 0;
}

