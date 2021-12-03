#include <stdio.h>
#include <errno.h>
#include "sem.h"

int wait_sem(int sem_id, int sem_num)
{
    int op;
    struct sembuf buf;

    buff.sem_flg = 0;
    buff.sem_num = sem_num;
    buff.sem_op = -1;

    op = semop(sem_id, &buf, 1);

    if(op < 0)
        perror("Error Wait\n");
    
    return op;
}


int signal_sem(int sem_id, int sem_num)
{
    int op;
    struct sembuf buf;

    buff.sem_flg = 0;
    buff.sem_num = sem_num;
    buff.sem_op = 1;

    op = semop(sem_id, &buf, 1);

    if(op < 0)
        perror("Error Signal\n");

    return op;   
}

