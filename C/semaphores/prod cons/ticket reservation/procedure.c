#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void prenota(teatro* buf, int nposti, int sem_id)
{
    if(buf->disponibili == 0 || nposti > buf->disponibili){
        printf("Dispoinibilità esaurita\n");
        exit(0);
    }

    //waitsem(sem_id, CLIENTE); inutile (?)

    waitsem(sem_id, MUTEXC); //sezione critica aggiornamento variabili di stato

    int index = 0;
    while(index < DIMBUF && buf->posti[index].stato != LIBERO)
        ++index;

    for(int i = index; i < nposti; i++)
        buf->posti[i].stato = IN_AGGIORNAMENTO;
    
    signalsem(sem_id, MUTEXC);


    for(int i = index; i < nposti; i++)
        buf->posti[i].id_cliente = getpid();
    

    waitsem(sem_id, MUTEXC);

    for(int i = index; i < nposti; i++)
        buf->posti[i].stato = OCCUPATO;
    
    buf->disponibili -= nposti;

    signalsem(sem_id, MUTEXC);

    signalsem(sem_id, VISUAL); //segnala il visualizzatore del messaggio disponibile

    printf("Prenotato\n\n");
}
