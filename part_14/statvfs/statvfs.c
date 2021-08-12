/*
 * Get information about file system
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/statvfs.h>

int main(void)
{
    struct statvfs buf;

    if(statvfs(".", &buf) == -1)
    {
        fprintf(stderr, "statvfs() ERROR");
        exit(EXIT_FAILURE);
    }

    printf("f_bsize:%lu \n", buf.f_bsize);
    printf("f_frsize:%lu \n", buf.f_frsize);
    printf("f_fsid:%lu \n", buf.f_fsid);
    printf("f_flag:%lu \n", buf.f_flag);
    printf("f_namemax:%lu \n", buf.f_namemax);

    return 0;
}


