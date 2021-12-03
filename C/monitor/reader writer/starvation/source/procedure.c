#include "../header/procedure.h"

int read(Buffer* buf)
{
    int val;

    enter_monitor(&(buf->monitor));

    while (buf->nwriter > 0){
        printf("Reading suspended\n");
        wait_condition(&(buf->monitor), VAR_COND_READER);
        printf("Reading resumed\n");
    }

    buf->nreader++;

    leave_monitor(&(buf->monitor));

    sleep(2);

    val = buf->buffer;
    printf("Value read: %d", val);

    enter_monitor(&(buf->monitor));

    buf->nreader--;

    if(buf->nreader == 0)
        signal_condition(&(buf->monitor), VAR_COND_WRITER);

    leave_monitor(&(buf->monitor));

    return val;
}

void write(Buffer* buf, int val)
{
    enter_monitor(&(buf->monitor));

    while(buf->nreader > 0 || buf->nwriter > 0){
        printf("Writing suspended\n");
        wait_condition(&(buf->monitor), VAR_COND_WRITER);
        printf("Writing resumed\n");
    }
    
    buf->nwriter++;

    leave_monitor(&(buf->monitor));

    sleep(1);
    
    buf->buffer = val;
    printf("Value written: %d\n", val);

    enter_monitor(&(buf->monitor));

    buf->nwriter--;

    if(queue_condition(&(buf->monitor), VAR_COND_WRITER))
        signal_condition(&(buf->monitor), VAR_COND_WRITER);
    else
        signal_all(&(buf->monitor), VAR_COND_READER);

    
    leave_monitor(&(buf->monitor));
}














