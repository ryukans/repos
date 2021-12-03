#include "../header/sem.h"

int waitsem(int semid, int semnum)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = -1;

    int op = semop(semid, &buf, 1);

    if(op < 0)
        perror("Error Wait\n");
    
    return op;
}

int signalsem(int semid, int semnum)
{
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = semnum;
    buf.sem_op = 1;
    

    int op = semop(semid, &buf, 1);

    if(op < 0)
        perror("Error Wait\n");
    
    return op;
}


