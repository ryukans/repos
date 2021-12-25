#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "header.h"

#define REQUESTORS 4
#define ELABORATORS 2
#define NUMREQ 3
#define NUMELAB 6

int main()
{
    pthread_attr_t attr;
    pthread_t requestors[REQUESTORS];
    pthread_t elaborators[ELABORATORS];
    ElabMonitor* m = (ElabMonitor*)malloc(sizeof(ElabMonitor));

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    init_monitor(m);
    
    srand(time(NULL));

    printf("Initialized\n\n");

    
    for(int i = 0; i < REQUESTORS; i++){
        pthread_create(&requestors[i], &attr, Requestor, (void*)m);
    }

    for(int i = 0; i < ELABORATORS; i++){
        pthread_create(&elaborators[i], &attr, Elaborator, (void*)m);
    }
    
    for (int i = 0; i < REQUESTORS; i++){
        pthread_join(requestors[i], NULL);
    }

    for (int i = 0; i < ELABORATORS; i++){
        pthread_join(elaborators[i], NULL);
    
    }


    pthread_attr_destroy(&attr);
    remove_monitor(m);
    free(m);

    pthread_exit(NULL);

    printf("Exit main\n");
    return 0;
}

void* Requestor(void* arg)
{
    ElabMonitor* m = (ElabMonitor*)arg;
    int nops;

    nops = 0;
    for(int i = 0; i < NUMREQ; i++){
        nops = rand()%3+2;
        setop(m, nops);
    }

    pthread_exit(NULL);
}

void* Elaborator(void* arg)
{
    ElabMonitor* m = (ElabMonitor*)arg;
    int sumop;

    sumop = 0;
    for(int i = 0; i < NUMELAB; i++){
        sumop = getsumop(m);
        printf("Sum: %d\n", sumop);
    }


    pthread_exit(NULL);
}