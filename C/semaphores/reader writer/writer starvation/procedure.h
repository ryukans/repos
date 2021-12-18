#pragma once

#include "../../sem/header/sem.h"
#include <sys/types.h>

#define DEFAULT 0
#define NSEMS 2

enum sems{
    MUTEXR, //readers mutex to access status variable -nreaders-
    SYNCHRW //synch for cooperation between reader and writer
};

typedef long mess_t;

typedef struct{
    mess_t mess;
    int nreaders;
} buffer;

typedef struct ipc_type{
    key_t key;
    id_t id;
} ipc;


void init_buffer(buffer*);
mess_t _read(buffer*, id_t semid);
void write(buffer*, mess_t, id_t semid);