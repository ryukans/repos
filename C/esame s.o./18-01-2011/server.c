#include "header.h"

void reqrcv(qid_t server_req)
{
	int err;
	pid_t server;
    msg_t req;

	server = getpid();
    err = msgrcv(server_req, (void*)&req, MSGSZ(msg_t), SERVER_T, 0);
	
	printf("[server]: %d\tmessage recived: <%d>\n", server, req.type);

	!err ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);
}