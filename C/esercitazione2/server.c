#include "common.h"
#include <stdio.h>

void server(int msgq_guest, int msgq_print)
{
	int i;
	
	/* TODO Definizione Messaggio da ricevere dal proc. client */
    mex_client m;

	/* TODO Definizione Messaggio da inviare al proc. printer */
    mex_server mbuf;

	printf("[server ] Server ready...\n");
	while(1){
		for(i=0; i<BUFFER_DIM; i++){
			/*TODO Ricezione del messaggio di richiesta*/
            msgrcv(msgq_guest, (void*)&m, MSGSZ(mex_client), QUEUE_REQ, 0);
			
			/*TODO se il messaggio è di tipo fine, inserisce -1 in posizione i-ma e termina*/
            if(m.type == EXIT_REQ){
                mbuf.pids[i] = -1;
                i = BUFFER_DIM;
            }
            /*TODO Accodamento della richiesta nel buffer */
            else
                mbuf.pids[i++] = m.pid;
		}
		
	    /*TODO Invio del messaggio con il buffer completo al proc. printer */
        mbuf.type = PRINT_REQ;
		msgsnd(msgq_print, (void*)&mbuf, MSGSZ(mex_server), IPC_NOWAIT);
        exit(0);
	}
}