/*
 * getpwnam() return info about user by his name
 */

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <pwd.h>

int main(void)
{
    char user_name[10];
    struct passwd * user_passwd;

    puts("Enter user name");
    scanf("%s", user_name);

    user_passwd = getpwnam(user_name);
    if(!user_passwd)
    {
        fprintf(stderr, "User name dosen't exit \n");
        exit(1);
    }

    puts("------------INFO ABOUT USER----------------");
    printf("pw_name: %s \n", user_passwd->pw_name);
    printf("pw_passwd: %s \n", user_passwd->pw_passwd);
    printf("pw_uid: %d \n", user_passwd->pw_uid);
    printf("pw_gid: %d \n", user_passwd->pw_gid);

    return 0;
}
