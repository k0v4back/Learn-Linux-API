/*
 * Passing the environment of the calling process new environment var
 */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    printf("Current USER: %s\n", getenv("USER"));
    if(putenv("USER=k0v4_v2") != 0){
        perror("putenv");
        exit(EXIT_FAILURE);
    }

    execl("/usr/bin/printenv", "printenv", "USER", "SHELL", (char *)NULL);
    
    /* Some problem */
    perror("execl");

    return 0;
}
