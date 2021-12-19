#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <time.h>
#include "header.h"

#define N_PROC 11


int main()
{
	pid_t pid_ex,pid;
	int st,i;
	
	//Istanziamo 
	int shmkey, shmid;	
	int semkey, semid;
	Buffer* buf;
	
	shmkey = ftok(PATHNAME, SHMID);
	shmid = shmget(shmkey, sizeof(Buffer), IPC_CREAT | 0664);
	
	semkey = ftok(PATHNAME, SEMID);
	semid = semget(semkey, NSEMS, IPC_CREAT | 0664);
	
	buf = (Buffer*)shmat(shmid, NULL, 0);
	buf->testa = buf->coda = 0;
	for(int i = 0; i < N; i++) buf->elementi[i] = 0;
	
	semctl(semid, PROD, SETVAL, N);
	semctl(semid, CONS, SETVAL, 0);
	semctl(semid, MUTEXP, SETVAL, 1);
	
	srand(time(NULL));
	
	for(i = 0; i < N_PROC;i++){
		pid = fork();
		
		if(pid == 0){
			if(i == 0)
				execl("./consumatore", "./consumatore", NULL);
			else
				execl("./produttore", "./produttore", NULL);
				
			_exit(0);			
		}
		sleep(rand()%3+1);

	}
	
	for(i = 0; i < N_PROC ; i++){
		pid_ex = wait(&st);
		printf("[MASTER] - Il processo %d ha terminato l'esecuzione\n",pid_ex);			
	}
	
	shmctl(shmid,IPC_RMID,0);
	semctl(semid,0,IPC_RMID);
	
	return 0;
}
