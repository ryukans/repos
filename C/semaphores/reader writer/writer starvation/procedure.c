#include "procedure.h"
#include <stdio.h>

void init_buffer(buffer* buf)
{
    buf->nreaders = 0;
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
}

void writer(buffer* buf, mess_t src_mess, id_t semid)
{
    waitsem(semid, SYNCHRW);

    sleep(1);
    buf->mess = src_mess;

    signalsem(semid, SYNCHRW);
}