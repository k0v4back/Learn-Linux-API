/*
 * Checking the file access mode with fcntl()
 * http://www.ccfit.nsu.ru/~deviv/courses/unix/unix/ng241bc.html
 */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(void)
{
    int flags, access_mode;
    int fd;

    fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC,
            S_IWUSR | S_IRUSR | S_IWGRP | S_IRGRP | S_IROTH);
    
    flags = fcntl(fd, F_GETFL);
    if (flags <= 0){
        fprintf(stderr, "fcntl error");
        exit(1);
    }

    access_mode = flags & O_ACCMODE;
    if (access_mode == O_WRONLY || access_mode == O_RDWR)
        printf("file is writable\n");
    else
        printf("file isn't writable\n");

    return 0;
}
