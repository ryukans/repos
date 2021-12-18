#include "../header/procedure.h"
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <time.h>


#define NPROD 5
#define NCONS 3

int main()
{
    int shmid, semid;
    buffer* buf;

    shmid = shmget(IPC_PRIVATE, sizeof(buffer), IPC_CREAT | 0664);
    buf = (buffer*)shmat(shmid, NULL, 0);
    init_buffer(buf);

    semid = semget(IPC_PRIVATE, NSEMS, IPC_CREAT | 0664);
    semctl(semid, SPACE_AVAIL, SETVAL, BUFSIZE);
    semctl(semid, VALUE_AVAIL, SETVAL, 0);
    semctl(semid, MUTEX_P, SETVAL, 1);
    semctl(semid, MUTEX_C, SETVAL, 1);

    for(int i = 0; i < NPROD; i++){
        if(!fork()){
            srand(getpid()+time(NULL));
            int val = consume(buf, semid);
            printf("Consumer <%d> just consumed [%d]\n", i, val);
            exit(1);
        }
    }
    
    for(int i = 0; i < NCONS; i++){
        if (!fork()){
            srand(getpid()*time(NULL));
            int val = rand()%100;
            produce(buf, val, semid);
            printf("Producer <%d> just produced [%d]\n", i, val);
            exit(2);     
        }   
    }
    
    for(int i = 0; i < NPROD; i++){
        wait(NULL);
        printf("Child process producer terminated\n");
    }
    
    for(int i = 0; i < NCONS; i++){
        wait(NULL);
        printf("Child process consumer terminated\n");
    }
    
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    printf("Exit success\n");
    return 0;
}
