#include "../header/procedure.h"
#include "../header/monitor_signal_continue.h"

void produce(Buffer* buf, T val)
{
    enter_monitor(&(buf->monitor));

    if(buf->is_full)
        wait_condition(&(buf->monitor), COND_VAR_PROD);

    buf->val = val;
    buf->is_full = 1;

    signal_condition(&(buf->monitor), COND_VAR_CONS);

    leave_monitor(&(buf->monitor));
}

int consume(Buffer* buf)
{
    T val;
    
    enter_monitor(&(buf->monitor));
    
    while(!(buf->is_full))
        wait_condition(&(buf->monitor), COND_VAR_CONS);
    
    val = buf->val;
    buf->is_full = 0;

    signal_condition(&(buf->monitor), COND_VAR_PROD);

    leave_monitor(&(buf->monitor));

    return val;
}