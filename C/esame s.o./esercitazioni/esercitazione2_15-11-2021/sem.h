#ifndef _SEM_H_
#define _SEM_H

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define NUMSEM 2

enum semafori {
    MUTEXL,
    SYNCH
};

int waitsem(int semid, int numsem);
int signalsem(int semid, int numsem);

#endif