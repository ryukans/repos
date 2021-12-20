#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "header.h"

int main(int argc, char const *argv[])
{
    printf("Process App 2 started\n");
    
    ipc queue;
    mess_t m_p2;

    m_p2.id_proc = P2;
    queue.key = ftok(QUEUEPATH, QUEUEID);
    queue.id = msgget(queue.key, IPC_CREAT | 0664);

    if(queue.id < 0){
        perror("msgget() failed\n");
        exit(-2);
    }
    
    srand(time(NULL));

    for(int i = 0; i < NUMMESS; i++){
        m_p2.value = genval(2, 20);
        printf("Sending message: <%lu,%f>\n", m_p2.id_proc, m_p2.value);
        msgsnd(queue.id, (void*)&m_p2, sizeof(mess_t)-sizeof(long), 0);
        sleep(2);
    }

    return 2;
}