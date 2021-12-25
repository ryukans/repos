#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>


void aggiorna_appello(buffer*, const char* data, int semid);
void cancella_prenotati(buffer*, int semid);

int main(int argc, char*argv[])
{
    
    ipc shm, sem;
    buffer* buf;

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, 0, 0);
    buf = (buffer*)shmat(shm.id, NULL, 0);

    sem.key = ftok(PATHNAME, SEMID);
    sem.id = semget(sem.key, 0, 0);

    printf("Docente\n\n");
    for(int i = 0; i < 3; i++){
        aggiorna_appello(buf, "12/12/12", sem.id);
        sleep(3);
        cancella_prenotati(buf, sem.id);
    }

    return 2;
}


void aggiorna_appello(buffer* buf, const char* data, int semid)
{
    waitsem(semid, SYNCHDC);

    strncpy(buf->appello.data, data, MAXSIZE+1);

    signalsem(semid, SYNCHDC);
}

void cancella_prenotati(buffer* buf, int semid)
{
    waitsem(semid, MUTEXP);

    printf("[DOCENTE] numero prenotati %d\n", buf->appello.prenotati);
    buf->appello.prenotati = 0;

    signalsem(semid, MUTEXP);
}