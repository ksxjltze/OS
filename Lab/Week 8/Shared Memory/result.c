#include "shm.h"

int main()
{
    key_t s_key;
    int shm_id;

    int sum = 0;
    shm_t* mem;

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

    *mem = 0;

    while (1)
    {
        if (*mem != 0)
        {
            sum += *mem;
            printf("Sum: %d\n", sum);

            *mem = 0;
        }
    }

    return 0;
}