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
    int i, status, queue;
    pid_t pid;

    queue = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    init_serviceq();

    pid = fork();

    if(pid == 0){
        printf("Produder [%d]", getpid());
        sleep(2);
        producer(queue, "ciao");
        _exit(0);
    }

    pid = fork();

    if(pid == 0){
        printf("Consumer [%d]", getpid());
        sleep(1);
        consumer(queue);
        _exit(0);
    }   
    
    for (i = 0; i < 2; i++){
        pid = wait(&status);
        if(pid == -1)
            perror("Error\n");
        else
            printf("Child [%d] terminated: %d\n", pid, status);
    }

    msgctl(queue, IPC_RMID, 0);
    remove_serviceq();

    return 0;
}