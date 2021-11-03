#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>

#define ITEM_COUNT 5
#define THREADS 3
#define SYNC 1

void *producer();
void *consumer();

int a[ITEM_COUNT];
int count;

sem_t mutex;

int main()
{
    pthread_t producer_threads[THREADS];
    pthread_t consumer_threads[THREADS];

    int i;
    count = 0;

    for (int i = 0; i < ITEM_COUNT; ++i)
    {
        a[i] = 0;
    }

    sem_init(&mutex, 0, 1);

    for (i = 0; i < THREADS; i++)
    {
       pthread_create(&producer_threads[i], NULL, producer, (void *)&i);
       pthread_create(&consumer_threads[i], NULL, consumer, (void *)&i);
    }

    for (i = 0; i < THREADS; i++)
    {
        pthread_join(producer_threads[i], NULL);
        pthread_join(consumer_threads[i], NULL);
    }    
    
    for (int i = 0; i < ITEM_COUNT; ++i)
    {
        printf("\nAll thread returns and Item %d = %d\n", i, a[i]);
    }

    sem_destroy(&mutex);
    exit(0);
}

void* producer(void* arg)
{
    int id = *(int*)arg;
    while (1)
    {
    #if SYNC
        sem_wait(&mutex);
    #endif

        //ENTER CRITICAL SECTION
        sleep(1);

        int index = ++count % ITEM_COUNT;
        int value = count;

        a[index] = value;

        printf("[PRODUCER %d] Value of item %d set to: %d\n", id, index, value);
        //EXIT CRITICAL SECTION

    #if SYNC
        sem_post(&mutex);
    #endif

        sleep(5);
    }
}

void* consumer(void* arg)
{
    int id = *(int*)arg;
    while (1)
    {
    #if SYNC
        sem_wait(&mutex);
    #endif

        //ENTER CRITICAL SECTION
        sleep(1);

        int index = count % ITEM_COUNT;        
        int value = a[index];

        printf("[CONSUMER %d] Value of item %d is: %d\n", id, index, value);
        a[index] = -1;

        //EXIT CRITICAL SECTION

    #if SYNC
        sem_post(&mutex);
    #endif

        sleep(5);
    }
}