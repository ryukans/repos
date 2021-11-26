#include "common.h"

void printer(int msgq_print)
{
	int counter = 1, i;
	//TODO definizione messaggio da ricevere
    mex_server mbuf;

	printf("[printer] Printer Ready...\n");

	while(1)
	{
		//TODO ricezione messaggio contenente il buffer
        msgrcv(msgq_print, (void*)&mbuf, MSGSZ(mex_server), PRINT_REQ, 0);
		
		for(i=0; i<BUFFER_DIM; i++){
			// TODO se in posizione i-ma del buffer c'è un pid -1 il printer deve terminare
            mbuf.pids[i] == EXIT_REQ ? i = BUFFER_DIM : printf("{printer}\t[%u] %u\n", counter++, mbuf.pids[i++]);
		}
        _exit(0);
	}
}