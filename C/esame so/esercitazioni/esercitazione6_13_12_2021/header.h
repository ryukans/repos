#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>


struct monitor {

	int molo; //posizione
	int id_nave;

	/* TODO: Aggiungere variabili per la sincronizzazione */
    
	pthread_mutex_t mutex;
	pthread_cond_t	cvlett;
	pthread_cond_t	cvscritt;

	int nlett;	// numero lettori;
	int nscritt;// numero scrittori;
	int nwaitlett; // numero scrittori in attesa
	int nwaitscritt; // numero lettori in attesa
};

void inizializza(struct monitor * m);
void rimuovi (struct monitor * m);

void inizio_scrittura(struct monitor * m);
void fine_scrittura(struct monitor * m);
void scrivi_molo(struct monitor * m, int molo);

void inizio_lettura(struct monitor * m);
void fine_lettura(struct monitor * m);
int leggi_molo(struct monitor * m);



#endif
