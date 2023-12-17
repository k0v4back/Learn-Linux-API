#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include <pthread.h>

#define MAXITEMS 1000000
#define MAXTHREADS 100
#define min(a, b) ((a) < (b)) ? (a) : (b)
#define max(a, b) ((a) > (b)) ? (a) : (b)

static int n_items, thread;

struct {
    pthread_mutex_t mutex;
    int buff[MAXITEMS];
    int n_put;
    int n_val;
} shared = {
    PTHREAD_MUTEX_INITIALIZER
};

void* creater(void* arg) {
    sleep(rand() % 10);

    for ( ; ; ) {
        pthread_mutex_lock(&shared.mutex);

        if (shared.n_put >= n_items) {
            pthread_mutex_unlock(&shared.mutex);
            return NULL; /* Array full */
        }

        shared.buff[shared.n_put] = shared.n_val;
        printf("creater #%lu make element %d with value %d\n", pthread_self(),
                shared.n_put, shared.n_val);
        shared.n_put++;
        shared.n_val++;

        pthread_mutex_unlock(&shared.mutex);
        *((int*) arg) += 1;
        sleep(rand() % 1);
    }
}

void consumer_wait(int i) {
    for ( ; ; ) {
        pthread_mutex_lock(&shared.mutex);
        if (i < shared.n_put) {
            printf("Element %d ready for consumer!\n", i);
            pthread_mutex_unlock(&shared.mutex);
            return; /* Element ready */
        }
        printf("Waiting %d element\n", i);
        pthread_mutex_unlock(&shared.mutex);
    }
}

void* cunsumer(void* arg) {
    int i;

    for (i = 0; i < n_items; i++) {
        consumer_wait(i);
        if (shared.buff[i] != i)
            printf("buff[%d] = %d\n", i, shared.buff[i]);
    }

    return NULL;
}

int main(int argc, char* argv[]) {
    int i, n_threads, count[MAXTHREADS];
    pthread_t tid_creater[MAXTHREADS], tid_consumer;

    if (argc != 3) {
        printf("usage: prodcons1 <#items> <#threads>");
        exit(-1);
    }

    n_items = min(atoi(argv[1]), MAXITEMS);
    n_threads = min(atoi(argv[2]), MAXTHREADS);

    /* Create creater for filling array and consumer for reading array */
    for (i = 0; i < n_threads; i++) {
        count[i] = 0;
        pthread_create(&tid_creater[i], NULL, creater, &count[i]);
        thread++;
    }
    pthread_create(&tid_consumer, NULL, cunsumer, NULL);

    /* Wait creater and consumer for end of working */
    for (i = 0; i < n_threads; i++) {
        pthread_join(tid_creater[i], NULL);
        printf("Creater #%lu makes %d elements\n", tid_creater[i], count[i]);
    }
    pthread_join(tid_consumer, NULL);
    
    return 0;
}