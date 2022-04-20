#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = 0;
    int status;

    pid = fork();

    if(pid == 0){
        printf("I am the child\n");
        sleep(5);
        printf("I am the child after 5 seconds\n");
    }

    if(pid > 0){
        /* Running from parent process while child is sleaping, and wait end of child */
        printf("I am the parent, the child is %d\n", pid);
        pid = wait(&status);
        printf("End of process %d: ", pid);

        if(WIFEXITED(status)){
            printf("The process ended with exit(%d)\n", WEXITSTATUS(status));
        }

        if(WIFSIGNALED(status)){
            printf("The process ended with kill -%d\n", WTERMSIG(status));
        }
    }

    if (pid < 0) {
        perror("In fork():");
    }

    exit(0);

    return 0;
}
