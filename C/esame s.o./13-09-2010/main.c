#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define NUM_ACC     15
#define NUM_PROCC   10


int main()
{
    int shm_buf, shm_nscorte;
    
    buffer* buf;
    int* nscorte;

    shm_buf = shmget(IPC_PRIVATE, sizeof(buffer), IPC_CREAT | 0664);
    shm_nscorte = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0664);
    
    buf = (buffer*) shmat(shm_buf, NULL, 0);
    nscorte = (int*) shmat(shm_nscorte, NULL, 0);

    *nscorte = 0;
    for (int i = 0; i < NUM_ELEM; i++)
    {
        buf->magazzino[i].stato = LIBERO;
    }
    
    init_monitor(&buf->m, N_CV);

    pid_t pid;

    pid = fork();


    for (int i = 0; i < NUM_PROCC; i++)
    {
        if(pid == 0){
            for (int j = 0; j < NUM_ACC; j++)
            {
                int val = getpid();
                inserisci(buf, nscorte, val);
                printf("Prodotto %d\n", val);
            }
            
        }
        exit(0);
    }
    

    if(pid == 0){
        for (int i = 0; i < NUM_PROCC; i++){
            for (int j = 0; j < NUM_ACC; j++){
                int val = getpid();
                inserisci(buf, nscorte, val);
                printf("Prodotto %d\n", val);
            }
            exit(0);
        }
    }


    pid = fork();

    for (int i = 0; i < NUM_PROCC; i++)
    {
        if(pid == 0){
            for (int j = 0; j < NUM_ACC; j++)
            {
                int val = preleva(buf, nscorte);
                printf("Consumato %d\n", val);
            }
        }
        exit(0);
    }
    


    rem_monitor(&buf->m);
    shmctl(shm_buf, IPC_RMID, 0);
    shmctl(shm_nscorte, IPC_RMID, 0);

    printf("[MAIN] exit success\n");
    return 0;
}