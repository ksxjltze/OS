#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>


#define THREADS 20000
void *incr();
int a = 0;
int main()
{
    pthread_t thread[THREADS];
    int iret, i;

    /* Create independent threads each of which will execute function incr*/
    for (i = 0; i < THREADS; i++)
    {
        iret = pthread_create(&thread[i], NULL, incr, (void *)NULL);
    }

    for (i = 0; i < THREADS; i++)
    {
        pthread_join(thread[i], NULL);
    }

    printf("All thread returns and a = : %d\n", a);
    exit(0);
}
void *incr()
{
    a = a + 1;
}