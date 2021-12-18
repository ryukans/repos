#include "procedure.h"

void init_buffer(buffer* buf)
{
    buf->nreaders = buf->nwriters = 0;
    buf->mess = DEFAULT;
}

mess_t _read(buffer* buf, id_t semid)
{
    mess_t mess;

    waitsem(semid, MUTEXR);

    buf->nreaders++;
    if(buf->nreaders == 1)
        waitsem(semid, SYNCHRW);

    signalsem(semid, MUTEXR);

    sleep(1);
    mess = buf->mess;

    waitsem(semid, MUTEXR); 

    buf->nreaders--;
    if(buf->nreaders == 0)
        signalsem(semid, SYNCHRW);

    signalsem(semid, MUTEXR);
    
    return mess;
}

void write(buffer* buf, mess_t src, id_t sem)
{
    waitsem(sem, MUTEXW);

    buf->nwriters++;
    if(buf->nwriters == 1)
        waitsem(sem, SYNCHRW);

    signalsem(sem, MUTEXW);

    waitsem(sem, MUTEX);
    
    sleep(1);
    buf->mess = src;

    signalsem(sem, MUTEX);

    waitsem(sem, MUTEXW);

    buf->nwriters--;
    if(buf->nwriters == 0)
        signalsem(sem, SYNCHRW);

    signalsem(sem, MUTEXW);
}
