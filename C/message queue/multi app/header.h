#pragma once
#include <sys/types.h>

#define QUEUEPATH "."
#define QUEUEID 'Q'
#define NUMMESS 11

enum {P1 = 1, P2};

typedef float T;

typedef struct message{
    long id_proc;
    T value;
} mess_t;

typedef struct inter_process_comm{
    key_t key;
    int id;
}ipc;

// generate value of type T on the intervall [i_sx, i_dx]
T genval(int i_sx, int i_dx);
