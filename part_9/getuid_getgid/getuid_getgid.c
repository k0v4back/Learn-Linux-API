/*
 * real user ID and real group ID
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    uid_t uid;
    gid_t gid;

    /* get the real user ID of the calling process */
    uid = getuid();

    /* the real group ID of the calling process */
    gid = getgid();

    printf("UID:%u\nGID:%u\n", uid, gid);
    
    return 0;
}

