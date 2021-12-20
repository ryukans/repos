#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>

#include "header.h"

int main(int argc, char const *argv[])
{
    printf("Process App 3 started\n");
    
    ipc queue;
    mess_t m_r;
    T cum_avg[2];
    int nmess;

    queue.key = ftok(QUEUEPATH, QUEUEID);
    queue.id = msgget(queue.key, IPC_CREAT | 0664);

    printf("Queue id: %d\n", queue.id);

    if(queue.id < 0){
        perror("msgget() failed\n");
        exit(-3);
    }
    
    nmess = NUMMESS*2;
    for(int i = 0; i < nmess; i++){
        msgrcv(queue.id, (void*)&m_r, sizeof(mess_t)-sizeof(long), 0, 0);
        printf("Message recieved form proccess <%lu>, w\\ val: <%f>\n", m_r.id_proc, m_r.value);
        if(m_r.id_proc == P1){
            cum_avg[P1-1]+=m_r.value/NUMMESS;
        }
        else if(m_r.id_proc == P2){
            cum_avg[P2-1]+=m_r.value/NUMMESS;
        }
        else{
            printf("Process unknown\n");
        }
    }
    
    for(int i = 0; i < 2; i++)
        printf("Avg %d = %f\n", i+1, cum_avg[i]);


    return 3;
}
