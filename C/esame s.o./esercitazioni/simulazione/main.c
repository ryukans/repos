#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/types.h>

#include "header.h"

#define NUM_THREADS_OPERANDI    2
#define NUM_THREADS_CALCOLO     3

int coda_ris;

int main(){

        pthread_attr_t attr;
        pthread_t t_operandi[NUM_THREADS_OPERANDI];
        pthread_t t_calcolo[NUM_THREADS_CALCOLO];
    
        srand(time(NULL)*getpid());

        coda_ris = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
        printf("Coda coda_risultati create con desc: %d\n", coda_ris);
    
        initServiceQueues();
            
        // Creazione di una istanza di struttura monitor per gli operandi
        // MonitorOperandi sarà usato dai thread generazione operandi
        MonitorOperandi * pc_op = (MonitorOperandi*)malloc(sizeof(MonitorOperandi));
    
        /* TODO: inizializzazione mutex e condition */
        pthread_mutex_init(&pc_op->mutex, NULL);
        pthread_cond_init(&pc_op->cvprod, NULL);
        pthread_cond_init(&pc_op->cvcons, NULL);

        /* TODO: inizializzazione delle variabili di stato */
        pc_op->testa = pc_op->coda = pc_op->count = 0;
        
        /* TODO: impostazione dei thread come joinable */
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

        /* TODO: genero processo prelievo risultati */
        if(!(fork())){
                preleva_risultati(coda_ris);
        }

        /* TODO: genero thread generazione operandi */
        for (int i = 0; i < NUM_THREADS_OPERANDI; i++)
        {
                pthread_create(&t_operandi[i], &attr, genera_operandi, (void*)pc_op);
        }
        
    
        /* TODO: genero thread di calcolo */
        for (int i = 0; i < NUM_THREADS_CALCOLO; i++)
        {
                pthread_create(&t_calcolo[i], &attr, calcola, (void*)pc_op);
        }
    
        /* TODO: Join threads a wait processo*/
        for (int i = 0; i < NUM_THREADS_OPERANDI; i++)
        {
                pthread_join(t_operandi[i], NULL);
        }
        
        for (size_t i = 0; i < NUM_THREADS_CALCOLO; i++)
        {
                pthread_join(t_calcolo[i], NULL);
        }
        
        wait(NULL);

        /* TODO: deallocazione risorse */
        removeServiceQueues();
        pthread_attr_destroy(&attr);
        pthread_mutex_destroy(&pc_op->mutex);
        pthread_cond_destroy(&pc_op->cvprod);
        pthread_cond_destroy(&pc_op->cvcons);
        free(pc_op);

        pthread_exit(NULL);

        printf("[MAIN] - Exit success\n");
        return 0;
}

