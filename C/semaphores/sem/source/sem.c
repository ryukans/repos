#include <stdio.h>
#include <errno.h>
#include "../header/sem.h"

int waitsem(int sem_id, int sem_num)
{
    int op;
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = sem_num;
    buf.sem_op = -1;

    op = semop(sem_id, &buf, 1);

    if(op < 0)
        perror("Error Wait\n");
    
    return op;
}


int signalsem(int sem_id, int sem_num)
{
    int op;
    struct sembuf buf;

    buf.sem_flg = 0;
    buf.sem_num = sem_num;
    buf.sem_op = 1;

    op = semop(sem_id, &buf, 1);

    if(op < 0)
        perror("Error Signal\n");

    return op;   
}

