#include "common.h"
#include <stdio.h>

void server(int msgq_guest, int msgq_print)
{
	int i;
	
	clientbuf msg_c;

	serverbuf msg_s;

	msg_c.type = CLIENT_T;
	msg_s.type = PRINTER_T;
	printf("[server ] Server ready...\n");
	
	/*
	do{
		for(i = 0; i < BUFFER_DIM && msg_c.type != EXIT_T; i++){
			msgrcv(msgq_guest, &msg_c, sizeof(clientbuf)-sizeof(long), 0, 0);
			msg_c.type == EXIT_T ? msg_s.mess[i] = -1 : msg_s.mess[i] = msg_c.mess;
		}
		msgsnd(msgq_print, &msg_s, sizeof(serverbuf)-sizeof(long), 0);
	}while(msg_c.type != EXIT_T);
	_exit(0);*/
	
	while(msg_c.type != EXIT_T){
		for(i = 0; (i < BUFFER_DIM) && (msg_c.type != EXIT_T); i++)
		{
			msgrcv(msgq_guest, &msg_c, sizeof(clientbuf)-sizeof(long), 0, 0);
			msg_s.mess[i] = msg_c.type == EXIT_T ? -1 : msg_c.mess;
		}
		msgsnd(msgq_print, &msg_s, sizeof(serverbuf)-sizeof(long), 0);
		printf("[server] - message sent to printer\n");
	}
	_exit(0);
	
	/*
	while(1){
		for(i = 0; i < BUFFER_DIM; i++){
			msgrcv(msgq_guest, &msg_c, sizeof(clientbuf)-sizeof(long), 0, 0);
			if(msg_c.type==EXIT_T){
				msg_s.mess[i] = -1;
				msgsnd(msgq_print, &msg_s, sizeof(serverbuf)-sizeof(long), 0);
				printf("[Server] Goodbye...\n");
				_exit(0);
			}
			msg_s.mess[i] = msg_c.mess;
		}
		msgsnd(msgq_print, &msg_s, sizeof(serverbuf)-sizeof(long), 0);
	}
	*/
}



