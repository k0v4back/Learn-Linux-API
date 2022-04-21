/*
 * Early version of fork() doesn't use COW
 * vfork() was more lightweight than fork()
 * But now fork() use COW and vfork() doesn't make much sense
 *
 * Child uses the memory of the parent, any changes it makes
 * to the data segments, heap or stack will be available to the
 * parent process itself as soon as it resumes work.
 *
 * Child gets access to the parent's memory, and the parent suspends
 * work until the child completes execution or calls the exec() function.
 */

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    pid_t child_pid;

    int example = 100;

    switch(child_pid = vfork()){
        case -1:
            perror("vfork");
            break;
        case 0:
            /* Child run inside parent memry area */
            sleep(3);
            printf("Child executing\n");
            example += 5;
            break;
        default:
            /* parent run this section */
            /* stop parent while child running */
            printf("Parent executing\n");
            printf("example=%d\n", example);
            break;
    }

    return 0;
}

