#include "../../sem/header/sem.h"

#include <sys/types.h>

#define DIMBUF 80

enum sems{
    MUTEXC,          // per accedere in competizione alla variabili di stato
    CLIENTE,
    VISUAL         // per accedere in cooperazione alla risorsa condivisa
};

enum status_flags{
    LIBERO,
    OCCUPATO,
    IN_AGGIORNAMENTO
};

typedef struct {
    unsigned int id_cliente;
    unsigned int stato;
} posto;

typedef struct buf_teatro{
    posto posti[DIMBUF];
    int disponibili;
} teatro;

typedef struct variabile_pigra{ // ù_ù
    key_t key;
    id_t id;
} pig;

void prenota(teatro*, int nposti, int sem_id);
