#include "common.h"

void client(int msgq_guest)
{
	int i;

	/* Inizializzazione Messaggio del processo */
	mex_client m;
    m.type = QUEUE_REQ;

	/* Invio dei 15 messaggi in ciclo, con sleep(1) tra un messaggio e l'altro*/
	for (i = 0; i < N_MSG; i++){
        sleep(1);
        m.pid = getpid();
        msgsnd(msgq_guest, (void*)&m, MSGSZ(mex_client), IPC_NOWAIT);
    }
}