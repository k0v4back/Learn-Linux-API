/*
 * scan entries into a password file.
 */

#include <stdio.h>
#include <pwd.h>

int main(void)
{
    struct passwd * pwd;

    while((pwd = getpwent()) != NULL)
        printf("pw_name:%s \n pw_uid:%u \n", pwd->pw_name, pwd->pw_uid);

    endpwent();

    return 0;
}
