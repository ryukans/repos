#ifndef _COMMON_
#define _COMMON_

#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define QPATH "."
#define QID 'Q'
#define BUFFER_DIM 10

/* Definizione Tipi di Messaggi*/
//TODO

typedef pid_t msg_t;

/* Definizione Messaggio Richiesta del Client */
//TODO
typedef struct {
	long type;
	msg_t mess;
}clientbuf;

/* Definizione Messaggio Richiesta del Server, contenente il buffer */

typedef msg_t msgbuf[BUFFER_DIM];

//TODO
typedef struct {
	long type;
	msgbuf mess;
}serverbuf;

enum types{EXIT_T = 1, CLIENT_T, SERVER_T, PRINTER_T};

/* Prototipi delle funzioni dei processi */
void printer(int msgq_print);
void server(int msgq_guest, int msgq_print);
void client(int msgq_guest);

#endif
