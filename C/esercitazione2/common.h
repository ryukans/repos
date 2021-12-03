#ifndef _COMMON_
#define _COMMON_

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

#define BUFFER_DIM 10
#define N_MSG 15
#define MSGSZ(x) sizeof(x)-sizeof(long)

/* Definizione Tipi di Messaggi*/
//TODO
enum msg_type{
    QUEUE_REQ = 1,
    PRINT_REQ,
    EXIT_REQ
};

/* Definizione Messaggio Richiesta del Client */
typedef struct message {
    long type;
    pid_t pid;
} mex_client;


/* Definizione Messaggio Richiesta del Server, contenente il buffer */

typedef pid_t msg[BUFFER_DIM];

typedef struct messagebuf{
   long type;
   msg pids;
   
} mex_server;


/* Prototipi delle funzioni dei processi */
void printer(int msgq_print);
void server(int msgq_guest, int msgq_print);
void client(int msgq_guest);

#endif