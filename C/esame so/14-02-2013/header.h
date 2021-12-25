#pragma once

#include "sem.h"
#include <sys/types.h>

#define MAXSIZE 20
#define PATHNAME "."
#define SHMID 'A'
#define SEMID 'B'
#define NSEMS 2

enum sem{
    SYNCHDC,     // Synch Mutex Docente Studente
    MUTEXL,      // Mutex Lettura 
    MUTEXP       // Mutex Prenotati
};

typedef struct messaggio{
    char data[MAXSIZE];
    int prenotati;
}appello_t;

typedef struct segrepass{
    appello_t appello;
    int studenti; //numlettori   
}buffer;

typedef struct{
    key_t key;
    int id;    
}ipc;