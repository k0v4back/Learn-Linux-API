#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>

#define PATHNAME "test.txt"

int main(void)
{
    struct stat buf;

    if(stat(PATHNAME, &buf) == -1)
    {
        fprintf(stderr, "stat() ERROR");
        exit(EXIT_FAILURE);
    }

    printf("st_dev:%lu\n", buf.st_dev);
    printf("st_ino:%lu\n", buf.st_ino);
    printf("st_mode:%u\n", buf.st_mode);
    printf("st_nlink:%lu\n", buf.st_nlink);
    printf("st_uid:%u\n", buf.st_uid);
    printf("st_gid:%u\n", buf.st_gid);
    printf("st_rdev:%lu\n", buf.st_rdev);

    return 0;
}
