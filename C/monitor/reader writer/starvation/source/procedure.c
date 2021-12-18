#include "../header/procedure.h"

void startr(Buffer* buf)
{
    enter_monitor(&buf->monitor);

    while(buf->nwriters > 0)
        waitcond(&buf->monitor, VAR_COND_READER);
    
    buf->nreaders++;
    
    leave_monitor(&buf->monitor);
}

T read(Buffer* buf)
{
    T val;
    
    startr(buf);

    sleep(2);
    val = buf->buffer;
    printf("Value read: %d", val);

    endr(buf);

    return val;
}

void endr(Buffer* buf)
{
    enter_monitor(&buf->monitor);

    buf->nreaders--;
    if(buf->nreaders == 0)
        signalcond(&buf->monitor, VAR_COND_WRITER);

    leave_monitor(&buf->monitor);
}

void startw(Buffer* buf)
{
    enter_monitor(&buf->monitor);

    while(buf->nreaders > 0 || buf->nwriters > 0)
        waitcond(&buf->monitor, VAR_COND_WRITER);
    
    buf->nwriters++;

    leave_monitor(&buf->monitor);
}

void write(Buffer* buf, int val)
{
	startw(buf);

	sleep(1);
	buf->buffer = val;
	printf("Value written: %d\n", val);

	endw(buf);
}

void endw(Buffer* buf)
{
    enter_monitor(&buf->monitor);

    buf->nwriters--;
	if(queueconds(&(buf->monitor), VAR_COND_WRITER)) //&buf->monitor.condcounts[VAR_COND_WRITER] > 0
        signalconds(&(buf->monitor), VAR_COND_WRITER);
    else
        signalall(&(buf->monitor), VAR_COND_READER);

	leave_monitor(&buf->monitor);
}













