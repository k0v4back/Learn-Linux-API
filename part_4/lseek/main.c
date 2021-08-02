#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include <errno.h>
#include <unistd.h>

int main(void)
{
    int fd;
    int ret;
    char * str = "HELLO";
    char buf[4];

    fd = open("test.txt", O_CREAT | O_APPEND | O_RDWR, 0664);
    if(fd == -1)
    {
        perror("Failed to create file");
        exit(1);
    }

    ret = write(fd, str, strlen(str));
    if(ret == -1)
    {
       perror("Failed to write data");
       exit(1);
    }

    //Using lseek();
    ret = lseek(fd, 2 * sizeof(char), SEEK_SET);

    //Read from file after using lseek()
    ret = read(fd, buf, 3);
    if(ret == -1)
    {
        perror("Failed to read from file after lseek()");
        exit(1);
    }

    close(fd);

    printf("%s \n", buf);

    return 0;
}
