#include "../../sem/header/sem.h"

#define DIMBUF 80

enum sems{
    MUTEXC,
    CLIENTE,
    VISUAL
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
    int key;
    int id;
} pig;

void prenota(teatro*, int nposti, int sem_id);
