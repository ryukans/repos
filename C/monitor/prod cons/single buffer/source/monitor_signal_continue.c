#include "../header/procedure.h"


static void waitsem(int idsem, int numsem);
static void signalsem(int idsem, int numsem);
static int queuesem(int idsems, int numsem);

void init_monitor(Monitor* m, int nconds)
{
    int i;
    
    // sem for monitor mutex
    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664);
    semctl(m->mutex, 0, SETVAL, 1);

    // sems for var conditions
    m->idconds = semget(IPC_PRIVATE, nconds, IPC_CREAT | 0664);
    for (i = 0; i < nconds; i++) semctl(m->idconds, i, SETVAL, 0);
    
    // allocate array of condition counters on shared mem
    m->idshmconds = shmget(IPC_PRIVATE, nconds*sizeof(int), IPC_CREAT | 0664);
    m->condcounts = (int*) shmat(m->idshmconds, NULL, 0);

    m->nconds = nconds;
    for (i = 0; i < nconds; i++) m->condcounts[i] = 0;  
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
    semctl(m->idconds, m->nconds, IPC_RMID, 0);
    shmctl(m->idshmconds, IPC_RMID, 0);
}

void wait_condition(Monitor* m, int idcond)
{
    m->condcounts[idcond]++;

    signalsem(m->mutex, 0);

    waitsem(m->idconds, idcond);

    waitsem(m->mutex, 0);
}

void signal_condition(Monitor* m, int idcond)
{
    if(m->condcounts[idcond] > 0){
        m->condcounts[idcond]--;
        signalsem(m->idconds, idcond);
    }
}

int queue_condition(Monitor* m, int idcond)
{
    return m->condcounts[idcond];
}

void waitsem(int idsem, int numsem)
{
    struct sembuf buf;

    buf.sem_num = numsem;
    buf.sem_flg = 0;
    buf.sem_op = 1;
    semop(idsem, &buf, 1);
}

void signalsem(int idsem, int numsem)
{
    struct sembuf buf;

    buf.sem_num = numsem;
    buf.sem_flg = 0;
    buf.sem_op = 1;
    semop(idsem, &buf, 1); 
}





