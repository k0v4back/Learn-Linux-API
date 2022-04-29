#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define CMD_LEN 100

int my_system(char *command);

int main(void)
{
    char str[CMD_LEN];
    int status;

    for(;;){
        printf("Command: ");
        fflush(stdout);
        if(fgets(str, CMD_LEN, stdin) == NULL)
            break;

        status = my_system(str);
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

int my_system(char *command)
{
    int status;
    pid_t child_pid;

    switch(child_pid = fork()){
        case -1:
            return -1;
        case 0:
            execl("/bin/sh", "sh", "-c", command, (char *) NULL);
        default:
            if(waitpid(child_pid, &status, 0) == -1)
                return -1;
            else
                return status;
    }
}
