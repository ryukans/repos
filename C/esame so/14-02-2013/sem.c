#include "sem.h"

void waitsem(int semnum, int semid)
{
    int err;
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = -1;
    err = semop(semid, &buf, 1);

    if(err) exit(-1);
}

void signalsem(int semnum, int semid)
{
    int err;
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = 1;
    err = semop(semid, &buf, 1);

    if(err) exit(-1);
}