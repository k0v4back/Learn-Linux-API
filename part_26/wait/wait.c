/*
 * wait() waits for one of the child of the calling process to stop working
 * and returns the termination code of this child process through the buffer
 * pointed to by the status argument
 *
 * pid_t wait(int *status);
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <errno.h>

#define COUNT 3

int main(void)
{
    pid_t child_pid = 0;
    int num_dead;

    setbuf(stdout, NULL); /* turn off standart output buffer */

    for(int i = 0; i < COUNT; i++){
       switch(fork()){
           case -1:
               perror("fork");
               exit(1);
           case 0:
               /* child proc stop some time and after termination */
               printf("child %d started witch PID %d\n", i, (int)getpid());
               sleep(i + 2);
               _exit(EXIT_SUCCESS);
           default:
               /* Parent working */
               break;
       }
    }

    num_dead = 0;
    while(1){
        child_pid = wait(NULL);
        if(child_pid == -1){ /* error of wait() */
            if(errno == ECHILD){ /* 0 child of current proc */
                printf("No more childern\n");
                exit(EXIT_SUCCESS);
            }else{
                exit(EXIT_FAILURE); /* Some else error */
            }
        }

        num_dead++;
        printf("wait() returned child PID %d\n", child_pid);
    }


    return 0;
}
