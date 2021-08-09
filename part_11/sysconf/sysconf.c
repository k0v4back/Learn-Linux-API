/*
 * Get system limit values during the execution of the program.
 */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void sysconf_print(const char * msg, int name);

int main(void)
{
    sysconf_print("_SC_ARG_MAX:", _SC_ARG_MAX);
    puts("");

    return 0;
}

void sysconf_print(const char * msg, int name)
{
    long lim;
    errno = 0;

    lim = sysconf(name);
    if(lim != -1)
    {
        printf("%s -> %ld", msg, lim);
    }
    else
    {
        if(errno == 0)
            printf("%s (indeterminate)\n", msg);
        else
            perror("sysconf");
    }
}
       
