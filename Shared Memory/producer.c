#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>

#define MAX_BUFFERS 10

struct shared_memory
{
    char buf[MAX_BUFFERS][256];
    int buffer_index;
};

int main()
{
    key_t s_key;
    int shm_id, i = 0;
    struct shared_memory *mem;
    char sentence[100];

    s_key = ftok("hello", 1);
    if (s_key == -1)
    {
        perror("ftok");
        exit(1);
    }

    if ((shm_id = shmget(s_key, sizeof(struct shared_memory), 0660 | IPC_CREAT)) == -1)
        perror("shmget");

    if ((mem = (struct shared_memory *)shmat(shm_id, NULL, 0)) == (struct shared_memory *)-1)
        perror("shmat");
        
    mem->buffer_index = 0;

    printf("Enter a string\n");
    scanf("%s", sentence);
    sleep(1);

    for (i = 0; i < 10; i++)
    {
        strcpy(mem->buf[mem->buffer_index], sentence);
        mem->buffer_index++;
    }
}