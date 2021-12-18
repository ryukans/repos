#include "procedure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    ipc shm, sem;
    pid_t pid;

    shm.key = ftok(PATHNAME, SHMID);
    shm.id = shmget(shm.key, sizeof(buffer), IPC_CREAT | 0664);
    buffer* buf = (buffer*)shmat(shm.id, NULL, 0);
    
    buf->mess.val1 = buf->mess.val2 = DEFAULT;
    buf->readers= 0;

    sem.key = ftok(PATHNAME, SEMID);
    sem.id = semget(sem.key, NSEMS, IPC_CREAT | 0664);
    semctl(sem.id, MUTEXL, SETVAL, 1);
    semctl(sem.id, SYNCHRW, SETVAL, 1);


    pid = fork();

    if(pid == 0){
        for (int i = 0; i < 5; i++){
            execl(".readers", ".readers", NULL);
        }
        exit(0);
    }
  

    pid = fork();

    if(pid == 0){
        for (int i = 0; i < 5; i++){
            execl(".writer", ".writer", NULL);
        }
        exit(0);
    }
    


    /*
    for(int i = 0; i < 10; i++){
        pid = fork();
        
        if(pid == 0){
            if(i%2)
                execl(".writer", ".writer", NULL);
            else
        }
    }*/
    
    for(int i = 0; i < 10; i++)
        wait(NULL);
    
    printf("exit\n");
    return 0;
}