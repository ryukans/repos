#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include "../header/procedure.h"

void producer(int queue, char* txt)
{
    messagebuf mbuf;

    mbuf.type = MESSAGE;
    strcpy(mbuf.mess, txt);    

    msgsnd(queue, (void*)&mbuf, sizeof(messagebuf)-sizeof(long), IPC_NOWAIT);
}

void consumer(int queue)
{
    messagebuf mbuf;

    msgrcv(queue, (void*)&mbuf, sizeof(messagebuf)-sizeof(long), MESSAGE, 0);
    msginfo(queue);
}

void msginfo(int queue)
{
    struct msqid_ds mid;

    msgctl(queue, IPC_STAT, &mid);
    char *time_sender = ctime(&mid.msg_stime);
	char *time_receiver = ctime(&mid.msg_rtime);	
	char *time_ctime = ctime(&mid.msg_ctime);
	printf("Time Sender: %sTime Receiver: %sTime Ctime: %s",time_sender,time_receiver,time_ctime);
	printf("Messages Number: %lu\n",mid.msg_qnum);
}