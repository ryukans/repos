#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/msg.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "../header/procedure.h"


static int rtsq, otsq;

void init_serviceq()
{
    rtsq = msgget(IPC_PRIVATE, IPC_CREAT | 0064);
    otsq = msgget(IPC_PRIVATE, IPC_CREAT | 0064);
}

void remove_serviceq()
{
    msgctl(rtsq, IPC_RMID, 0);
    msgctl(otsq, IPC_RMID, 0);
}


void syncsnd(messagebuf* msgbuf, int queue)
{
    messagebuf rtsbuf, otsbuf;

    rtsbuf.type = RTS;
    strcpy(rtsbuf.mess, "Request to send");
    msgsnd(rtsq, &rtsbuf, sizeof(messagebuf)-sizeof(long), 0);
    msgrcv(otsq, &otsbuf, sizeof(messagebuf)-sizeof(long), OTS, 0);
    msgsnd(queue, msgbuf, sizeof(messagebuf)-sizeof(long), 0);
}

void blockedrcv(messagebuf* msgbuf, int queue, int type)
{
    messagebuf rtsbuf, otsbuf;

    otsbuf.type = OTS;
    strcpy(otsbuf.mess, "Okay to send");
    msgrcv(rtsq, &rtsbuf, sizeof(messagebuf)-sizeof(long), RTS, 0);
    msgsnd(otsq, &otsbuf, sizeof(messagebuf)-sizeof(long), 0);
    msgrcv(queue, msgbuf, sizeof(messagebuf)-sizeof(long), type, 0);
}

void producer(int queue, char* txt)
{
    messagebuf msgbuf;

    msgbuf.type = MESSAGE;
    strcpy(msgbuf.mess, txt);
    syncsnd(&msgbuf, queue);
    printf("\nMessage sent: [%s]\n", msgbuf.mess);
}

void consumer(int queue)
{
    messagebuf msgbuf;

    blockedrcv(&msgbuf, queue, MESSAGE);
    printf("\nMessage recieved: [%s]\n", msgbuf.mess);
}






