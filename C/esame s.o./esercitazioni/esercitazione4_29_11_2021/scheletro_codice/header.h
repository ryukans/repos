#define MSG_TYPE 1
#define STRING_MAX_DIM 11
#define INT_MAX_DIM 2


#define NUM_FILTER 1
#define NUM_CHECKSUM 1
#define NUM_VISUAL 1

#define NUM_GENERATORS 4
#define DIM_QUEUE 4
#define VARCOND_GEN_PRODUTTORI 0
#define VARCOND_GEN_CONSUMATORI 1

#define NUM_MESSAGES 8


#include "monitor_signal_continue.h"

typedef struct {
        
    /* TODO: Definire il messaggio */
    long type;
    char string[STRING_MAX_DIM];
    int intarray[INT_MAX_DIM];
    int var;

} message;

typedef struct ProdConsGen {
    
    /* TODO: Definire le variabili per la sincronizzazione dei processi generatori prod/cons */
    message msg[DIM_QUEUE]; //coda di messaggi
    int testa;
    int coda;
    int count;
    Monitor monitor;

} Buffer;

void generatore_produttore(Buffer *);
void generatore_consumatore(Buffer *,  int);

void filtro(int, int);
void checksum(int , int);
void visualizzatore(int);
