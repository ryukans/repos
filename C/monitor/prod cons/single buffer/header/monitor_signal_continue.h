#ifndef _MONITOR_SC_H
#define _MONITOR_SC_H

#include <stdio.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/types.h>

typedef struct {
    int mutex;

    int idconds; //sem ids
    int nconds;

    int idshmconds; //shared mem id for array
    int* condcounts; //array condition counts
} Monitor;

void init_monitor(Monitor*, int nconds);
void enter_monitor(Monitor*);
void leave_monitor(Monitor*);
void remove_monitor(Monitor*);
void wait_condition(Monitor*, int idcond);
void signal_condition(Monitor*, int idcond);
int queue_condition(Monitor*, int idcond);

#endif