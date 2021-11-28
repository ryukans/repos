#include "../header/procedure.h"


static void waitsem(int idsem, int numsem);
static void signalsem(int idsem, int numsem);
static int queuesem(int idsems, int numsem);

void init_monitor(Monitor* m, int n_var)
{
    int i;
    
    // sem for mutex
    m->mutex = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664);
    semctl(m->mutex, 0, SETVAL, 1);

    // sem for var condition
    m->idconds = semget(IPC_PRIVATE, n_var, IPC_CREAT | 0664);
    for (i = 0; i < n_var; i++) semctl(m->idconds, i, SETVAL, 0);
    
    // allocate a counter on a shared mem for each var cond
    m->idshmem = shmget(IPC_PRIVATE, n_var*sizeof(int), IPC_CREAT | 0664);
    m->condcounts = (int*) shmat(m->idshmem, NULL, 0);

    m->varconds = n_var;
    for (i = 0; i < n_var; i++) m->condcounts[i] = 0;  
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
    semctl(m->idconds, m->varconds, IPC_RMID, 0);
    shmctl(m->idshmem, IPC_RMID, 0);
}

void wait_condition(Monitor* m, int id_var)
{
    m->condcounts[id_var]++;

    signalsem(m->mutex, 0);
    waitsem(m->idconds, id_var);
    waitsem(m->mutex, 0);
}

void signal_condition(Monitor* m, int id_var)
{
    if(m->condcounts[id_var] > 0){
        m->condcounts[id_var]--;
        signalsem(m->idconds, id_var);
    }
}

int queue_condition(Monitor* m, int id_var)
{
    return m->condcounts[id_var];
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





