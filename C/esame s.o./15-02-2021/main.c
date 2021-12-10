#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "prodcons.h"



void * produttore(void *);
void * consumatore(void *);

int main()
{

    printf("[MAIN] inizializza_monitor\n");

    /* TBD: Creare e inizializzare il monitor */
    MonitorProdCons* m;
    
    m = (MonitorProdCons*)malloc(sizeof(MonitorProdCons));
    inizializza_monitor(m);
    
    pthread_attr_init(&attr);
    pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);

    printf("[MAIN] pthread_create\n");

    /* TBD: Avviare i thread */
    int i;
    for (i = 0; i < NUM_PROD; i++)
        pthread_create(&threads[i], &attr, produttore, (void*)m);

    pthread_create(&threads[i], &attr, consumatore, (void*)m); // -i- dovrebbe essere 5
  
    
    printf("[MAIN] pthread_join\n");
    
    /* TBD: Attendere la terminazione dei thread */

    for(i = 0; i < NUM_PROD+NUM_CONS; i++){
        //printf("[MAIN] lwp %d terminated\n", i);
        pthread_join(threads[i], NULL);
    }

    printf("[MAIN] distruzione_monitor\n");

    /* TBD: Disattivazione e deallocazione del monitor */

    pthread_attr_destroy(&attr);
    distruggi_monitor(m);
    free(m);

    return EXIT_SUCCESS;
}


void * produttore(void * p) {

    MonitorProdCons* m = (MonitorProdCons*)p;

    printf("[MAIN] Avvio thread produttore\n");

    int i;
    for(i = 0; i < 4; i++){
        int val = rand()%10;

        printf("[MAIN] Produttore ha generato %d\n", val);

        int ret = produci(m, val); 
        /* TBD: Chiamare il metodo di produzione */

        while(ret < 0){
            sleep(1);

            printf("[MAIN] Produttore ritenta inserimento di %d\n", val);

            ret = produci(m, val); 
            /* TBD: Chiamare il metodo di produzione */
        }

    }

    pthread_exit(NULL);
}

void * consumatore(void * p)
{
    MonitorProdCons* m = (MonitorProdCons*)p;

    printf("[MAIN] Avvio thread consumatore\n");

    int i;
    for(i = 0; i < 20; i++){
        int val;

        int ret = consuma(m, &val); 
        /* TBD: Chiamare il metodo di consumazione */

        printf("[MAIN] Consumatore ha prelevato %d\n", val);

        sleep(2);
    }

    pthread_exit(NULL);
}