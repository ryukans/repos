#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include <sys/ipc.h>
#include <sys/shm.h>

#include "header.h"

int main()
{

        pid_t pid;
        int ds_queue_gen_filter, ds_queue_filter_checksum, ds_queue_checksum_visual;
        int total_process = NUM_GENERATORS + NUM_FILTER + NUM_CHECKSUM + NUM_VISUAL;

        //create queues
        /* chiave coda generatore-filtro */
        int key_queue_gen_filter = IPC_PRIVATE;
        /* definire chiave coda filtro-checksum */
        int key_queue_filter_checksum = IPC_PRIVATE;
        /* definire chiave coda checksum-visualizzatore */
        int key_queue_checksum_visual = IPC_PRIVATE; 

        /* descrittore coda generatore-filtro */
        ds_queue_gen_filter = msgget(key_queue_gen_filter, IPC_CREAT | 0664);
        /* descrittore coda filtro-checksum */
        ds_queue_filter_checksum = msgget(ds_queue_filter_checksum, IPC_CREAT | 0664);;
         /* descrittore coda checksum-visualizzatore */
        ds_queue_checksum_visual = msgget(ds_queue_checksum_visual, IPC_CREAT | 0664);
        
        printf("[master] Code create...\n");
        printf("[master] ...........ds_queue_gen_filter: %d\n", ds_queue_gen_filter);
        printf("[master] ...........ds_queue_filter_checksum: %d\n", ds_queue_filter_checksum);
        printf("[master] ...........ds_queue_checksum_visual: %d\n", ds_queue_checksum_visual);

        /* creazione shm per prod-cons generatori */
    
        /* chiave shared memory per prod/cons generatori*/
        key_t shm_key = IPC_PRIVATE;
        /* descrittore della shared memory per prod/cons generatori*/
        int ds_shm = shmget(shm_key, sizeof(Buffer), IPC_CREAT | 0664); 

        if(ds_shm<0) { perror("SHM errore"); exit(1); }

        /*riferimento per il segmento di shm */
        Buffer* pc = (Buffer*) shmat(ds_shm, NULL, 0);

        if(pc == (void*)-1) { perror("SHM attach error\n"); exit(1); }


        /* TODO: inizializzare variabili utilizzate per la sincronizzazione generatori */
        init_monitor(&(pc->monitor), 2); // due monitor, per var cons consum e var cons prod
        pc->coda = pc->testa = pc->count = 0;
    
        int i;

        for (i=0; i<NUM_GENERATORS; i++){
        
                pid = fork();

                if (pid == 0){
                
                    if (i % 2 == 0){
                        
                        printf("GENERATORE PROD PID: %d\n", getpid());
                        int j;
                        for (j=0; j<4; j++){
                            srand(time(NULL)*getpid()+j);
                            generatore_produttore(pc);
                        }
                        exit(0);
                    }
                    else {
                        printf("GENERATORE CONS PID: %d\n", getpid());
                        int j;
                        for (j=0; j<4; j++){
                            generatore_consumatore(pc, ds_queue_gen_filter);
                        }
                        exit(0);
                    }
                }        
        }        


        for (i=0; i<NUM_FILTER+NUM_CHECKSUM+NUM_VISUAL; i++){
                pid = fork();
                if (pid==0){
                        if (i==0){
                            printf("FILTRO PID: %d\n", getpid());
                            filtro(ds_queue_gen_filter, ds_queue_filter_checksum);
                        }
                        else if (i==1){
                            printf("CHECKSUM PID: %d\n", getpid());
                            checksum(ds_queue_filter_checksum, ds_queue_checksum_visual);
                        }
                        else if (i==2){
                            printf("VISUALIZZATORE PID: %d\n", getpid());
                            visualizzatore(ds_queue_checksum_visual);
                        }
                }
        }

       
        for (i=0; i<total_process; i++){
                wait(NULL);
        }

        /* TODO: deallocare risorse (code, shm, monitor) */
        msgctl(ds_queue_gen_filter, IPC_RMID, NULL);
        msgctl(ds_queue_filter_checksum, IPC_RMID, NULL);
        msgctl(ds_queue_checksum_visual, IPC_RMID, NULL);
        shmctl(ds_shm, IPC_RMID, NULL);
        remove_monitor(&(pc->monitor));

        printf("[master] Rimozione code OK!\n");
        printf("[master] Rimozione monitor OK!\n");
    
        return 0;
}
