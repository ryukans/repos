#include "flight.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_UPDATES

typedef struct parameter{
    Buffer* buf;
    int id;
} parameter;

void init_pars(parameter*, Buffer*, int);
void* Handler(void*);

int main()
{
    pthread_attr_t attr;
    pthread_t handlers[NUM_THREADS];
    Buffer* buf = (Buffer*)malloc(sizeof(Buffer));
    parameter args[NUM_THREADS];

    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    init_buffer(buf);

    for (int i = 0; i < NUM_THREADS; i++){
        init_pars(&args[i], buf, i);
        printf("Pars initialized: %d\n", args[i].id);
        int err_t = pthread_create(&handlers[i], &attr, Handler, (void*)&args[i]);
        
        if(err_t){
            perror("Error: pthread_create()\n");
            exit(-1);
        }
    }
    
    for (int i = 0; i < NUM_THREADS; i++){
        printf("Thread handler <%d> joined\n", i);
        pthread_join(handlers[i], NULL);
    }

    pthread_attr_destroy(&attr);    
    destroy_buffer(buf);
    free(buf);

    pthread_exit(NULL);

    printf("Exit success\n");
    return 0;
}


void* Handler(void* arg)
{
    parameter* p = (parameter*)arg;

    ins_flight(p->buf, p->id);
    printf("Flight %d inserted\n", p->id);

    upd_flight(p->buf, p->id, 1000);
    printf("Flight %d updated\n", p->id);

    upd_flight(p->buf, p->id, 2000);
    printf("Flight %d updated\n", p->id);

    upd_flight(p->buf, p->id, 1000);
    printf("Flight %d updated\n", p->id);

    rem_flight(p->buf, p->id);
    printf("Flight %d removed\n", p->id);


    pthread_exit(NULL);
}


void init_pars(parameter* p, Buffer* buf, int id)
{
    p->buf = buf;
    p->id = id;
}