#include "common.h"
#include <sys/wait.h>

#define NR_CLIENT  5

/* ID - Code di Messaggi */
int msgq_guest;
int msgq_print;

int main(int argc,char*argv[])
{
	int i;
	/*Richiesta code di messaggi IPC*/
	msgq_guest = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
	msgq_print = msgget(IPC_PRIVATE, IPC_CREAT | 0664); 

	/*Creazione processo 'printer'*/
	if(!fork()){
		printer(msgq_print);
		_exit(0);
	}

	/*Creazione processo 'server'*/
	if(!fork()){
		server(msgq_guest, msgq_print);
		_exit(0);
	}

	/*Creazione processi 'client'*/
	for(i = 0; i < NR_CLIENT; i++){
		if(!fork()){
			client(msgq_guest);
			_exit(0);
		}
	}

	/*Attesa terminazione dei client*/
	for(i = 0; i < NR_CLIENT; i++)
		wait(NULL);

	/*Invio messaggio di terminazione al server*/
	clientbuf exit;
	exit.type = EXIT_T;
	exit.mess = -1; 
	msgsnd(msgq_guest, &exit, sizeof(clientbuf)-sizeof(long), 0);
	
	/*Attesa terminazione processi 'server' e 'printer'*/
	for(i=0; i<2; i++)
		wait(0);

	/*Rimozione code IPC e uscita*/
	//TODO
	msgctl(msgq_guest, 0, IPC_RMID);
	msgctl(msgq_print, 0, IPC_RMID);

	return 0;
}
