#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main()
{
    pig memory;
    pig sem;

    memory.key = ftok(".", 'A');
    memory.id = shmget(memory.key, sizeof(teatro), IPC_CREAT | 0664);
    teatro* p_teatro = (teatro*)shmat(memory.id, NULL, 0);

    sem.key = ftok(".", 'B');
    sem.id = semget(sem.key, 1, IPC_CREAT | 0664);
    semctl(sem.id, CLIENTE, SETVAL, 0);
    semctl(sem.id, VISUAL, SETVAL, 0);
    semctl(sem.id, MUTEXC, SETVAL, 1);

    int index = 0;
    while(index < DIMBUF && p_teatro->posti[index].stato != OCCUPATO)
        ++index;

    int n = p_teatro->disponibili;

    waitsem(sem.id, VISUAL); // aspetta che il messaggio sia disponibile

    //printf("!!!!!!!!!!!!!!!INFO:\n");
    for (int i = index; i < n; i++){
        if(p_teatro->posti[i].stato == OCCUPATO) 
            printf("Posto [%d] occupato da cliente <%ud>\n", i, p_teatro->posti[i].id_cliente);
        else
            printf("Posto [%d] libero", i);
    }
       
    exit(1);
}