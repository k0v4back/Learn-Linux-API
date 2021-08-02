/*
 * open file and read info from it
 */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_READ 10

int main(void)
{
    int fd;
    char buffer[MAX_READ + 1];
    ssize_t num_read;

    fd = open("test.txt", O_RDONLY);
    if(fd < 0){
        if(errno == EINVAL)
            perror("open");
        exit(1);
    }

    num_read = read(fd, buffer, MAX_READ);
    if(num_read < 0){
        if(errno == EBADF)
            perror("read");
        exit(2);
    }

    puts("----------RESULT----------");
    printf("%s \n", buffer);

    return 0;
}

