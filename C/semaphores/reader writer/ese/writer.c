#include "procedure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main()
{
    ipc shm, sem;

    srand(time(NULL));

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, 0, IPC_CREAT | 0664);
    buffer* buf = (buffer*)shmat(shm.id, NULL, 0);

    sem.key = ftok(PATHNAME, SEMID);
    sem.id = semget(sem.key, 0, IPC_CREAT | 0664);


    waitsem(sem.id, SYNCHRW);

    sleep(1);
    buf->mess.val1 = rand()%10;
    buf->mess.val2 = rand()%10;
    printf("Written\n");

    signalsem(sem.id, SYNCHRW);

    exit(2);
}