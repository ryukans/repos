#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#define DIM_Q 6
#define FRAME_RES 2
#define LOG(x)
    #ifdef _DEBUG \
        \printf(x)
    #endif


typedef int frame_video[FRAME_RES][FRAME_RES];

typedef struct streaming_buffer{
    pthread_mutex_t mutexm;

    pthread_cond_t prodcv;
    pthread_cond_t conscv;
    //frame_video frame;
    frame_video frames[DIM_Q]; //queue of matrix frames
    int head;
    int tail;
    int count;

} Buffer;


void startprod(Buffer*);
void endprod(Buffer*);
void startcons(Buffer*);
void endcons(Buffer*);

void init(Buffer*);
void destr(Buffer*);

void produce(Buffer*, frame_video);
void consume(Buffer*, frame_video);
void buffer(Buffer*, int frames);














