#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include "header.h"


void generatore_produttore(struct ProdConsGen *pc)
{    
    int i;    
    /* TODO: utilizzare il costrutto monitor per la produzione del messaggio */
    enter_monitor(&pc->m);
    
    while(pc->count == DIM_QUEUE)
    	wait_condition(&pc->m, VARCOND_GEN_PRODUTTORI);
    	
    pc->msg[pc->testa].type = MSG_TYPE;
    	
    for(i = 0; i < STRING_MAX_DIM-1; i++)
    	pc->msg[pc->testa].stringa[i] = 'a' + rand()%26;
    pc->msg[pc->testa].stringa[i] = '\0';
    
    for(i = 0; i < INT_MAX_DIM; i++)
    	pc->msg[pc->testa].array[i] = rand()%10;
    	
    pc->msg[pc->testa].var = 0;
    
    pc->testa = ++(pc->testa)%DIM_QUEUE;
    pc->count++;
    
    printf("[generatore_produttore] Messaggio generato!\n");
    printf("[generatore_produttore] ...............msg.stringa: %s\n", pc->msg[pc->testa].stringa);
    printf("[generatore_produttore] ...............msg.array[0]: %d\n", pc->msg[pc->testa].array[0]);
    printf("[generatore_produttore] ...............msg.array[1]: %d\n", pc->msg[pc->testa].array[1]);
    printf("[generatore_produttore] ...............msg.var: %d\n", pc->msg[pc->testa].var);
 
    /* TODO: ... */
    
    signal_condition(&pc->m, VARCOND_GEN_CONSUMATORI);
    
    leave_monitor(&pc->m);
}

void generatore_consumatore(struct ProdConsGen *pc, int ds_queue_gen_filter){

    /* TODO: utilizzare il costrutto monitor per la consumazione del messaggio e l'invio verso il processo filter */
    enter_monitor(&pc->m);
    
    while(pc->count == 0)
    	wait_condition(&pc->m, VARCOND_GEN_CONSUMATORI);
    
    printf("[generatore_consumatore] Messaggio CONSUMATO!\n");
    printf("[generatore_consumatore] ...............msg.stringa: %s\n", pc->msg[pc->coda].stringa);
    printf("[generatore_consumatore] ...............msg.array[0]: %d\n", pc->msg[pc->coda].array[0]);
    printf("[generatore_consumatore] ...............msg.array[1]: %d\n", pc->msg[pc->coda].array[1]);
    printf("[generatore_consumatore] ...............msg.var: %d\n", pc->msg[pc->coda].var);
    
    pc->coda = ++(pc->coda)%DIM_QUEUE;
    pc->count--;
    
    /* TODO: invio del messaggio consumato al processo filter */
    int ret = msgsnd(ds_queue_gen_filter, (void*)&pc->msg[pc->coda], sizeof(message)-sizeof(long), 0);
    
    if (ret<0){
            perror("msgsnd del messaggio on ds_queue_gen_filter FALLITA!");
            exit(-1);
    }
    printf("[generatore_consumatore] Messaggio INVIATO!\n");
    
    /* TODO: ... */
    
    signal_condition(&pc->m, VARCOND_GEN_PRODUTTORI);
    
    leave_monitor(&pc->m);
}

