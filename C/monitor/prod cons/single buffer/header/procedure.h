#ifndef PROCEDURE_H
#define PROCEDURE_H

#include "../header/monitor_signal_continue.h"

#define COND_VAR_PROD 0
#define COND_VAR_CONS 1

typedef int T;

typedef struct prod_cons{
    T val;
    int is_full;
    Monitor monitor;
} Buffer;


void produce(Buffer*, int val);
int consume(Buffer*);


#endif