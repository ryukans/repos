/*PROCESSO CONSUMATORE*/

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
	printf("[Consumatore] Sono il processo consumatore con pid ",getpid());
	
	int shmid, semid;
	BufferCircolare* buff;
	
	key_t key_shm = ftok(".",'a');
	key_t key_sem = ftok(".",'b');
	
	shmid = shmget(key_shm, sizeof(BufferCircolare), IPC_CREAT | 0664);
	semid = semget(key_sem, N_SEM,IPC_CREAT | 0664);
	
	buff = (BufferCircolare*) shmat(shmid,0,0);
	
	for (int i = 0; i < 2; i++)
		consuma_elementi(semid, buff);
	
	return 1;
}