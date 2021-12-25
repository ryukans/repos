#include "header.h"

void reqsnd(qid_t client_req)
{
	int i, err;
	pid_t client;
    msg_t msg;

	client = getpid();
	i = err = 0;
    while(i < REQUESTS && !err){
		msg.type = CLIENT_T;
		msg.pid = client;
		err = msgsnd(client_req, (void*)&msg, MSGSZ(msg_t), 0);
		++i;
		sleep(SENDRATE);
    }

	printf("\033%s[client]\033%s - %d: \tall %d requests sent\n", CLIENT_C, RESET_C, client, i);
	
	err ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}