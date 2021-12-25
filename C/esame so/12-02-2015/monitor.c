#include "monitor.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

static void waitsem(int, int);
static void signalsem(int, int);

void init_monitor(monitor* m, int ncvs)
{
    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664);
    m->semcv = semget(IPC_PRIVATE, ncvs, IPC_CREAT | 0664);
    m->shmcountcv = shmget(IPC_PRIVATE, sizeof(int)*ncvs, IPC_CREAT | 0664);
    m->countcv = (int*)shmat(m->shmcountcv, (void*)0, 0);
    
    semctl(m->mutex, MUTEX, SETVAL, 1);
    for(int i = 0; i < ncvs; i++) semctl(m->semcv, i, SETVAL, 0);
    for (int i = 0; i < ncvs; i++) m->countcv[i] = 0;
    m->ncvs = ncvs;
}

void remove_monitor(monitor* m)
{
    semctl(m->mutex, 0, IPC_RMID, (void*)0);
    semctl(m->semcv, m->ncvs, IPC_RMID, (void*)0);
    shmctl(m->shmcountcv, IPC_RMID, (void*)0);
}

void mutexlock(monitor* m)
{
    waitsem(m->mutex, MUTEX);   
}

void mutexunlock(monitor* m)
{
    signalsem(m->mutex, MUTEX);
}

int monitorop(monitor* m, u_int op)
{
    //op == m->mutexop.lock ? waitsem(m->mutex, MUTEX) : signalsem(m->mutex, MUTEX);

    if(op == m->mutexop.lock)
        waitsem(m->mutex, MUTEX);
    else if(op == !m->mutexop.lock)
        signalsem(m->mutex, MUTEX);
    else{
        perror("Invalid monitor operation\n");
        return -1;
    }

    return 1;
}


void condwait(monitor* m, int idcv)
{
    signalsem(m->mutex, MUTEX);

    waitsem(m->semcv, idcv);

    waitsem(m->mutex, MUTEX);
}


void condsignal(monitor* m, int idcv)
{
    if(m->countcv[idcv] > 0){
        m->countcv[idcv]--;
        signalsem(m->semcv, idcv);
    }
}

int queuecond(monitor* m, int idcv)
{
    return m->countcv[idcv];
}

void waitsem(int semid, int semnum)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = -1;

    semop(semid, &buf, 1);
}

void signalsem(int semid, int semnum)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = 1;

    semop(semid, &buf, 1);
}