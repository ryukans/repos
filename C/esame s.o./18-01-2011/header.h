#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define CLIENTS 8
#define BALANCERS 1
#define SERVERS 3
#define REQUESTS 15 /* total client message requests */
#define SENDRATE 1  /* client message requests send rate in seconds */

#define MSGSZ(x) sizeof(x)-sizeof(long)

enum types{CLIENT_T, BALANCE_T, SERVER_T};  /* message types */

typedef int qid_t;    /* queue id type */

typedef struct message{
    long type;
    pid_t pid;
} msg_t;

void reqsnd(qid_t); 
void reqblnc(qid_t, qid_t[]);
void reqrcv(qid_t);