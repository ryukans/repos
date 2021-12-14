#pragma once

#include <pthread.h>

typedef struct monitor {
    pthread_mutex_t mutex;
    pthread_cond_t  cvinsert;
    pthread_cond_t  cvremove;
} monitor;


void init_monitor(monitor* m);
void destroy_monitor(monitor* m);

