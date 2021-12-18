#include "../header/procedure.h"

void produce(buffer* buf, value srcval, int semid)
{
    waitsem(semid, SPACE_AVAIL);

    waitsem(semid, MUTEX_P);
    
    int index = 0;
    while(index < BUFSIZE && buf->status[index] != EMPTY)
        ++index;
    
    buf->status[index] = IN_USE;

    signalsem(semid, MUTEX_P);

    sleep(2);
    buf->values[index] = srcval;
    buf->status[index] = FULL;

    signalsem(semid, VALUE_AVAIL);
}

value consumer(buffer* buf, int semid)
{
    waitsem(semid, VALUE_AVAIL);

    waitsem(semid, MUTEX_C);
    
    int index = 0;
    while(index < BUFSIZE && buf->status[index] != FULL)
        ++index;

    buf->status[index] = IN_USE;
    
    signalsem(semid, MUTEX_C);

    sleep(2);
    value v = buf->values[index];
    buf->status[index] = EMPTY;

    signalsem(semid, SPACE_AVAIL);
}

void consumer(buffer* buf, value* srcval, int semid)
{
    waitsem(semid, MUTEX_C);
    
    int index = 0;
    while(index < BUFSIZE && buf->status[index] != FULL)
        ++index;

    buf->status[index] = IN_USE;

    signalsem(semid, MUTEX_C);

    sleep(2);
    *srcval = buf->values[index];
    buf->status[index] = EMPTY;

    signalsem(semid, SPACE_AVAIL);
}