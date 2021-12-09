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


void generatore_produttore(Buffer* pc)
{
    enter_monitor(&(pc->monitor));

    while(pc->testa == DIM_QUEUE)
        wait_condition(&(pc->monitor), VARCOND_GEN_PRODUTTORI);

    int i;
    char c;

    srand(time(NULL));
    
    //genero stringa casuale
    for (i = 0; i < STRING_MAX_DIM; i++){
        c = 'a' + (rand()%26);
        pc->msg[pc->testa].string[i] = c;
    }
    pc->msg[pc->testa].string[i] = '\0';

    //genero array interi casuale
    pc->msg[pc->testa].intarray[0] = rand()%10;
    pc->msg[pc->testa].intarray[1] = rand()%10;

    pc->msg[pc->testa].var = 0;
    pc->msg[pc->testa].type = MSG_TYPE;
    printf("[generatore_produttore] Messaggio generato!\n");
    printf("[generatore_produttore] ...............msg.stringa: %s\n", pc->msg[pc->testa].string);
    printf("[generatore_produttore] ...............msg.intarray[0]: %d\n", pc->msg[pc->testa].intarray[0]);
    printf("[generatore_produttore] ...............msg.intarray[1]: %d\n", pc->msg[pc->testa].intarray[1]);
    printf("[generatore_produttore] ...............msg.var: %d\n", pc->msg->var);
    
    pc->testa = (pc->testa+1) % DIM_QUEUE;
    pc->count++;

    signal_condition(&(pc->monitor), VARCOND_GEN_CONSUMATORI);

    leave_monitor(&(pc->monitor));
}

void generatore_consumatore(Buffer* pc, int ds_queue_gen_filter)
{
    enter_monitor(&(pc->monitor));
    
    while (pc->count == 0)
        wait_condition(&(pc->monitor), VARCOND_GEN_CONSUMATORI);

    printf("[generatore_consumatore] Messaggio CONSUMATO!\n");
    printf("[generatore_consumatore] ...............msg.stringa: %s\n", pc->msg[pc->coda].string);
    printf("[generatore_consumatore] ...............msg.array[0]: %d\n", pc->msg[pc->coda].intarray[0]);
    printf("[generatore_consumatore] ...............msg.array[1]: %d\n", pc->msg[pc->coda].intarray[1]);
    printf("[generatore_consumatore] ...............msg.var: %d\n", pc->msg[pc->coda].var);
    
    /* invio del messaggio consumato al processo filter */
    int ret = msgsnd(ds_queue_gen_filter, (void*)&(pc->msg[pc->coda]), sizeof(message)-sizeof(long), 0); //invio un messaggio alla volta tramite pc->msg[pc->coda] 

    if (ret<0){
            perror("msgsnd del messaggio on ds_queue_gen_filter FALLITA!");
            exit(-1);
    }
    printf("[generatore_consumatore] Messaggio INVIATO!\n");

    pc->coda = (pc->coda + 1) % DIM_QUEUE;
    pc->count--;
    
    signal_condition(&(pc->monitor), VARCOND_GEN_PRODUTTORI);

    leave_monitor(&(pc->monitor));
}

