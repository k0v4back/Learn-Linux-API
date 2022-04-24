#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(void)
{
    int pid, status;

    printf("Parent PID: %d\n", getpid());

    switch(pid = fork()){
       case -1:
           perror("fork");
           exit(1);
       case 0:
           /* child proc stop some time and after termination */
           printf("Child %d\n", getpid());
           sleep(2);
           _exit(EXIT_SUCCESS);
       default:
           /* Parent working */
           break;
    }

    waitpid(pid, &status, 0);
    if (WIFSIGNALED(status)){
        printf("Error\n");
    }else if (WEXITSTATUS(status)){
        printf("Exited Normally\n");
    }
    //To Here and see the difference
    printf("Parent PID: %d\n", getpid());


    return 0;
}
