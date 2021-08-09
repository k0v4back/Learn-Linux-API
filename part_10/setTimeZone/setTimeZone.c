/*
 * Specifying the time zone for the program
 */

#include <time.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

#define BUF_SIZE 200

int main(int argc, char ** argv)
{
    time_t t;
    struct tm *loc;
    char buf[BUF_SIZE];

    if(setlocale(LC_ALL, "") == NULL)
    {
        fprintf(stderr, "setlocale ERROR!");
        exit(1);
    }

    t = time(NULL);
    
    printf("ctime() of time() value is: %s", ctime(&t));
    loc = localtime(&t);
    if(loc == NULL)
    {
        fprintf(stderr, "localtime ERROR!");
        exit(1);
    }
    
    printf("asctime() of local time is: %s", asctime(loc));
    if(strftime(buf, BUF_SIZE, "%A, %d %B %Y, %H:%M:%S %Z", loc) == 0)
    {
        fprintf(stderr, "strftime ERROR!");
        exit(1);
    }
    printf("strftime() of local time is: %s\n", buf);

    return 0;
}
        
