#include "header.h"
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

int coda_risultati;
int coda_RTS;
int coda_OTS;

void initServiceQueues(){

    /* TODO: Inizializzazione code di servizio */
    coda_RTS = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    printf("Coda di servizio coda_RTS create con desc: %d\n", coda_RTS);
    
    coda_OTS = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    printf("Coda di servizio coda_OTS create con desc: %d\n", coda_OTS);
}

void removeServiceQueues()
{    
    /* TODO: rimozione code di servizio */
    msgctl(coda_risultati, IPC_RMID, NULL);
    msgctl(coda_RTS, IPC_RMID, NULL);
    msgctl(coda_OTS, IPC_RMID, NULL);
}

// Send Sincrona
void inserisci_risultato (Risultato *m , int queue)
{   
    /* TODO: Implementare il protocollo per la send sincrona e inviare il messaggio
     * per l'inserimento del risultato
     */

	Risultato buf_RTS, buf_OTS;
	buf_OTS.type = OTS;

	msgsnd(coda_RTS, &buf_RTS, sizeof(Risultato)-sizeof(long), 0);
	msgrcv(coda_OTS, &buf_OTS, sizeof(Risultato)-sizeof(long), OTS, 0); //recieve bloccante
	msgsnd(coda_ris, &m, sizeof(Risultato)-sizeof(long), 0);
}

// Receive Bloccante
int preleva_risultato(Risultato *m, int queue, int tipomess)
{
    /* TODO: Implementare il protocollo per la send sincrona e ricevere il messaggio
     * per il prelevamento del risultato
     */
    
	Risultato buf_RTS, buf_OTS;
	buf_RTS.type = RTS;

	msgrcv(coda_RTS, &buf_RTS, sizeof(Risultato)-sizeof(long), RTS, 0); //recieve bloccante
	msgsnd(coda_OTS, &buf_OTS, sizeof(Risultato)-sizeof(long), 0);
	msgrcv(coda_ris, &m, sizeof(Risultato)-sizeof(long), RIS, 0); //recieve bloccante

    return m->mess;
}

void inserisci_operando(MonitorOperandi * m, int operando)
{
    /* TODO: Implementare la sincronizzazione richiesta tramite monitor
     * gestendo opportunamente la produzione degli operandi
     */

	//startprod:

	pthread_mutex_lock(&m->mutex);

	while(m->count == DIM_BUFFER){
		//printf("[DEBUG] - Buffer pieno\n");
		pthread_cond_wait(&m->cvprod, &m->mutex);
	}

	//prod:

	m->operandi[m->testa] = operando;
	m->testa = (m->testa+1)%DIM_BUFFER;
	m->count++;

	//endprod:

	pthread_cond_signal(&m->cvcons);

	pthread_mutex_unlock(&m->mutex);

}

int * preleva_operando(MonitorOperandi * m){

    static int operando[2];
    /* TODO: Implementare la sincronizzazione richiesta tramite monitor
     * gestendo opportunamente la consumazione degli operandi
     */

	//startcons:
	
	pthread_mutex_lock(&m->mutex);
	
	while (m->count == 0){
		//printf("[DEBUG] - Buffer vuoto\n");
		pthread_cond_wait(&m->cvcons, &m->mutex);
	}
	
	//cons:

	for (int i = 0; i < 2; i++){
		operando[i] = m->operandi[m->coda];
		m->coda = (m->coda+1)%DIM_BUFFER;
		m->count--;
	}

	//endcons:

	pthread_cond_signal(&m->cvprod);
	
	pthread_mutex_unlock(&m->mutex);

    return operando;
}

void * genera_operandi(void *m)
{
    int i, op;
    MonitorOperandi * mon = (MonitorOperandi*)m;

    for (i = 0; i < 6; i++){
        // call inserisci_operando generato da 1 a 10
        op = 1 + rand() % 10;
        //printf("[thread genera_operandi] Operando generato: %d\n", op);
        inserisci_operando(mon, op);
    }

    pthread_exit(0);
}

void preleva_risultati(int coda_risultati)
{
    int i, risultato, less = 0, great = 0;

    Risultato msg;

    for(i = 0; i < 6; i++){
    	//risultato = preleva_risultato(mon);
        risultato = preleva_risultato(&msg, coda_risultati, RIS);
        printf("[processo preleva_risultati] Risultato prelevato: %d coda: %d\n", risultato, coda_risultati);
    
		risultato <= 25 ? ++less : ++great; // ù_ù
    }

    printf("[processo preleva_risultati] STATS: Conteggio minore uguale: risultato: %d\n", less);
    printf("[processo preleva_risultati] STATS: Conteggio maggiore: %d\n", great);
    exit(0);
}


void * calcola(void *mon)
{
    int i, calc;
    int *op;
    MonitorOperandi * mon_op = (MonitorOperandi*)mon;

    Risultato msg; //messaggio da inviare

    for (i = 0; i < 2; i++){
        // preleva operando
        op = preleva_operando(mon_op);
        int op1 = *op;
        int op2 = *(op+1);
        printf("[thread calcola] Preleva op1: %d op2: %d\n", op1, op2);
        
		// calcola
        calc = (op1*op1) + (op2*op2);
        printf("[thread calcola] Calcola somma dei quadrati (%d x %d) + (%d x %d) = %d\n", op1, op1, op2, op2, calc);
        
		// inserisci risultato
        printf("[thread calcola] Inserisci risultato: %d tramite send sincrona su coda: %d\n", calc, coda_risultati);
        sleep(1);
    
        /* TODO: Impostare il messaggio da inviare */
		msg.type = RIS;
		msg.mess = calc;
        inserisci_risultato(&msg , coda_risultati);
    }

    pthread_exit(0);
}
