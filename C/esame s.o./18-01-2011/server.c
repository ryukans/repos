#include "header.h"

void reqrcv(qid_t server_req)
{
	int i, res, nmess;
	pid_t server;
    msg_t req;

	server = getpid();
	printf("\033%s[server]\033%s - %d: \tstatus ready\n", SERVER_C, RESET_C, server);
	
	nmess = REQUESTS*CLIENTS/SERVERS;
	i = res = 0;
	while(i < nmess && res != -1){
    	res = msgrcv(server_req, (void*)&req, MSGSZ(msg_t), SERVER_T, 0);
		printf("\033%s[server]\033%s - %d: \tmessage %d recived: \033%s%d\033%s \n", SERVER_C, RESET_C, server, i, PID_C, req.pid, RESET_C);
		++i;
	}

	printf("\033%s[server]\033%s - \033%s%d\033%s: \tall messages recieved\n", SERVER_C, RESET_C, PID_C, server, RESET_C);

	res < 0 ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);
}