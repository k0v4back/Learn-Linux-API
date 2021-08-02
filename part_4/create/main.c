/*
 * creat() create and open new file with specified path.
 * If file alredy exist, open and truncates it to zero length
 */

#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(void)
{
    int fd;

    fd = creat("test.txt", S_IRUSR | S_IWUSR | S_IRGRP);
    if(fd < 0){
        if(errno == ENAMETOOLONG)
            perror("pathname was too long");
        exit(1);
    }

    return 0;
}
