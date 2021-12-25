#include "monitor.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

static void waitsem(int, int);
static void signalsem(int, int);
static int queuesem(int, int);

void init_monitor(monitor* m, int ncv)
{
    //allocazione semafori
    m->ncv = ncv;
    printf("here\n");
    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT|0664);
    m->conds = semget(IPC_PRIVATE, ncv, IPC_CREAT | 0664);    

    //inizializzazione semafori
    semctl(m->mutex, 0, SETVAL, 1);
    for (int i = 0; i < ncv; i++)
        semctl(m->conds, i, SETVAL, 0);

    //allocazione shared mempory
    m->shmconds = shmget(IPC_PRIVATE, sizeof(int)*ncv, IPC_CREAT | 0664);
    
    //attach shared memory
    m->cvcount = (int*)shmat(m->shmconds, NULL, 0);


    //inizializzazione array contatori di cond var
    for (int i = 0; i < ncv; i++)
        m->cvcount[i] = 0;
    
    printf("Monitor inizzializzato\n");
}

void rem_monitor(monitor* m)
{
    semctl(m->mutex, 0, IPC_RMID, NULL);
    semctl(m->conds, 0, IPC_RMID, NULL);
    shmctl(m->shmconds, IPC_RMID, NULL);
}

void monitor_mutex_lock(monitor* m)
{
    //printf("[DEBUG id: %d] - Igresso monitor in corso...\n", getpid());
    waitsem(m->mutex, 0);
    //printf("[DEBUG id: %d] - Entrato nel monitor\n", getpid());
}

void monitor_mutex_unlock(monitor* m)
{
    //printf("[DEBUG pid: %d] - USCITA MONITOR\n", getpid());
    signalsem(m->mutex, 0);
}

void monitor_cond_wait(monitor* m, int idcv)
{
    m->cvcount[idcv]++;
    
    signalsem(m->mutex, 0);

    waitsem(m->conds, idcv);

    m->cvcount[idcv]--;
}

void monitor_cond_signal(monitor* m, int idcv)
{
    if(m->cvcount[idcv] > 0){
        signalsem(m->conds, idcv);
    }
    else{
        signalsem(m->mutex, 0);
    }
}

int numconds(monitor* m, int idcv)
{
    return m->cvcount[idcv];
}

void waitsem(int numsem, int idsem)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = numsem;
    buf.sem_op = -1;
    semop(idsem, &buf, 1);
}

void signalsem(int numsem, int idsem)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = numsem;
    buf.sem_op = 1;
    semop(idsem, &buf, 1);
}

int queuesem(int numsem, int idsem)
{
    return (semctl(idsem, numsem, GETNCNT, NULL));
}