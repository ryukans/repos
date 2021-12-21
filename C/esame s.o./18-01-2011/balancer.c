#include "header.h"


void reqblnc(qid_t client_req, qid_t server_reqs[])
{
    int i, count, err;
    msg_t creq, sreq;

    i = count = err = 0;
    while(i < REQUESTS && !err){
        
        err = msgrcv(client_req, (void*)&creq, MSGSZ(msg_t), CLIENT_T, 0);
        
        sreq.type = SERVER_T;
        sreq.pid = creq.pid;
        err = msgsnd(server_reqs[count], (void*)&sreq, MSGSZ(msg_t), 0);

        ++i;
        count = ++(count)%SERVERS;
    }

   	!err ? exit(EXIT_SUCCESS) : exit(EXIT_FAILURE);   
}