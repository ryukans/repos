#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "dotprod.h"
#include "util.h"

#define NUM_THREADS 40
#define VEC_LEN 10000   // Dim of each sub partition

DotProd dotstr;

pthread_t threads[NUM_THREADS];
pthread_mutex_t mutexsum;

void* dotprod(void* arg)
{
    int i, start, end, len;
    long offset;
    double sum, *x, *y;

    offset = (long)arg;
    len    = dotstr.len;
    start  = offset*len;
    end    = start+len;
    //vector coordinates
    x = dotstr.x;
    y = dotstr.y;

    for (i = start, sum = 0.0; i < end; i++)
        sum += (x[i]*y[i]);

    pthread_mutex_lock(&mutexsum);

    dotstr.sum += sum;

    pthread_mutex_unlock(&mutexsum);
    
    pthread_exit(NULL);
}

int main()
{
    long i;
    double *x, *y;
    void *status;
    pthread_attr_t attr;

   
    x = y = (double*) malloc(NUM_THREADS*VEC_LEN*sizeof(double));
    
    for(i = 0; i < NUM_THREADS*VEC_LEN; i++)
        y[i] = (x[i] = 1);
    
    dotstr.len = VEC_LEN;
    dotstr.x = x;
    dotstr.y = y;
    dotstr.sum = 0;

    pthread_mutex_init(&mutexsum, NULL);

    long start_time = getinstant();
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


    int ret = -1;
    for (i = 0; i < NUM_THREADS; i++){
        if((ret = pthread_create(&threads[i], &attr, dotprod, (void*)i))){
            printf("Error pthread: %d\n", ret);
            exit(ret);
        }
    }
    
    for (i = 0; i < NUM_THREADS; i++){
        pthread_join(threads[i], &status);
        printf("Joined thread %d\n", (int)i);
    }
    
    long elapsed_time = getinstant()-start_time;

    printf ("\nDot product =\t%f\nExec time =\t%ld\n", dotstr.sum, elapsed_time);

    pthread_attr_destroy(&attr);
    pthread_mutex_destroy(&mutexsum);
    free(x);
    free(y);

    pthread_exit(NULL);

    return 0;
}