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
    printf("Process App 1 started\n");
    
    ipc queue;
    mess_t m_p1;

    m_p1.id_proc = P1;
    queue.key = ftok(QUEUEPATH, QUEUEID);
    queue.id = msgget(queue.key, IPC_CREAT | 0664);

    if(queue.id < 0){
        perror("msgget() failed\n");
        exit(-1);
    }
    
    srand(time(NULL));

    for(int i = 0; i < NUMMESS; i++){
        m_p1.value = genval(0, 10);
        printf("Sending message: <%lu,%f>\n", m_p1.id_proc, m_p1.value);
        msgsnd(queue.id, (void*)&m_p1, sizeof(mess_t)-sizeof(long), 0);
        sleep(1);
    }

    return 1;
}
