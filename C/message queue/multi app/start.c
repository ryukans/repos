#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc, char const *argv[])
{
    ipc queue;
    pid_t pid;

    queue.key = ftok(QUEUEPATH, QUEUEID);
    queue.id = msgget(queue.key, IPC_CREAT | 0664);

    if(queue.id < 0){
        perror("msgget() failed\n");
        exit(-3);
    }

    pid = fork();

    if(pid < 0){
        perror("fork() failed\n");
        exit(1);
    }
    if(pid == 0){
        execl("./p1", "./p1", NULL);
        perror("execl() failed\n");
        exit(0);
    }

    pid = fork();

    if(pid < 0){
        perror("fork() failed\n");
        exit(1);
    }
    if(pid == 0){
        execl("./p2", "./p2", (char*)0);
        perror("execl() failed\n");
        exit(0);
    }

    pid = fork();

    if(pid < 0){
        perror("fork() failed\n");
        exit(1);
    }
    if(pid == 0){
        execl("./p3", "./p3", (char*)0);
        perror("execl() failed\n");
        exit(0);
    }

    for (int i = 0; i < 3; i++){
        wait(NULL);
    }
    
    msgctl(queue.id, IPC_RMID, NULL);

    return 0;
}
