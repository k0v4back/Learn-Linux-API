/*
 * uname() return base information about system
 */

#include <stdio.h>
#include <sys/utsname.h>
#include <stdlib.h>

int main(void)
{
    struct utsname uts;

    if(uname(&uts) == -1)
    {
        fprintf(stderr, "uname() ERROR \n");
        exit(EXIT_FAILURE);
    }

    printf("Node name: %s\n", uts.nodename);
    printf("System name: %s\n", uts.sysname);
    printf("Release: %s\n", uts.release);
    printf("Version: %s\n", uts.version);
    printf("Machine: %s\n", uts.machine);

    return 0;
}
