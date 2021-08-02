#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/uio.h>
#include <unistd.h>

#define FILE_NAME "test.txt"

int main(void)
{
    struct iovec iov[3];
    ssize_t nr;
    int fd;

    char * buf[] = {
        "It is some intresting programm using linux API \n",
        "I do not know what to write \n",
        "Hello world \n"
    };

    fd = open (FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC);
    if(fd < 0){
        fprintf(stderr, "Couldn't open %s\n", FILE_NAME);
        exit(1);
    }

    /*fill in 3 structures iovec */
    for(int i = 0; i < 3; i++){
        iov[i].iov_base = buf[i];
        iov[i].iov_len = strlen(buf[i]) + 1;
    }
    printf("wrote %ld bytes\n", nr);
    
    if(close(fd)){
        perror ("close");
        exit(1);
    }

    return 0;
}

