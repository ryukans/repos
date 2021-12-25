#include "header.h"
#include <sys/wait.h>

int main()
{
    pid_t pid;
    qid_t client_req;
    qid_t balance_req;
    qid_t server_reqs[SERVERS];

    client_req = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    balance_req = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    server_reqs[0] = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    server_reqs[1] = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    server_reqs[2] = msgget(IPC_PRIVATE, IPC_CREAT | 0664);

    for (int i = 0; i < CLIENTS; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            reqsnd(client_req);
            exit(0);
        }
    }

    pid = fork();

    if (pid == 0)
    {
        reqblnc(client_req, server_reqs);
        exit(0);
    }

    for (int i = 0; i < SERVERS; i++)
    {
        pid = fork();

        if (pid == 0)
        {
            reqrcv(server_reqs[i]);
            exit(0);
        }
    }

    for (int i = 0; i < CLIENTS+SERVERS+BALANCERS; i++)
    {
        // printf("[main]: process %s joined\n", i);
        wait(NULL);
    }

    msgctl(client_req, IPC_RMID, NULL);
    msgctl(balance_req, IPC_RMID, NULL);
    msgctl(server_reqs[0], IPC_RMID, NULL);
    msgctl(server_reqs[1], IPC_RMID, NULL);
    msgctl(server_reqs[2], IPC_RMID, NULL);

    printf("\033[1;31mExit success\n\033[0m");
    return 0;
}
