#include "../header/monitor_signal_continue.h"

static void waitsem(int semid, int semnum);
static void signalsem(int semid, int semnum);
static int queuesem(int semid, int semnum);

void init_monitor(Monitor* m, int nvarconds)
{
    int i;

    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664);
    semctl(m->mutex, 0, SETVAL, 1);

    m->idconds = semget(IPC_PRIVATE, nvarconds, IPC_CREAT | 0664);
    for (i = 0; i < nvarconds; i++) semctl(m->idconds, i, SETVAL, 0);
    
    m->idshmconds = shmget(IPC_PRIVATE, nvarconds*sizeof(int), IPC_CREAT| 0664);
    m->condcounts = (int*)shmat(m->idshmconds, NULL, 0);

    m->nvarcond = nvarconds;
    for (i = 0; i < nvarconds; i++) m->condcounts[i] = 0;
}

void enter_monitor(Monitor* m)
{
    waitsem(m->mutex, MUTEX);
}

void leave_monitor(Monitor* m)
{
    signalsem(m->mutex, MUTEX);
}

void remove_monitor(Monitor* m)
{
    shmctl(m->idshmconds, IPC_RMID, 0);
    semctl(m->mutex, 0, IPC_RMID, 0);
    semctl(m->idconds, m->nvarcond, IPC_RMID,0);
}

void waitcond(Monitor* m, int idvarcond)
{
    m->condcounts[idvarcond]++;
    
    signalsem(m->mutex, MUTEX);

    waitsem(m->idconds, idvarcond);

    waitsem(m->mutex, MUTEX);
}

void signalcond(Monitor* m, int idvarcond)
{
    if(m->condcounts[idvarcond] > 0){
        m->condcounts[idvarcond]--;
        signalsem(m->idconds, idvarcond);
    }
}

void signalall(Monitor* m, int idvarcond)
{
    while(m->condcounts[idvarcond] > 0){
        m->condcounts[idvarcond]--;
        signalsem(m->idconds, idvarcond);
    }
}

int queueconds(Monitor* m, int idvarcond)
{
    return m->condcounts[idvarcond];
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

void queue_sem(int semid, int semnum)
{
    return (semctl(semid, semnum, GETNCNT, NULL));
}