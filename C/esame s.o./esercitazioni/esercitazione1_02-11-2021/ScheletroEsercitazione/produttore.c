/* PROCESSO PRODUTTORE */

#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"


int main(){
	printf("[PRODUTTORE] <%d> \n",getpid());
	
	int shmid, semid;
	
	srand(time(NULL));
	
	BufferCircolare* buff;
	
	key_t key_shm = ftok(".",'a');
	key_t key_sem = ftok(".",'b');
	
	shmid = shmget(key_shm, sizeof(BufferCircolare), IPC_CREAT | 0664);
	semid = semget(key_sem, N_SEM, IPC_CREAT | 0664);
	
	buff = (BufferCircolare*) shmat(shmid,0,0);
	
	produci_elemento(semid, buff);
	
	return 1;
}