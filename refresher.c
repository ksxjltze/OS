#include <stdio.h>
#include <unistd.h>

#define CHILD_COUNT 2

void split()
{
    int pid;

    pid = fork();

    if (pid == 0)
    {
        printf("Child process with PID: %d\n", getpid());
    }
}

int main()
{
    int pid = getpid();
    printf("Parent process with PID: %d\n", pid);

    for (int i = 0; i < 5; ++i)
    {
        if (pid != 0)
        {
            //printf("%d\n", i);
            pid = fork();
            if (pid == 0)
            {
                printf("Child process with PID: %d\n", getpid());
                break;
            }

            //printf("Child process with PID: %d\n", pid);
        }


    }

    //int n;
    // int pid[CHILD_COUNT];

    // for (int i = 0; i < CHILD_COUNT; ++i)
    // {
    //     pid[i] = fork();
    //     //printf("Child process with PID: %d\n", pid[i]);
    // }

    // for (int i = 0; i < CHILD_COUNT; ++i)
    // {
    //     if (pid[i] == 0)
    //     {
    //         printf("Child process with PID: %d\n", getpid());
    //     }
    //     else
    //     {
    //         printf("Parent process with PID: %d\n", getpid());
    //         printf("Parent process with child PID: %d\n", pid[i]);
    //     }
        
    // }
    sleep(5);
    
}