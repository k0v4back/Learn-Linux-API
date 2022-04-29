/*
 * system() create a child process that executes the shell command
 */

#include <stdio.h>
#include <stdlib.h>

#define CMD_LEN 100

int main(void)
{
    char str[CMD_LEN];
    int status;

    for(;;){
        printf("Command: ");
        fflush(stdout);
        if(fgets(str, CMD_LEN, stdin) == NULL)
            break;

        status = system(str);
        printf("system() returned: status=0x%04x (%d%d)\n",
                (unsigned int)status, status >> 8, status & 0xff);

        if(status == 1){
            perror("system");
            exit(EXIT_FAILURE);
        }else{
            if(WIFEXITED(status) && WEXITSTATUS(status) == 127){
                printf("(Probably) could not invoke shell\n");
            }
        }
    }

    exit(EXIT_FAILURE);

    return 0;
}


