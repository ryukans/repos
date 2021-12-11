#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include "header.h"

#define NUM_WORKER 3

static int coda;
static pthread_t threads[NUM_WORKER+1];


// struttura per il passaggio dei parametri ai thread worker
typedef struct {
	int id;
	Buffer* b;
} parametri;

void init_buffer(Buffer* b){
	//TODO inizializzazione del buffer
	pthread_mutex_init(&b->mutex, NULL);
	pthread_cond_init(&b->prelievo, NULL);
	b->somma = 0;
	b->count = 0;

	printf("[SERVER] - Buffer inizializzato...\n");
}

void remove_buffer(Buffer* b){
	//TODO distruzione delle variabili de buffer
	pthread_mutex_destroy(&b->mutex);
	pthread_cond_destroy(&b->prelievo);

	printf("[SERVER] - Buffer distrutto...\n");
}


void aggiorna_somma(Buffer* b, int somma_parziale){
	// TODO aggiungere la somma parziale alla somma nel buffer,
	//		risvegliando il prelievo della somma finale quando necessario...
	
	pthread_mutex_lock(&b->mutex);

	b->somma+=somma_parziale;
	b->count++;
	
	if(b->count == NUM_WORKER*NUM_REQ)
		pthread_cond_signal(&b->prelievo);

	pthread_mutex_unlock(&b->mutex);
}

int preleva_somma_finale(Buffer* b){
	int somma_finale;
	//TODO prelevare la somma finale dal buffer, 
	// 		solo quando sono state accumulati NUM_WORKER*NUM_REQ incrementi
	
	pthread_mutex_lock(&b->mutex);

	while(b->count != NUM_WORKER*NUM_REQ){
		//printf("[DEBUG] - count %d < 30\n", b->count);
		pthread_cond_wait(&b->prelievo, &b->mutex);
	}

	somma_finale = b->somma;
	printf("[COLLECTOR] somma finale %d\n", somma_finale);
	pthread_mutex_unlock(&b->mutex);

	return somma_finale;
}

void* collector(void* arg){
	int somma_finale;
	float media;

	// TODO recupera l'argomento
	Buffer* b = (Buffer*)arg;

	printf("[COLLECTOR] - start del thread...\n");

	// TODO preleva la somma chiamando preleva_somma_finale
	somma_finale = preleva_somma_finale(b);
	
	media = (float)somma_finale/(NUM_WORKER*NUM_REQ); //TODO calcola la media sul totale delle misure ricevute
	
	printf("[COLLECTOR] - somma finale: %d media: %f\n",somma_finale,media);
	
	pthread_exit(NULL);
}

void *worker(void* arg){

	printf("[WORKER] - start del thread...\n");

	//TODO recupera i parametri
	parametri* p = (parametri*)arg;

	Misura m;
	//TODO ogni worker preleva NUM_REQ messaggi relativi ad un certo client id 
	//     e per ogni messaggio ricevuto aggiorna la somma chiamando aggiorna_somma

	int i;
	long msgtype = (long)p->id;
	printf("[WORKER] - reciving messages id: %ld \n", msgtype);

	for(i = 0; i < NUM_REQ; i++){
		msgrcv(coda, (void*)&m, sizeof(Misura)-sizeof(long), msgtype, 0);
		printf("[WORKER] - message %d id: %ld recived\n", i, msgtype);
		aggiorna_somma(p->b, m.val);
	}


	pthread_exit(NULL);
}

int main(){

	int i,status;
	pid_t pid;

	pthread_attr_t attr;
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr,PTHREAD_CREATE_DETACHED);

	key_t key;
	key = ftok(".", 'A');
    
	coda = msgget(key, IPC_CREAT | 0664);

	printf("[SERVER] - id coda %d\n",coda);


	//Inizializziamo strutture
	
	Buffer* b = (Buffer*)malloc(sizeof(Buffer));
	init_buffer(b);
	
	//parametri* arg = (parametri*)malloc(sizeof(parametri)*NUM_WORKER);
	//arg->b = b;
	//arg->id = 0;

	parametri arg[NUM_WORKER];

	//parametri arg;
	//arg.b = b;
	
	//Avvio dei thread
	for(i = 0; i < NUM_WORKER+1; i++){

		printf("[MASTER] - creo thread %d...\n",i);

		// TODO creazione di 1 trhead collector e 3 thread worker (ai quali passare anche l'id)
		if(i == 0){
			//sleep(1);
			pthread_create(&threads[i], &attr, collector, (void*)b);
		}
		else{
			//sleep(2);
			arg[i].b = b;
			arg[i].id = i;
			printf("[DEBUG] arg->id = %d\n", i);
			pthread_create(&threads[i], &attr, worker, (void*)&arg[i]);
		}
	}

	printf("[MASTER] - bye bye...\n");
	pthread_attr_destroy(&attr);
	remove_buffer(b);
	free(b);
	
	pthread_exit(NULL);

    return 0;
}

