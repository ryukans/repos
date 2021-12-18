#include "../../sem/header/sem.h"
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>

#define DEFAULT 0
#define PATHNAME "."
#define SHMID 'A'
#define SEMID 'B'
#define NSEMS 2

enum sems{
    MUTEXL, //mutex lettori per accedere alla variabile di conteggio
    SYNCHRW //semaforo per la cooperazione lettori e scrittori
};

typedef struct message{
    int val1;
    int val2;
} mess_t;

typedef struct{
    mess_t mess;
    int readers;
} buffer;

typedef struct{
    key_t key;
    int id;    
} ipc;


void init_buffer(buffer*);