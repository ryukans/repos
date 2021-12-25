#include "common.h"

void printer(int msgq_print)
{
	int counter = 1, i;
	//TODO definizione messaggio da ricevere
	serverbuf msg_s;
	
	printf("[printer] Printer Ready...\n");

	while(1)
	{
		//TODO ricezione messaggio contenente il buffer
		msgrcv(msgq_print, &msg_s, sizeof(serverbuf)-sizeof(long), PRINTER_T, 0);
		
		for(i=0; i<BUFFER_DIM; i++)
		{
			// TODO se in posizione i-ma del buffer c'è un pid -1 il printer deve terminare
			if(msg_s.mess[i] < 0)
				_exit(-1);

			printf("{printer}\t[%u] %u\n", counter++, msg_s.mess[i]);
		}
	}
}
