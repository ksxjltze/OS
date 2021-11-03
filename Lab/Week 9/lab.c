#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void *thread(void *arg)
{
    char *str = (char *)arg;
    printf("IN %s\n", str);
    // wait
    sem_wait(&mutex);
    printf("\n%s entered critical section\n", str);
    // critical section
    printf("\n%s working on the critical section\n", str);
    sleep(4);

    // signal
    printf("\n%s exiting critical section\n", str);
    sem_post(&mutex);

    return NULL;
}

int main()
{
    // initialize mutex to value 1
    sem_init(&mutex, 0, 1);
    pthread_t t1, t2;
    pthread_create(&t1, NULL, thread, (void *)"Thread 1");
    pthread_create(&t2, NULL, thread, (void *)"Thread 2");
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    sem_destroy(&mutex);
    return 0;
}