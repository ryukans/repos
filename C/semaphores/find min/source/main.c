#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <limits.h>
#include <time.h>
#include <stdlib.h>

#include "../header/processes.h"

#define N_ELEM 1000 //sub partition size

int main()
{
    int vector_id;
    int buffer_id;
    int sem_id;
    int *vector;
    int *buffer;

    vector_id = shmget(vector_id, sizeof(int)*NUM_ELEMENTS, IPC_CREAT | 0664);
    /* TBD: usare shmget() per creare un vettore di interi su 
               *      memoria condivisa, con NUM_INTERI elementi */

    if (vector_id < 0){
        perror("Cannot create array in shared memory\n");
        exit(1);
    }

    vector = (int*) shmat(vector_id, NULL, 0);
    /* TBD: usare shmat() per ottenere un puntatore */

    if (vector == (void *)-1){
        perror("Cannot initialize array in shared memory\n");
        exit(1);
    }

    /* Inizializza il vettore con numeri casuali tra 0 e INT_MAX */

    srand(12345);
    int i;
    for (i = 0; i < NUM_ELEMENTS; i++){
        vector[i] = rand()%INT_MAX;
        //printf("[DEBUG] - %d\n", vettore[i]);
    }

    buffer_id = shmget(buffer_id, sizeof(int), IPC_CREAT | 0664);
    /* TBD: usare shmget() per creare un buffer singolo su
                 *      memoria condivisa, con un intero */

    if (buffer_id < 0){
        perror("Cannot create buffer in shared memory\n");
        exit(1);
    }

    buffer = (int*) shmat(buffer_id, NULL, 0); 
    /* TBD: usare shmat() per ottenere un puntatore */

    if (buffer == (void *)-1){
        perror("Cannot initialize buffer in shared memory\n");
        exit(1);
    }

    /* Inizializza il buffer ad INT_MAX.
     * Il valore da ricercare sarà, per definizione, minore del valore iniziale.
     */

    *buffer = INT_MAX;

    /* Inizializzazione semafori */

    sem_id = semget(IPC_PRIVATE, 1, IPC_CREAT | 0664); 
    semctl(sem_id, 0, SETVAL, 1);


    /* Avvio dei processi figli */

    /* TBD: creare 10 processi figli, ognuno dei quali dovrà eseguire
     *      la funzione "figlio()". Alla funzione, passare come parametri:
     *      - il puntatore al vettore 
     *      - il puntatore al buffer singolo
     *      - l'ID del vettore di semafori
     *      - l'indice del primo elemento da elaborare
     *      - il numero di elementi da elaborare (1000)
     */

    int first_elem;
    for(i = 0, first_elem = 0; i < NUM_PROCESSES; i++, first_elem+=N_ELEM){
        pid_t pid = fork();

        if(pid < 0){
            perror("Error fork\n");
            exit(-1);
        }

        if(pid == 0){
            childproc(vector, buffer, sem_id, first_elem, N_ELEM);
            exit(0);
        }
    }

    /* Processo padre */
    printf("DEBUG: Chiamta padre con i: %d\n", i);
    fatherproc(buffer, sem_id);


    /* Deallocazione risorse IPC */

    semctl(sem_id, 0, IPC_RMID);
    shmctl(vector_id, IPC_RMID, 0);
    shmctl(buffer_id, IPC_RMID, 0);
}