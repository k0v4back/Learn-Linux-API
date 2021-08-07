/*
 * current user ID and current group ID
 */

#include <stdio.h>
#include <unistd.h>

int main(void)
{
    uid_t euid;
    gid_t egid;

    /* Returns the valid user ID of the calling process */
    euid = geteuid();

    /* Returns the valid group ID of the calling process */
    egid = getegid();

    printf("EUID:%u\nEGID:%u\n", euid, egid);
    
    return 0;
}

