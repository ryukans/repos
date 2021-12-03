#ifndef _MONITOR_SC_H
#define _MONITOR_SC_H

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

typedef struct {
    int mutex;
    
    int idconds;
    int nvarcond;
    
    int idshmem;
    int* condcounts;
} Monitor;

void init_monitor(Monitor*, int nvarcond); 
void enter_monitor(Monitor*);
void leave_monitor(Monitor*);
void remove_monitor(Monitor*);
void wait_condition(Monitor*, int id_varcond);
void signal_condition(Monitor*, int id_varcond);
void signal_all(Monitor*, int id_varcond);
int queue_condition(Monitor*, int numsem); 

#endif

