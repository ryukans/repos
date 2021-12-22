#include "procedure.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <time.h>

int main()
{
    ipc shm, sem;
    pid_t pid;
    int nreaders, nwriters, nproc, status;
    

    shm.key = IPC_PRIVATE;
    shm.id = shmget(shm.key, sizeof(buffer), IPC_CREAT | 0664);
    buffer* buf = (buffer*)shmat(shm.id, NULL, 0);
    init_buffer(buf);

    sem.key = IPC_PRIVATE;
    sem.id = semget(sem.key, NSEMS, IPC_CREAT | 0664);
    semctl(sem.id, MUTEXR, SETVAL, 1);
    semctl(sem.id, SYNCHRW, SETVAL, 1);

    nreaders = nwriters = 6;
    nproc = nreaders+nwriters;

    for(int i = 0; i < nproc; i++){
        pid = fork();

        if(pid == 0){
            if(i%2){
                mess_t mess = _read(buf, sem.id);
                printf("[READER] <%d> has read %d\n", mess);
            }
            else{
                srand(time(NULL)*getpid());
                mess_t mess = rand()%100;
                printf("[WRITER] <%d> has written %d\n", getpid(), mess);
                write(buf, mess, sem.id);
            }
        }
    }

    status = 0;    
    for(int i = 0; i < nproc; i++){
        pid = wait(&status);

        if (pid == -1)
            perror("Error\n");
        else
            printf("Process <%d> has terminated: %d\n", pid, status);
    }
    
    shmctl(shm.id, IPC_RMID, NULL);
    semctl(shm.id, 0, NULL);
    
    printf("Exit success\n");
    return 0;
}
