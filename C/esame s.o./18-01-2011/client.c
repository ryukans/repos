#include "header.h"

void reqsend(qid_t client_req)
{
	int i, err;
	pid_t client;
    msg_t msg;

    msg.type = CLIENT_T;
    msg.pid = client;

    for(i = 0, err = 0; i < REQUESTS && !err; i++){
		err = msgsnd(client_req, (void*)&msg, MSGSZ(msg_t), 0);
		sleep(SENDRATE);
    }

	printf("[client]: %d\tmessage sent\n", client);
	
	!err ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}