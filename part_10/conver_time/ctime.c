/*
 * print current time to the output stream
 */

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
    time_t current_time;
    char * c_time_string;

    /* get time */
    current_time = time(NULL);
    if(current_time == ((time_t)-1))
    {
        fprintf(stderr, "Failure to get time");
        exit(EXIT_FAILURE);
    }
    /* Convert to local time format. */
    c_time_string = ctime(&current_time);
    if(c_time_string == NULL)
    {
        fprintf(stderr, "Failure to convert the current time.\n");
        exit(EXIT_FAILURE);
    }

    printf("Current time is %s", c_time_string);

    return 0;
}
