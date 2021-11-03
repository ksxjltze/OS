#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define THREADS 12

int data[5] = {0, 0, 0, 0, 0};
int yes[THREADS] = {0, 0, 0};

void* produce(void* p_index)
{
    int x = 0;
    int index = *((int*)p_index);

    printf("Producer ID: %d\n", index);

    while (1)
    {
        for (int i = 0; i < 5; ++i)
        {
            data[i] = (index + 1) * x++;
        }
        x += index;

        yes[index] = 1;
        sleep(1);
    }
}

void* consume(void* p_index)
{
    int index = *((int*)p_index);
    printf("Consumer ID: %d\n", index);

    while (1)
    {
        if (yes[index] == 1)
        {
            sleep(1);
            for (int i = 0; i < 5; ++i)
            {
                printf("%d: %d", index, data[i]);
                if (i < 4)
                    printf(", ");
            }
            printf ("\n");
            yes[index] = 0;
        }
    }
}   

int main()
{
    pthread_t thread[THREADS];
    int iret;

    int n = THREADS / 2;
    printf("Pair Count: %d\n", n);

    //Producers
    for (int i = 0; i < n; i++)
    {
        int x = i;
        iret = pthread_create(&thread[i], NULL, produce, (void *)(&x));
    }

    //Consumers
    for (int i = 0; i < n; ++i)
    {
        int x = i;
        iret = pthread_create(&thread[n + i], NULL, consume, (void *)(&x));
    }

    for (int i = 0; i < THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }

    exit(0);
}
