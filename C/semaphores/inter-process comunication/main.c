#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "../sem/header/sem.h"

#define NUM_PROC 2

int main()
{
    key_t key_shm = IPC_PRIVATE;
    key_t key_sem = IPC_PRIVATE;
    
    //Shared memory
    int shmid = shmget(key_shm, sizeof(int), IPC_CREAT | 0664);

    if(shmid < 0) {
        perror("Error Shmget\n");
        exit(EXIT_SUCCESS);
    }

    int* shmptr = (int*) shmat(shmid, NULL, 0);

    if(shmptr == (void*)-1){
        perror("Error linking memory\n");
        exit(EXIT_FAILURE);
    }

    //Semaphores
    int semid = semget(key_sem, 1, IPC_CREAT | 0664);

    if(semid < 0){
        perror("Error Semget\n");
        exit(EXIT_FAILURE);
    }


    *shmptr = 0; //Initialize shared memory
    semctl(semid, 0, SETVAL, 1); //Initialize semaphore (1)
    
    int i;
    for (i = 0; i < NUM_PROC; i++){
        pid_t pid = fork();

        if(pid < 0) {
            perror("Error FORK\n");
            exit(EXIT_FAILURE);
        }

        if(pid == 0){  
            printf("Process[%d] PID=%d created\n", i, getpid());
            int j;
            for (j = 0; j < 5; j++){
                waitsem(semid, 0);
                
                //BEGIN CRITIC SECTION
                
                int tmp = *shmptr;
                printf("Process %d has read\n", i);
                sleep(1); //optional, it makes the execution slower in order to emphasize the race condition between the two processes on the variable -tmp-
                //(*shmptr)++;
                *shmptr = tmp+1;
                printf("Process %d has incremented\n", i);

                //END CRITIC SECTION

                signalsem(semid, 0);
            }
            exit(EXIT_SUCCESS);
        }
    }
    
    for (i = 0; i < NUM_PROC; i++){
        wait(NULL);
    }

    printf("Final value: %d\n", *shmptr);
    
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);


    return 0;
}