#ifndef _MONITOR_SC_H
#define _MONITOR_SC_H

#include <stdio.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define MUTEX 0

typedef struct {
    int mutex;
    
    int idconds;
    int nvarcond;
    
    int idshmconds;
    int* condcounts;
} Monitor;

void init_monitor(Monitor*, int nvarcond); 
void enter_monitor(Monitor*);
void leave_monitor(Monitor*);
void remove_monitor(Monitor*);
void waitcond(Monitor*, int id_varcond);
void signalcond(Monitor*, int id_varcond);
void signalall(Monitor*, int id_varcond);
int queueconds(Monitor*, int numsem); 

#endif

