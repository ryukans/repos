#include "../header/monitor_signal_continue.h"

static void waitsem(int, int);
static void signalsem(int, int);
static int queuesem(int, int);


void init_monitor(Monitor* m, int nvarconds)
{
    int i;

    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664);
    semctl(m->mutex, 0, SETVAL, 1);

    m->idconds = semget(IPC_PRIVATE, nvarconds, IPC_CREAT | 0664);
    for (i = 0; i < nvarconds; i++) semctl(m->idconds, i, SETVAL, 0);
    
    m->idshmem = shmget(IPC_PRIVATE, nvarconds*sizeof(int), IPC_CREAT| 0664);
    m->condcounts = (int*) shmat(m->idshmem, NULL, 0);

    m->nvarcond = nvarconds;
    for (i = 0; i < nvarconds; i++) m->condcounts[i] = 0;

}

void enter_monitor(Monitor* m)
{
    waitsem(m->mutex, 0);
}

void leave_monitor(Monitor* m)
{
    signalsem(m->mutex, 0);
}

void remove_monitor(Monitor* m)
{
    semctl(m->mutex, 0, IPC_RMID, 0);
    semctl(m->idconds, m->nvarcond, IPC_RMID,0);
    shmctl(m->idshmem, IPC_RMID, 0);
}

void wait_condition(Monitor* m, int idvarcond)
{
    m->condcounts[idvarcond]++;
    signalsem(m->mutex)
}





