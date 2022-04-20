/*
 * Child changes the offset of the open file and
 * the flags of its state, after which it shuts down.
 * The parent then extracts the offset and flags of the file
 * to make sure that it can see the changes made by its child.
 */

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
    int fd, flags;
    pid_t child_pid;

    setbuf(stdout, NULL); /* turn off standart output buffer */
    
    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 
            S_IRWXU | S_IRGRP | S_IWGRP | S_IROTH);
    if(fd < 0){
        if(errno == EINVAL)
            perror("Invalid value in flags");
        exit(1);        
    }

    printf("File offset before fork(): %lld\n", 
            (long long)lseek(fd, 0, SEEK_CUR));
    flags = fcntl(fd, F_GETFL);
    if (flags <= 0){
        fprintf(stderr, "fcntl error");
        exit(1);
    }

    switch(child_pid = fork()){
        case -1:
            perror("fork");
            exit(1);
        case 0:
            /* Child change lseek and flags */
            if(lseek(fd, 1000, SEEK_SET) == -1){
                perror("lseek");
                exit(1);
            }

            /* Current flags */
            flags = fcntl(fd, F_GETFL);
            if(flags < 0){
                perror("fcntl");
                exit(1);
            }

            /* check O_APPEND flag befor update*/
            if(flags & O_APPEND)
                puts("O_APPEND is in the flags");
            else
                puts("O_APPEND is not in the flags");

            flags |= O_APPEND;
            if((fcntl(fd, F_SETFL, flags) < 0)){
                perror("Set new flags error");
                exit(1);
            }

            break;
        default:
            /* Parent can see changes from child process */
            if(wait(NULL) == -1){
                perror("wait()");
                exit(1);
            }

            printf("Child has exited\n");
            printf("File offset in parent: %lld\n",
                    (long long) lseek(fd, 0, SEEK_CUR));
            
            /* Current flags */
            flags = fcntl(fd, F_GETFL);
            if(flags < 0){
                perror("fcntl");
                exit(1);
            }

            printf("O_APPEND flag in parent is: %s\n", 
                    (flags & O_APPEND) ? "on" : "off");
            break;
    }

    return 0;
}
