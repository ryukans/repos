#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void inserisci(buffer* buf, int* nscorte, int val)
{
    monitor_mutex_lock(&buf->m);

    if(*nscorte == NUM_ELEM){
        printf("[FORNITORE] - non ci sono scorte in magazzino\n");
        monitor_cond_wait(&buf->m, CV_PROD);
    }
    
    int i = 0;
    while(i < NUM_ELEM && buf->magazzino[i].stato != LIBERO)
        ++i;

    buf->magazzino[i].stato = IN_USO;
    
    monitor_mutex_unlock(&buf->m);

    sleep(2);
    printf("Fornitura effettuata %d\n", val);
    buf->magazzino[i].id = val;

    monitor_mutex_lock(&buf->m);

    buf->magazzino[i].stato = OCCUPATO;
    (*nscorte)++;

    monitor_cond_signal(&buf->m, CV_CONS);

    //monitor_mutex_unlock(&buf->m);
}

int preleva(buffer* buf, int* nscorte)
{
    monitor_mutex_lock(&buf->m);

    if((*nscorte) == 0){
        printf("[FORNITORE] - non ci sono scorte in magazzino\n");
        monitor_cond_wait(&buf->m, CV_CONS);
    }

    int i = 0;
    while(i < NUM_ELEM && buf->magazzino[i].stato != OCCUPATO)
        ++i;

    buf->magazzino[i].stato = IN_USO;

    monitor_mutex_unlock(&buf->m);
    
    sleep(2);
    int val = buf->magazzino[i].id;
    printf("Merce prelevata, %d\n", val);
    buf->magazzino[i].id = 0;

    monitor_mutex_lock(&buf->m);

    (*nscorte)--;
    buf->magazzino[i].stato = LIBERO;

    monitor_cond_signal(&buf->m, CV_PROD);

}