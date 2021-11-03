#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define THREADS 20000

void *incr();
int a = 0;
sem_t mutex;

int main()
{
    pthread_t thread[THREADS];
    int iret, i;

    sem_init(&mutex, 0, 1);

    /* Create independent threads each of which will execute function incr*/
    for (i = 0; i < THREADS; i++)
    {
        iret = pthread_create(&thread[i], NULL, incr, (void *)&i);
    }

    for (i = 0; i < THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("\nAll thread returns and a = : %d\n", a);
    printf("iret: %d\n", iret);

    sem_destroy(&mutex);
    exit(0);
}

void *incr(void* arg)
{
    int i = *((int*)arg);
    (void)(i);

    sem_wait(&mutex);
    // printf("\nThread %d entered critical section\n", i);

    // printf("Thread %d working on the critical section\n", i);
    a = a + 1;
    printf("Value: %d\n", a);

    //printf("Thread %d exiting critical section\n", i);
    sem_post(&mutex);
    
    return 0;
}