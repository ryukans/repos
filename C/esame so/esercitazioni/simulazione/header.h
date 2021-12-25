#include <pthread.h>

#ifndef HEADER_H
#define HEADER_H

#define DIM_BUFFER 5

/* TODO: Definire le macro per la comunicazione su coda sincrona */
enum sync_msgq_types{
    RTS,    //messagio tipo -request to send-
    OTS,    //messaggio tipo -okay to send-
    RIS     //messaggio tipo -risultato-
};

extern int coda_ris;
extern int coda_RTS;
extern int coda_OTS;


typedef struct {
    
    // pool di buffer condivisi
    int operandi[DIM_BUFFER];
    
    int testa;
    int coda;
    int count;

    /* TODO: Aggiungere le variabili necessarie per la sincronizzazione */
    pthread_mutex_t mutex;
    pthread_cond_t  cvprod;
    pthread_cond_t  cvcons;
     
} MonitorOperandi;


typedef struct {
    /* TODO: Definire la struttura messaggio */
    long type;
    int mess;
} Risultato;

void inserisci_operando(MonitorOperandi * mo, int operando);
int *preleva_operando(MonitorOperandi * mo);

void inserisci_risultato(Risultato *m , int queue);
int preleva_risultato(Risultato *m, int queue, int tipomess);

void * genera_operandi(void *);
void * calcola(void *);
void preleva_risultati(int);

void initServiceQueues();
void removeServiceQueues();
    
#endif

