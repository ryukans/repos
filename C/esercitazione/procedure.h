#ifndef _PROCEDURE_H_
#define _PROCEDURE_H_

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#define SIZE 15 // capacità massima 

enum exit {
    EXIT_GENERATORE = 1,
    EXIT_ELABORATORE,
    EXIT_ANALIZZATORE
};

typedef struct {
    int numlettori;
    char line[SIZE];
    int index;
    int riemp; //riempimento
} buffer;


//lettori
void elabora(buffer* buf);
void analizza(buffer* buf);

//scrittore
void genera(int sem, buffer* buf);

void iniziolettra(int sem, buffer* buf);
void finelettura(int sem, buffer* buf);
void inizioscrittura(int sem);
void finescrittura(int sem);


void iniziolettura(int sem, Buffer* buf)
{
    
    waitsem(sem, MUTEXL); 

    buf->numlettori = buf->numlettori + 1;
    
    if (buf->numlettori == 1) //se si tratta del primo lettore blocca gli scrittori
        waitsem(sem, SYNCH);
    
    signalsem(sem, MUTEXL); //Rilascia il mutex per far entrare altri lettori
}

void finelettura(int sem, Buffer* buf)
{
    waitsem(sem, MUTEXL); 

    buf->numlettori = buf->numlettori - 1;
    
    if (buf->numlettori == 0) //se sono l'ultimo lettore devo rilasciare la risorsa per gli scrittori
        signalsemsem, SYNCH);
    
    signalsem(sem, MUTEXL); //rilascio il mutex per altri lettori
}

void inizioscrittura(int sem){
	waitsem(sem, SYNCH);
}

void finescrittura (int sem){
	signalsem(sem, SYNCH);
}

#endif