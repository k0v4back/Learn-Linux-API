#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define COUNT 5

void do_some_work(char *str);

int i = 0;

int main(void)
{
    pid_t pid;
   
    printf("I am %d\n", getpid());

    pid = fork();
    srand((int) pid);

    switch(pid){
        case -1:
            perror("fork fail");
            break;
        case 0:
            printf("I am child %d\n", getpid());
            do_some_work("Child");
            exit(0);
        default:
            printf("I am parent, waiting for child end\n");
            do_some_work("Parent");
            wait(NULL);
            printf("Parent end\n");
    }

    return 0;
}

void do_some_work(char *str)
{
    for( ; i < COUNT; i++){
        sleep(rand() % 4);
        printf("Done pass %d for %s\n", i, str);
    }
}
