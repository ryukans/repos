#include <stdio.h>
#include <sys/wait.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include "../header/procedure.h"

int main()
{
    int i, k, status, queue;
    pid_t pid;
    char m[30];

    queue = msgget(IPC_PRIVATE, IPC_CREAT | 0664);

    pid = fork();
    
    if(pid == 0){
        for (i = 0; i < 10; i++){
            sprintf(m, "stringa %d", i);
            usleep(100);
            producer(queue, m);
        }
        _exit(0);
    }
    
    pid = fork();

    if(pid == 0){
        sleep(1);
        for (i = 0; i < 10; i++){
            consumer(queue);
        }
        _exit(0);
    }

    for (i = 0; i < 2; i++){
        pid = wait(&status);

        if(pid == -1)
            perror("Error\n");
        else
           printf("Child process [%d] terminated: %d\n", pid, status);
    }

    msgctl(queue, IPC_RMID, 0);
    return 0;

}




