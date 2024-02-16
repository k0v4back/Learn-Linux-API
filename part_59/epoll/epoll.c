#include <stdio.h>
#include <sys/epoll.h>
#include <unistd.h>

int main(void)
{
    struct epoll_event event;
    int epoll_fd = epoll_create1(0); /* stdin event */
    if (epoll_fd == -1)
        return 1;
    
    /* Subscribe to data entry events */
    event.events = EPOLLIN;
    event.data.fd = 0;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, 0, &event)) {
        printf("Failed epoll_ctl()\n");
        return 1;
    }



    if (close(epoll_fd)) {
        printf("Failed close()\n");
        return 1;
    }

    /* Count of epoll() events */
    int event_count = epoll_wait(epoll_fd, &event, 1, 5000);
    if (!event_count) {
        printf("Timeout\n");
    } else {
        printf("Timeout\n");
        return 1;
    }

    return 0;
}