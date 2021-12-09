#include "../header/utils.h"
#include "../header/procedure.h"
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/wait.h>

int main()
{
    key_t keyshm = IPC_PRIVATE;
    int shm = shmget(keyshm, sizeof(T), IPC_CREAT | 0664);

    if (shm < 0)
    {
        perror("Error shmget function !\n");
        exit(EXIT_FAILURE);
    }

    T *shmptr = (T *)shmat(shm, NULL, 0);

    if (shmptr == (void *)-1)
    {
        perror("Error linking memory\n");
        exit(EXIT_FAILURE);
    }

    key_t keysem = IPC_PRIVATE;
    int sem = semget(keysem, NUMSEM, IPC_CREAT | 0664);

    if (sem < 0)
    {
        perror("Error semget funtcion\n");
        exit(EXIT_FAILURE);
    }

    // memory and sems initialization
    *shmptr = 0;
    semctl(sem, AVAIL_SPACE, SETVAL, 1);
    semctl(sem, AVAIL_MSG, SETVAL, 0);

    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        consumer(shmptr, sem);
        exit(EXIT_SUCCESS);
    }

    pid = fork();

    if (pid == 0)
    {
        producer(shmptr, sem);
        exit(EXIT_SUCCESS);
    }

    wait(NULL);
    wait(NULL);

    shmctl(shm, IPC_RMID, NULL);
    semctl(sem, 0, IPC_RMID);

    return 0;
}
