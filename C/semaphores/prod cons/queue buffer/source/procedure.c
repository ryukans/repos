#include "../header/procedure.h"

void init_buffer(buffer* buf)
{
    buf->head = buf->tail = 0;
    for (int i = 0; i < BUFSIZE; i++)
        buf->values[i] = 0;
}

void produce(buffer* buf, value srcval, int sem_id)
{
    waitsem(sem_id, SPACE_AVAIL);
    
    waitsem(sem_id, MUTEX_P);

    //sleep(rand()%5); simulate slow process
    buf->values[buf->head] = srcval;
    buf->head = (buf->head+1)%BUFSIZE;

    signalsem(sem_id, MUTEX_P);

    signalsem(sem_id, VALUE_AVAIL);
}

int consume(buffer* buf, int sem_id)
{
    waitsem(sem_id, VALUE_AVAIL);

    waitsem(sem_id, MUTEX_C);

    value v;

    //sleep(rand()%3); //simulate slow process
    v = buf->values[buf->tail];
    buf->tail = (buf->tail+1)%BUFSIZE;   

    signalsem(sem_id, MUTEX_C);

    signalsem(sem_id, SPACE_AVAIL);

    return v;
}


int consumep(buffer* buf, value* val, int sem_id)
{
    waitsem(sem_id, VALUE_AVAIL);

    waitsem(sem_id, MUTEX_C);

    *val = buf->values[buf->tail];
    buf->tail = (buf->tail+1)%BUFSIZE;   

    signalsem(sem_id, MUTEX_C);

    signalsem(sem_id, SPACE_AVAIL);
}