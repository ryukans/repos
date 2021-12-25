/* PROCESSO PRODUTTORE */

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
	printf("[PRODUTTORE] <%d> \n",getpid());
	
	int shmkey, shmid;	
	int semkey, semid;
	Buffer* buf;
	
	srand(time(NULL));
	
	shmkey = ftok(PATHNAME, SHMID);
	shmid = shmget(shmkey, sizeof(Buffer), IPC_CREAT | 0664);
	
	semkey = ftok(PATHNAME, SEMID);
	semid = semget(semkey, 0, 0);
	
	buf = (Buffer*)shmat(shmid, NULL, 0);
	
	produci_elemento(semid, buf);
	
	return 1;
}
