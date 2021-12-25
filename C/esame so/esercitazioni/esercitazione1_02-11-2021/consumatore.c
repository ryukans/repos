/*PROCESSO CONSUMATORE*/

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"


int main(){
	printf("[Consumatore] <%d> \n",getpid());
	
	int shmkey, shmid;	
	int semkey, semid;
	Buffer* buf;
	
	shmkey = ftok(PATHNAME, SHMID);
	shmid = shmget(shmkey, sizeof(Buffer), IPC_CREAT | 0664);
	
	semkey = ftok(PATHNAME, SEMID);
	semid = semget(semkey, 0, 0);
	
	buf = (Buffer*)shmat(shmid, NULL, 0);
	
	for(int i = 0; i < 2; i++){
		consuma_elementi(semid, buf);
		sleep(1);
	}
	
	return 1;
}
