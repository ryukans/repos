#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>

int main()
{
    ipc shm, sem;
    pid_t pid;
    buffer* buf;

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, sizeof(buffer), IPC_CREAT | 0664);
    buf = (buffer*)shmat(shm.id, NULL, 0);
    buf->studenti = 0;
    buf->appello.prenotati = 0;
    strncpy(buf->appello.data, "00/00/00", MAXSIZE);

    sem.key = ftok(PATHNAME, SHMID);
    sem.id = semget(sem.key, NSEMS, IPC_CREAT | 0664);
    semctl(sem.id, SYNCHDC, SETVAL, 1);
    semctl(sem.id, MUTEXL, SETVAL, 1);
    semctl(sem.id, MUTEXP, SETVAL, 1);


    for (int i = 0; i < 11; i++)
    {
        pid = fork();

        if(pid == 0){
            if(i == 0){
               execl("./docente", "./docente", NULL);
            }
            else{
			    execl("./studente", "./studente", NULL);            
            }
            perror("Errore execl()\n");
        }
        else if(pid < 0){
            perror("Error fork()");
            exit(-1);
        }
    }
    
    /*
    pid = fork();  

    if(pid == 0){
        execl(".docente", ".docente", NULL);
    }
    else{
        perror("Errore processo docente\n");
        exit(-1);
    }

    for (int i = 0; i < 10; i++){
        pid = fork();
        if(pid == 0){
            execl(".studente", ".studente", NULL);
        }
        else{
            perror("Errore processo studente\n");
            exit(-2);
        }
    }*/
    
    for (int i = 0; i < 11; i++){
        wait(NULL);
        //printf("Process %d killed\n", i);
    }

    shmctl(shm.id, IPC_RMID, NULL);
    semctl(sem.id, 0, IPC_RMID);

    printf("Exit success\n");
    return 0;
}