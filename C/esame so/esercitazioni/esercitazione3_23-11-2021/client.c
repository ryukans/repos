#include "common.h"

#define NMSGS 15

void client(int msgq_guest)
{
	int i;
	clientbuf msg;
	
	/* Inizializzazione Messaggio del processo */
	//TODO
	msg.type = CLIENT_T;
	msg.mess = getpid();

	/* Invio dei 15 messaggi in ciclo, con sleep(1) tra un messaggio e l'altro*/
	//TODO
	for(i = 0; i < NMSGS; i++){
		msgsnd(msgq_guest, &msg, sizeof(clientbuf)-sizeof(long), 0);
		sleep(1);
	}
	printf("[CLIENT] - all messages sent\n");
}
