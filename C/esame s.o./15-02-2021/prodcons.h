#ifndef _PRODCONS_H_
#define _PRODCONS_H_

#include <pthread.h>

#define DIM 4

enum lwps{
    NUM_CONS = 1,
    NUM_PROD = 5
};

//#define TIMER_INDEX (NUM_PROD+NUM_CONS)

typedef struct {

    int buffer[DIM];
    int testa;
    int coda;
    int count;
    
    /* TBD: Definire variabili per la sincronizzazione,
     *      e una variabile "uscita_timer"
     */

    pthread_mutex_t mutex;
    pthread_cond_t cvcons;
    pthread_cond_t cvprod;
    
    int uscita_timer;

} MonitorProdCons;

void inizializza_monitor(MonitorProdCons * m);
void distruggi_monitor(MonitorProdCons * m);
int produci(MonitorProdCons * m, int val);
int consuma(MonitorProdCons * m, int * val);

#endif