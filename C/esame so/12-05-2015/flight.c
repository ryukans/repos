#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MONITOR &buf->m

void init_buffer(Buffer* buf)
{
    init_monitor(MONITOR);

    
    for(int i = 0; i < BUF_SIZE; i++){
        buf->flights[i].id = 0;
        buf->flights[i].quote = 0;
        buf->status[i] = FREE;
    }

    buf->nfree = BUF_SIZE;
    
    printf("Initialized\n");
}

void destroy_buffer(Buffer* buf)
{
    destroy_monitor(MONITOR);
}

void ins_flight(Buffer* buf, int id)
{
    //startprod
    pthread_mutex_lock(MONITOR.mutex);

    while(buf->nfree == 0){
        printf("[DEBUG PROD]: prod on wait\n");
        pthread_cond_wait(MONITOR.cvinsert, MONITOR.mutex);
    }

    int index = 0;

    while(index < BUF_SIZE && buf->status[index] != FREE)
        ++index;
    
    buf->status[index] = IN_USE;
    buf->nfree--; //produced

    pthread_mutex_unlock(MONITOR.mutex);

    //prod
    sleep(1);
    
    buf->flights[index].id = id;
    buf->flights[index].quote = 0;

    //endprod
    pthread_mutex_lock(MONITOR.mutex);

    buf->status[index] = OCCUPIED;
    //buf->noccup++;

    pthread_cond_signal(MONITOR.cvremove);

    pthread_mutex_unlock(MONITOR.mutex);
}

void rem_flight(Buffer* buf, int id)
{   
    //startcons
    pthread_mutex_lock(MONITOR.mutex);

    int index = 0;

    while(index < BUF_SIZE && buf->status[index] != OCCUPIED && buf->flights[index].id != id)
        ++index;

    buf->status[index] = IN_USE;
    //buf->noccup--; //consumed

    pthread_mutex_unlock(MONITOR.mutex);
    
    //cons
    sleep(1);
    
    buf->flights[index].id = 0;

    //endcons
    pthread_mutex_lock(MONITOR.mutex);

    buf->status[index] = FREE;
    buf->nfree++;

    //pthread_cond_signal(MONITOR.cvinsert);

    pthread_mutex_unlock(MONITOR.mutex);
}

void upd_flight(Buffer* buf, int id, int quote)
{
    //startupd
    pthread_mutex_lock(MONITOR.mutex);

    int index = 0;

    while(index < BUF_SIZE && buf->status[index] != OCCUPIED && buf->flights[index].id != id)
        ++index;

    buf->status[index] = IN_USE;
    //buf->noccup;

    pthread_mutex_unlock(MONITOR.mutex);

    //upd
    int sleeptime = rand()%3+1;

    sleep(sleeptime);

    //buf->flights[index].id = id;
    buf->flights[index].quote = quote;

    pthread_mutex_lock(MONITOR.mutex);

    buf->status[index] = OCCUPIED;

    //pthread_cond_signal(MONITOR.cvremove);

    pthread_mutex_unlock(MONITOR.mutex);
}








