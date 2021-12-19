#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "header.h"
#include <math.h>

//Procedure per la sincronizzazione sui semafori

void waitsem(int semid, int semnum)
{
	struct sembuf buf;
	
	buf.sem_flg = 0;
	buf.sem_num = semnum;
	buf.sem_op = -1;
	
	if(semop(semid, &buf, 1)){
		printf("Error semop() in waitsem()\n");
		exit(1);
	}
}

void waitnsem(int semid, int semnum, int nops)
{
	struct sembuf buf;
	
	buf.sem_flg = 0;
	buf.sem_num = semnum;
	buf.sem_op = -nops;
	
	if(semop(semid, &buf, 1)){
		printf("Error semop() in waitsem()\n");
		exit(1);
	}
}

void signalsem(int semid, int semnum)
{
	struct sembuf buf;
	
	buf.sem_flg = 0;
	buf.sem_num = semnum;
	buf.sem_op = 1;
	
	if(semop(semid, &buf, 1)){
		printf("Error semop() in waitsem()\n");
		exit(1);
	}
}

void signalnsem(int semid, int semnum, int nops)
{ 
	struct sembuf buf;
	
	buf.sem_flg = 0;
	buf.sem_num = semnum;
	buf.sem_op = nops;
	
	if(semop(semid, &buf, 1)){
		printf("Error semop() in waitsem()\n");
		exit(1);
	}
}


//Calcolo statistiche
double media(int* v){
	int i;
	double somma;
	somma = 0.0f;
	for(i = 0; i < N;i++){
		somma += v[i];
	}
	return (double)(somma/N);
}

double var(int* v,double media){
	int i;
	double somma_par,temp;
	somma_par = 0.0f;
	for(i = 0; i < N;i++){
		temp = v[i]*v[i];
		somma_par += (temp - media);
	}
	return (double)(somma_par/N-1);
}

// Consumo
void consuma_elementi(int sem, Buffer* buf)
{
	int val[N];
	double m;
	//Calcola media e varianza
	/*Qua va il codice della sincronizzazione*/	
	
	/*
	for(int i = 0; i < N; i++)
		waitsem(sem, CONS);
	*/

	waitnsem(sem, CONS, N);
	
	for(int i = 0; i < N; i++){
		val[i] = buf->elementi[buf->coda];
		//buf->coda = (buf->coda+1)%N;
		//buf->nelem--;
	}
	
	//buf->nelem = 0;

	signalnsem(sem, PROD, N);
	
	/*
	for(int i = 0; i < N; i++)
		signalsem(sem, PROD);*/
	
	printf("[Consumatore %d] consumo elementi\n",getpid());	
	m = media(val);
	printf("[Consumatore %d] media %f, varianza %f\n",getpid(),m,sqrt(var(val,m)));	
}

//Produzione
void produci_elemento(int sem, Buffer* buf)
{
	int val;
	val = (1+rand()%11);
	
	waitsem(sem, PROD);

	waitsem(sem, MUTEXP);
	
	buf->elementi[buf->testa] = val;
	buf->testa = (buf->testa+1)%N;
	
	signalsem(sem, MUTEXP);

	signalsem(sem, CONS);
	
	printf("[Produttore %d] ho prodotto %d in posizione %d\n",getpid(),val,buf->testa);
}
