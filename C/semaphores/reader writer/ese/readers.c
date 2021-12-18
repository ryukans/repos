#include "procedure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    ipc shm, sem;

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, 0, IPC_CREAT | 0664);
    buffer* buf = (buffer*)shmat(shm.id, NULL, 0);


    sem.key = ftok(PATHNAME, SEMID);
    sem.id = semget(sem.key, 0, IPC_CREAT | 0664);


    waitsem(sem.id, MUTEXL);

    buf->readers++;
    if(buf->readers == 1)
        waitsem(sem.id, SYNCHRW);

    signalsem(sem.id, MUTEXL);

    sleep(1);

    if(buf->readers == 1)
        printf("Val 1: %d\n", buf->mess.val1);
    else
        printf("Val 2: %d\n", buf->mess.val2);
    
    waitsem(sem.id, MUTEXL);

    buf->readers--;
    if(buf->readers == 0)
        signalsem(sem.id, SYNCHRW);

    signalsem(sem.id, MUTEXL);

    exit(1);
}