#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>

#define N_PHILOSOPHERS 5
#define N_CHOPSTICKS 5

sem_t chopsticks[N_CHOPSTICKS];

void* think(void* args)
{
    int id = (*((int*)args))++;

    while(1)
    {        
        printf("Philosopher %d is thinking..\n", id);
        sleep(2);

        sem_wait(&chopsticks[id]);
        sem_wait(&chopsticks[(id + 1) % 5]);

        printf("Philosopher %d is eating..\n", id);
        sleep(2);
        printf("Philosopher %d has finished eating..\n", id);

        sem_post(&chopsticks[id]);
        sem_post(&chopsticks[(id + 1) % 5]);
    }
    return 0;
}

int main()
{
    pthread_t threads[N_PHILOSOPHERS];
    for (int i = 0; i < N_CHOPSTICKS; ++i)
    {
        sem_init(&chopsticks[i], 0, 1);
    }

    int result = 0;
    int x = 0;

    for (int i = 0; i < N_PHILOSOPHERS; ++i)
    {
        result = pthread_create(&threads[i], NULL, think, (void*)&x);
        assert(!result);
    }

    for (int i = 0; i < N_PHILOSOPHERS; ++i)
    {
        pthread_join(threads[i], NULL);
        assert(!result);
    }

    return 0;
}