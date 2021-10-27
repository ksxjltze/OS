#include "shm.h"

int main()
{
    key_t s_key;
    int shm_id;
    shm_t* mem = 0;

    size_t shm_size = sizeof(int);

    //Generate key
    s_key = ftok("hello", 1);
    if (s_key == -1)
    {
        perror("ftok");
        exit(1);
    }

    if ((shm_id = shmget(s_key, shm_size, 0)) == -1)
        perror("shmget");

    if ((mem = (shm_t*)shmat(shm_id, NULL, 0)) == (shm_t*)-1)
        perror("shmat");

    printf("Value: %d\n", *mem);

    return 0;
}