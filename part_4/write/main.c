#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define STRING_WRITE "Hello World"

int main(void)
{
    unsigned max_read = strlen(STRING_WRITE);
    int fd;
    char buffer[max_read + 1];
    ssize_t write_bytes;
    ssize_t read_bytes;

    /* create file */
    fd = creat("test.txt", S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
    if(fd < 0){
        if(errno == EINVAL)
            perror("creat");
        exit(1);
    }

    /* write text info in file */
    write_bytes = write(fd, STRING_WRITE, max_read);
    close(fd);    
   
    /* read text info from file */
    fd = open("test.txt", O_RDONLY);
    read_bytes = read(fd, buffer, max_read);
    if(read_bytes < 0){
        if(errno == EBADF)
            perror("read");
        exit(2);
    }

    puts("----------RESULT----------");
    printf("%s \n", buffer);

    return 0;
}
