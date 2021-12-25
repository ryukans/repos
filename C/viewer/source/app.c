#include "../header/viewer.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{
	ipc_t qdes;
    msg_t msg;
	pid_t pid;
    int err;

	qdes.key = ftok(".", 'Q');
	qdes.id = msgget(qdes.key, IPC_CREAT | 0664);

    msg.type = 1;
    msg.pid = getpid();
    strcpy(msg.buffer, "Hello World\n");

	pid = fork();
	if(pid < 0){
		perror("[app] fork() failed\n");
		exit(0);
	}
/*
	if(!pid){
		execl("./viewer", "./viewer", NULL);
		perror("[app] exelc() failed\n");	
	}*/

	err = msgsnd(qdes.id, (void*)&msg, sizeof(msg_t)-sizeof(long), 0);
	if(err < 0){
		perror("[client] msgsnd() failed\n");
		exit(-1);
	}	

	msgctl(qdes.id, IPC_RMID, NULL);

    return 0;
}