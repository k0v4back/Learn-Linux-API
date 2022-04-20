/*
 * The fork() system call creates a new process (child),
 * which is an almost complete copy of the calling process, the parent.
 */

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
    pid_t parent_pid = getpid();
    pid_t child_pid;

    int example = 100;

    switch(child_pid = fork()){
        case -1:
            perror("fork");
            break;
        case 0:
            example += 5;
            break;
        default:
            /* parent run this section */
            /* stop parent while child running */
            sleep(2);
            break;
    }

    /* run parent and childe process */
    printf("child_pid=%d; ppid=%d, example=%d\n", child_pid, parent_pid, example);

    return 0;
}
