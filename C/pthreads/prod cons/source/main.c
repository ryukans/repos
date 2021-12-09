#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include "../header/procedure.h"

#define NUM_THREADS 10

int main()
{
    Buffer* buf = malloc(sizeof(Buffer));
    pthread_attr_t attr;
    pthread_t threads[NUM_THREADS];


    //init mutex and condition vars
    pthread_mutex_init(&buf->mutexm, NULL);
    pthread_cond_init(&buf->cvprod, NULL);
    pthread_cond_init(&buf->cvcons, NULL);
    //init flag vars
    buf->okprod = 1;
    buf->okconsume = 0;

    //setting threads as joinable type
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    int i;
    for(i = 0; i < NUM_THREADS; i++){
        if(i%2){
            printf("Consumer thread: %d\n", i);
            pthread_create(&threads[i], &attr, consumer, (void*)buf);
        }
        else{
            sleep(1);
            printf("Producer thread: %d\n", i);
            pthread_create(&threads[i], &attr, producer, (void*)buf);
        }    
    }

    for(i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], NULL);
        printf("Thread %d terminated\n", i); 
    }
    
    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&buf->mutexm);
    pthread_cond_destroy(&buf->cvprod);
    pthread_cond_destroy(&buf->cvcons);
    free(buf);
    
    pthread_exit(NULL);

    return 0;
}