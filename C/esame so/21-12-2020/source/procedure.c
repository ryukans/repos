#include "../header/procedure.h"
#include <time.h>

#define N_FRAMES 4

void init(Buffer* buf)
{
    buf->head = buf->tail = buf->count = 0;
    pthread_mutex_init(&buf->mutexm, NULL);
    pthread_cond_init(&buf->prodcv, NULL);
    pthread_cond_init(&buf->conscv, NULL);
}

void destr(Buffer* buf)
{
    pthread_mutex_destroy(&buf->mutexm);
    pthread_cond_destroy(&buf->prodcv);
    pthread_cond_destroy(&buf->conscv);
}

void startprod(Buffer* buf)
{
    pthread_mutex_lock(&buf->mutexm);

    while(buf->count == DIM_Q)
        pthread_cond_wait(&buf->prodcv, &buf->mutexm);
}

void endprod(Buffer* buf)
{
    buf->head = (buf->head+1)%DIM_Q;
    buf->count++;

    //buffered = (buffered+1)%(N_FRAMES+1); // [0,4] DEBUG TESTS
    
    pthread_cond_signal(&buf->conscv);

    pthread_mutex_unlock(&buf->mutexm);
}

void startcons(Buffer* buf)
{
    pthread_mutex_lock(&buf->mutexm);

    while(buf->count == 0)
        pthread_cond_wait(&buf->conscv, &buf->mutexm);  
}

void endcons(Buffer* buf)
{
    buf->tail = (buf->tail+1)%DIM_Q;
    buf->count--;

    pthread_cond_signal(&buf->prodcv);

    pthread_mutex_unlock(&buf->mutexm);
}

void produce(Buffer* buf, frame_video srcframe)
{
    startprod(buf);

    printf("Produzione frame: { %d, %d, %d, %d }\n", srcframe[0][0], srcframe[0][1], srcframe[1][0], srcframe[1][1]);

    buf->frames[buf->head][0][0] = srcframe[0][0];
    buf->frames[buf->head][0][1] = srcframe[0][1];
    buf->frames[buf->head][1][0] = srcframe[1][0];
    buf->frames[buf->head][1][1] = srcframe[1][1];

    endprod(buf);
}

void consume(Buffer* buf, frame_video srcframe)
{
    startcons(buf);

    srcframe[0][0] = buf->frames[buf->tail][0][0];
    srcframe[0][1] = buf->frames[buf->tail][0][1];
    srcframe[1][0] = buf->frames[buf->tail][1][0];
    srcframe[1][1] = buf->frames[buf->tail][1][1];

    printf("Consumazione frame: { %d, %d, %d, %d }\n", srcframe[0][0], srcframe[0][1], srcframe[1][0], srcframe[1][1]);

    endcons(buf);
}


void buffer(Buffer* buf, int frames)
{
    pthread_mutex_lock(&buf->mutexm);

    printf("Buffering...\n");

    while(buf->count < frames){
        printf("%d < min buffered frames (4)\n", buf->count);
        pthread_cond_wait(&buf->conscv, &buf->mutexm);
    }
    printf("%d >= min buffered frames (4)\n", buf->count);

    pthread_mutex_unlock(&buf->mutexm);
}