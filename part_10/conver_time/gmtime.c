/*
 * converts the calendar time to the divided time corresponding to UTC
 */

#include <stdio.h>
#include <time.h>

int main(void)
{
    struct tm *gtime;
    time_t now;

    /* Get current system time */
    time(&now);

    /* Convert the system time to UTC */
    gtime = gmtime(&now);

    printf("UTC0: %2d:%02d \n", gtime->tm_hour, gtime->tm_min);

    return 0;
}
