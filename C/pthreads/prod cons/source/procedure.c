#include <stdio.h>
#include <sys/time.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include "../header/procedure.h"

void startcons(Buffer* buf)
{
    pthread_mutex_lock(&(buf->mutexm));

    while(!buf->okconsume)
        pthread_cond_wait(&(buf->cvcons), &(buf->mutexm));
}

void endcons(Buffer* buf)
{
    buf->okprod = 1;
    buf->okconsume = 0;

    pthread_cond_signal(&(buf->cvprod));

    pthread_mutex_unlock(&(buf->mutexm));
}

void startprod(Buffer* buf)
{
    pthread_mutex_lock(&(buf->mutexm));

    while(!buf->okprod)
        pthread_cond_wait(&(buf->cvprod), &(buf->mutexm));
}

void endprod(Buffer* buf)
{
    buf->okconsume = 1;
    buf->okprod = 0;

    pthread_cond_signal(&(buf->cvcons));

    pthread_mutex_unlock(&(buf->mutexm));
}

void produce(Buffer* buf, msg val)
{
    startprod(buf);

    buf->data = val;
    u_int64_t id;
    //pthread_threadid_np(NULL, &id);
    id = syscall(SYS_gettid);
    printf("Thread #%lu produced: [%ld]\n", id, buf->data);

    endprod(buf);
}

msg consume(Buffer* buf)
{
    msg m;
    
    startcons(buf);

    u_int64_t id;
    id = syscall(SYS_gettid);
    printf("Thread #%lu consumed: [%ld]\n", id, buf->data);
    m = buf->data;

    endcons(buf);

    return m;
}

// thread entry-point
void* producer(void* srcbuf)
{
    int i;
    msg val;
    //Buffer* buf = (Buffer*) arg;

    for (i = 0; i < 3; i++){
        struct timeval t1;
		struct timezone t2;
		gettimeofday(&t1,&t2);//valore diverso ad ogni produzione
	    val = t1.tv_usec;
		produce((Buffer*)srcbuf, val);
    }

    pthread_exit(NULL);
}

void* consumer(void* srcbuf)
{
    int i;
    msg val;
    //Buffer* buf = (Buffer*) arg;

    for (i = 0; i < 3; i++){
        val = consume((Buffer*)srcbuf);
    }
    
    pthread_exit(NULL);
}