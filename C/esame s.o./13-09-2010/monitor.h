#pragma once

/*
typedef struct sembuf_mutex{
    int id;
    int num;
} mutexsem;*/

typedef struct{

    int mutex;  //id semaforo mutex del monitor

    int ncv; // ncv: numero cond var

    int conds;  //id semaforo cond

    int shmconds;
    int *cvcount;

} monitor;

void init_monitor(monitor*, int num_cond_vars);
void rem_monitor(monitor*);

void monitor_mutex_lock(monitor*);
void monitor_mutex_unlock(monitor*);

void monitor_cond_wait(monitor*, int idcv);
void monitor_cond_signal(monitor*, int idcv);

int numconds(monitor*, int idcv); //ritorna il numero totale della cond var