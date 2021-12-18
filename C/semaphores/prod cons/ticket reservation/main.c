#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>

#define NUM_CLIENTI 10
#define NUM_VISUAL 1



int main()
{
    pig memory;
    pig sem;

    memory.key = ftok(".", 'A');
    memory.id = shmget(memory.key, sizeof(teatro), IPC_CREAT | 0664);
    teatro* p_teatro = (teatro*)shmat(memory.id, NULL, 0);

    p_teatro->disponibili = DIMBUF;
    for(int i = 0; i < DIMBUF; i++){
        p_teatro->posti[i].id_cliente = 0;
        p_teatro->posti[i].stato = LIBERO;
    }

    printf("Inizializzato\n\n");

    sem.key = ftok(".", 'B');
    sem.id = semget(sem.key, 3, IPC_CREAT | 0664);
    semctl(sem.id, CLIENTE, SETVAL, 0);
    semctl(sem.id, VISUAL, SETVAL, 0);
    semctl(sem.id, MUTEXC, SETVAL, 1);



    // corretto ?
    for (int i = 0; i < NUM_CLIENTI+NUM_VISUAL; i++)
    {
        if(i%2){
            if(!(fork())){
                printf("Prenotazione in corso.....\n\n");
                sleep(3);
                int nposti = rand()%4+1;
                prenota(p_teatro, nposti, sem.id);
            }
        }
        else{
            if(!(fork())){
                sleep(1);
                execl(".visual", ".visual", NULL);
            }
        }
    }
    
    for (int i = 0; i < NUM_CLIENTI+NUM_VISUAL; i++)
        wait(NULL);
    

    return 0;
}