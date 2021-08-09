/*
 * The only difference between pathconf() and fpathconf() is how you specify a file or directory
 * For pathconf(), as a pathname in the pathname argument, and for fpathconf() - via
 * a descriptor of a previously opened file.
 */

#include <unistd.h>
#include <stdio.h>
#include <errno.h>

void fpathconf_print(const char * msg, int fd, int name);

int main(void)
{
    fpathconf_print("_SC_ARG_MAX:", STDIN_FILENO, _PC_NAME_MAX);
    puts("");

    return 0;
}

void fpathconf_print(const char * msg, int fd, int name)
{
    long lim;
    errno = 0;

    lim = fpathconf(fd, name);
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
       
