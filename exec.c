#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing program...\n");
    int pid;

    pid = fork();
    if (pid == 0)
    {
        execl("./hello", "./hello", NULL);

    }
    else
    {
        sleep(1);
        pid = fork();

        if (pid == 0)
            execl("./world", "./world", NULL);
        else
        {
            sleep(1);
            pid = fork();
            if (pid == 0)
                execl("./sit", "./sit", NULL);
        }
           
    }

    sleep(1);
    printf("Finished execution...\n");


}