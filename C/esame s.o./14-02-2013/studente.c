#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>

void leggi_appello(buffer*, int semid);
void prenota_appello(buffer*, int semid);

int main(int argc, char*argv[])
{

    ipc shm, sem;
    buffer* buf;

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, sizeof(buffer), IPC_CREAT | 0664);
    buf = (buffer*)shmat(shm.id, NULL, 0);

    sem.key = ftok(PATHNAME, SEMID);
    sem.id = semget(sem.key, 0, 0);

    sleep(rand()%9);
    leggi_appello(buf, sem.id);
    prenota_appello(buf, sem.id);
    
    return 1;
}

void leggi_appello(buffer* buf, int semid)
{
    printf("[SEGREPASS]: Prenotazione in corso, caricamento...\n"); //debug

    waitsem(semid, MUTEXL);

    buf->studenti++;
    if(buf->studenti == 1)
        waitsem(semid, SYNCHDC);
    
    signalsem(semid, MUTEXL);

    printf("Caricamento terminato\n");  //debug
    printf("[SEGREPASS]: Data appello %s\n", buf->appello.data);

    waitsem(semid, MUTEXL);

    buf->studenti--;
    if(buf->studenti == 0)
        signalsem(semid, SYNCHDC);
    
    signalsem(semid, MUTEXL);
}

void prenota_appello(buffer* buf, int semid)
{
    waitsem(semid, MUTEXP);

    buf->appello.prenotati++;
    printf("[SEGREPASS] - Prenotazione effettuata\n");

    signalsem(semid, MUTEXP);    
}










