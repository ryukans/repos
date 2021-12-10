#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

#include "prodcons.h"


/* Dichiarazione di metodo privato, che sarà
 * eseguito da un thread "timer" */
static void * thread_timer(void *);

void inizializza_monitor(MonitorProdCons * m) {

    printf("[MONITOR] Inizializzazione monitor\n");

    /* TBD: Inizializzazione il monitor, e avviare
     *      il thread timer
     */

    m->testa = m->coda = m->count = 0;
    m->uscita_timer = 0;
    pthread_mutex_init(&m->mutex, NULL);
    pthread_cond_init(&m->cvprod, NULL);
    pthread_cond_init(&m->cvcons, NULL);
    
    pthread_create(&threads[TIMER_INDEX], &attr, thread_timer, (void*)m);
}

void distruggi_monitor(MonitorProdCons * m) {

    printf("[MONITOR] Distruzione monitor\n");

    /* TBD: Disattivare il monitor, e far
     *      terminare il thread timer tramite
     *      la variabile "uscita_timer"
     */
    m->uscita_timer = 1;
    pthread_mutex_destroy(&m->mutex);
    pthread_cond_destroy(&m->cvprod);
    pthread_cond_destroy(&m->cvcons);
}

int produci(MonitorProdCons * m, int val) {

    /* TBD: Introdurre la sincronizzazione */

    pthread_mutex_lock(&m->mutex);


    struct timeval t1;
	gettimeofday(&t1,NULL);
    long start_time = t1.tv_sec*1000000 + t1.tv_usec;



    struct timeval t2;
	gettimeofday(&t2,NULL);
    long current_time = t2.tv_sec*1000000 + t2.tv_usec;

    if(current_time - start_time >= 3000000) {
        printf("[MONITOR] Produttore ha atteso oltre 3 secondi, esce\n");
        /* TBD: Il metodo esce dal monitor senza porsi nuovamente 
                in attesa sulla condition variable, e ritorna in uscita
                un valore negativo
         */

        pthread_mutex_unlock(&m->mutex);
        
        return -1;
    }

    while(m->count == DIM)
        pthread_cond_wait(&m->cvprod, &m->mutex);

    m->buffer[m->testa] = val;
    m->testa = (m->testa+1)%DIM;
    m->count++;

    printf("[MONITOR] Produzione %d\n", val);

    pthread_cond_signal(&m->cvcons);

    pthread_mutex_unlock(&m->mutex);

    return 0;
}

int consuma(MonitorProdCons * m, int * val) {

    /* TBD: Introdurre la sincronizzazione */

    pthread_mutex_lock(&m->mutex);

    struct timeval t1;
	gettimeofday(&t1,NULL);
    long start_time = t1.tv_sec*1000000 + t1.tv_usec;


    struct timeval t2;
	gettimeofday(&t2,NULL);
    long current_time = t2.tv_sec*1000000 + t2.tv_usec;
    
    if(current_time - start_time >= 3000000) {
        printf("[MONITOR] Consumatore ha atteso oltre 3 secondi, esce\n");
        /* TBD: Il metodo esce dal monitor senza porsi nuovamente 
                in attesa sulla condition variable, e ritorna in uscita
                un valore negativo
         */

        pthread_mutex_unlock(&m->mutex);

        return -2;
    }

    while(m->count == 0)
        pthread_cond_wait(&m->cvcons, &m->mutex);

    *val = m->buffer[m->coda];
    m->coda = (m->coda+1)%DIM;
    m->count--;

    printf("[MONITOR] Consumazione %d\n", *val);

    pthread_cond_signal(&m->cvprod);

    pthread_mutex_unlock(&m->mutex);

    return 0;
}

void * thread_timer(void * p) {

    printf("[MONITOR] Avvio thread timer\n");

    MonitorProdCons* m = (MonitorProdCons*)p;

    while(1) {

        int uscita = 0;

        sleep(1);

        /* TBD: Il thread timer periodicamente attiva tutti i thread sospesi */
        pthread_cond_signal(&m->cvprod);
        pthread_cond_signal(&m->cvcons);
        uscita = m->uscita_timer;

        if(uscita != 0) {
            break;
        }
    }

    printf("[MONITOR] Uscita thread timer\n");

    pthread_exit(NULL);
}