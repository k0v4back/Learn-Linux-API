#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

void* thread_func(void* arg) {
    int i;
    int data = *(int*)arg;

    for (i = 0; i < 5; i++) {
        printf("pthread %i is running\n", data);
        sleep(1);
    }

    pthread_exit(NULL);
}

int main(int argc, char* argv[]) {
    int id;
    int N = 5;
    pthread_t thread1, thread2, thread3;
    pthread_t threads[N];
    int result;

    /* Create threads */
    for (id = 0; id < N; id++) {
        result = pthread_create(&threads[id], NULL, thread_func, &id);
        if (result != 0) {
            perror("Creating the first thread");
            return EXIT_FAILURE;
        }
    }
    
    /* Wait threads */
    for (id = 0; id < N; id++) {
        result = pthread_join(threads[id], NULL);
        if (result != 0) {
            perror("Join the first thread");
            return EXIT_FAILURE;
        }
    }

    return 0;
}