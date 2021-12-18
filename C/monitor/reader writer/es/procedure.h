#include "monitor_hoare.h"

#define NUM_USERS 10
#define NUM_CONDITIONS 2
#define DEFAULT 0

#define SYNCHR 0
#define SYNCHW 1

typedef struct {
	int temp;
	unsigned int humidity;
	unsigned short rain;
} weather_t;

typedef struct {
	weather_t weather;
	
	/* TBD: aggiungere qui le variabili di stato per la sincronizzazione */
	int readers;
	int writers;
} Buffer;


void init_buffer(Buffer*);
void startr(Monitor*, Buffer*);
void endr(Monitor*, Buffer*);
void startw(Monitor*, Buffer*);
void endw(Monitor*, Buffer*);

void Servizio(Monitor* m, Buffer * buf);
void Utente(Monitor* m, Buffer * buf);
