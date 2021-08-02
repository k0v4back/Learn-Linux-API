/*
 * pread() and pwrie() they work almost the same as read() except that file I / O is performed
 * from the location specified by the offset value, and not from the current file offset.
 * These calls do not change the file offset.
 */

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define FILE_NAME "test.txt"
#define STR_BUF "Hello"
#define STR_LEN(x) strlen(x)
#define OFFSET 10

int main(void)
{
    int fd;
    ssize_t write_bytes;
    ssize_t read_bytes;
    char buffer[STR_LEN(STR_BUF) + OFFSET + 1];

    fd = creat(FILE_NAME, S_IRUSR | S_IWUSR | S_IRGRP);
    if(fd < 0){
        fprintf(stderr, "Couldn't creat file %s\n", FILE_NAME);
        exit(1);
    }
    
    write_bytes = pwrite(fd, STR_BUF, STR_LEN(STR_BUF), OFFSET);
    close(fd);

    /* read data from file */
    fd = open(FILE_NAME, O_RDONLY);
    if(fd < 0){
        fprintf(stderr, "Couldn't open file %s\n", FILE_NAME);
        exit(1);
    }

    read_bytes = pread(fd, buffer, STR_LEN(STR_BUF) + OFFSET, 10);
    if(read_bytes < 0){
        fprintf(stderr, "Couldn't pread file %s\n", FILE_NAME);
        exit(1);
    }

    printf("RESULT: %s \n", buffer);

    return 0;
}
