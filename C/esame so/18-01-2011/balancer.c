#include "header.h"


void reqblnc(qid_t client_req, qid_t server_reqs[])
{
    int i, count, nreqs, rcvres, snderr;
    pid_t balancer, client;
    msg_t creq, sreq;

    balancer = getpid();
    printf("\033%s[balancer]\033%s - %d:\tturing on...\n", BALANCER_C, RESET_C, balancer);
    sleep(3);

    nreqs = REQUESTS*CLIENTS;
    i = count = rcvres = snderr = 0;
    while(i < nreqs && rcvres != -1 && !snderr){
        rcvres = msgrcv(client_req, (void*)&creq, MSGSZ(msg_t), CLIENT_T, 0);
        client = creq.pid;

        printf("\033%s[balancer]\033%s - %d:\tmessage form client %d recived\n", BALANCER_C, RESET_C, balancer, client);

        sreq.type = SERVER_T;
        sreq.pid = client;
        snderr = msgsnd(server_reqs[count], (void*)&sreq, MSGSZ(msg_t), 0);

        printf("\033%s[balancer]\033%s - \033%s%d\033%s:\tmessage %d sent to server %d\n", BALANCER_C, RESET_C, PID_C, balancer, RESET_C, sreq.pid, count+1);
        
        ++i;
        count = ++(count)%SERVERS;

        //sleep(SENDRATE); /* may be useful in debugguing mode
    }

    printf("\033%s[balancer]\033%s - %d\tall messages sent\n", BALANCER_C, RESET_C, balancer);

   	(rcvres < 0 || snderr) ? exit(EXIT_FAILURE) : exit(EXIT_SUCCESS);   
}