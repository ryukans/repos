#include "monitor.h"

#define NUM_ELEM 100
#define N_CV 2

enum cond_vars{
    CV_PROD,
    CV_CONS
};

enum status_flag{
    LIBERO,
    IN_USO,
    OCCUPATO
};

typedef struct{
    unsigned int id;
    unsigned int stato;
}scaffale;

typedef struct{
    scaffale magazzino[NUM_ELEM];

    monitor m;
} buffer;

void inserisci(buffer*, int* nscorte, int val);
int preleva(buffer*, int* nscorte);