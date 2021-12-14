#include "monitor.h"

void init_monitor(monitor* m)
{
    pthread_mutex_init(&m->mutex, NULL);
    pthread_cond_init(&m->cvinsert, NULL);
    pthread_cond_init(&m->cvremove, NULL);    
}

void destroy_monitor(monitor* m)
{
    pthread_mutex_destroy(&m->mutex);
    pthread_cond_destroy(&m->cvinsert);
    pthread_cond_destroy(&m->cvremove);
}

