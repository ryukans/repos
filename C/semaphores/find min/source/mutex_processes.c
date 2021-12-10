#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/wait.h>
#include "../header/processes.h"
#include "../../sem/header/sem.h"

int initsem()
{
    int sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664); 
    /* TBD: usare semget() per allocare un vettore,
                  *      con un singolo semaforo "mutex" */

    if (sem_id < 0){
        perror("Cannot create mutex sem\n");
        exit(1);
    }

    /* Valore iniziale: 1 (mutua esclusione) */

    /* TBD: inizializzare il mutex */
    semctl(sem_id, 0, SETVAL, 1);

    return sem_id;
}

void childproc(
            int *vector,
            int *buffer,
            int sem_id,
            int first_elem,
            int nelem) //offset
{

    /* TBD: aggiungere dentro questa funzione delle chiamate a
     *      Wait_Sem() e Signal_Sem() per creare una sezione critica
     *      e realizzare la mutua esclusione */

    int i;
    int min = INT_MAX;

    waitsem(sem_id, 0);

    for (i = first_elem; i < first_elem+nelem; i++){
        if (vector[i] < min)
            min = vector[i];
    }

    printf("Figlio: Il minimo locale è %d\n", min);

    if (min < *buffer)
        *buffer = min;

    signalsem(sem_id, 0);
}

void fatherproc(
            int *buffer,
            int sem_id)
{

    /* Attesa terminazione processi figli */

    /* TBD: Utilizzare wait() per attendere la terminazione dei 10 figli */
    int i;
    for(i = 0; i < NUM_ELEMENTS; i++){
        wait(NULL);
    }

    /* Risultato finale */

    printf("Padre: Il valore minimo assoluto è: %d\n", *buffer);
}