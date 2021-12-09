#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N_THREADS 5

void* print(void* threadid)
{
    printf("%ld: Hello World\n", (long)threadid);
    pthread_exit(NULL);
}

int main()
{
    pthread_t threads[N_THREADS];
    int rc;
    long i;

    for(i = 0; i < N_THREADS; i++){
        if((rc = pthread_create(&threads[i], NULL, print, (void*)i))){
            printf("Error pthead: %d\n", rc);
            exit(-1);
        }
    }
    
    pthread_exit(NULL);
}