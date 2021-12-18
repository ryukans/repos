#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

#include "procedure.h"

int main(){

	/* TBD: Creare una variabile M di tipo "Monitor", e inizializzarla con init_monitor() */
	Monitor M;
	Buffer* buf;
	key_t key_weather;
	
	key_weather = shmget(IPC_PRIVATE, sizeof(Buffer), IPC_CREAT|0664);
	buf = (Buffer*)shmat(key_weather, NULL, 0);

	/* TBD: inizializzare la struttura Buffer */
	init_monitor(&M, NUM_CONDITIONS);
	init_buffer(buf);

	pid_t pid;

	int k;
	for(k = 0; k < NUM_USERS; k++){
		pid=fork();

		if(pid == 0){
			Utente(&M,buf);
			exit(0);
     	} 
		else if(pid < 0) 
			perror("fork");
	}

	pid=fork();

	if(pid == 0){
		Servizio(&M,buf);
		exit(0);
	} 
	else if(pid < 0)
		perror("fork error\n");


	int status;
	for(k = 0; k < NUM_USERS+1; k++){
		pid=wait(&status);

		if(pid == -1)
			perror("exit status code: -1\n");
	}

	shmctl(key_weather,IPC_RMID,0);

	/* TBD: Deallocare la variabile Monitor con remove_monitor() */
	remove_monitor(&M);
	
	return 0;
}
