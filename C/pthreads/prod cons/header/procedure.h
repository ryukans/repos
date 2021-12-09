#include <pthread.h>

#ifndef _PROCEDURE_H
#define _PROCEDURE_H
 
typedef long msg;

typedef struct prodcons {
    pthread_mutex_t mutexm;
    
    pthread_cond_t cvprod;
    pthread_cond_t cvcons;

    int okprod;
    int okconsume;

    msg data;
} Buffer;

void* consumer(void* arg);
void* producer(void* arg);

void produce(Buffer*, msg);
msg consume(Buffer*);

void startprod(Buffer*);
void startcons(Buffer*);
void endprod(Buffer*);
void endcons(Buffer*);

#endif