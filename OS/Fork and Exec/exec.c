#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("Executing program...\n");
    int pid = getpid();

    const char* programs[3] = {"./hello", "./world", "./sit"};
    pid = fork();

    for (int i = 0; i < 3; ++i)
    {
        if (pid == 0)
        {
            const char* program_name = programs[i];
            execl(program_name, program_name, NULL);
        }
        else
        {
            pid = fork();
            sleep(1);
        }
    }
    
    if (pid != 0)
    {
        sleep(1);
        printf("Finished execution...\n");
    }


}