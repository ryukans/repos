#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#include "procedure.h"

void init_buffer(Buffer* buf)
{
    buf->readers = buf->writers = 0;
	buf->weather.humidity = buf->weather.rain = buf->weather.temp = DEFAULT;
}

void startr(Monitor* m, Buffer * buf)
{	
    enter_monitor(m);

    while(buf->writers > 0)
        wait_condition(m, SYNCHR);
    buf->readers++;
    
    signal_condition(m, SYNCHR);

    leave_monitor(m);
}

void endr(Monitor* m, Buffer * buf)
{
    enter_monitor(m);

    buf->readers--;
    if(buf->readers == 0)
        signal_condition(m, SYNCHW);

    leave_monitor(m);
}

//Procedure di inizio e fine scrittura

void startw(Monitor* m,Buffer*buf)
{
    enter_monitor(m);

    while(buf->readers > 0 || buf->writers > 0)
        wait_condition(m, SYNCHW);
    buf->writers++;

    leave_monitor(m);
}

void endw(Monitor* m, Buffer*buf)
{
    enter_monitor(m);

    buf->writers--;
    if(queue_condition(m, SYNCHW))
        signal_condition(m, SYNCHW);
    else
        signal_condition(m, SYNCHR);

    leave_monitor(m);
}

void Servizio(Monitor* m, Buffer * buf)
{
	int i;
	srand(time(NULL));

	for(i = 0; i < 20; i++){

		/* TBD: Richiamare InizioScrittura e FineScrittura */
		startw(m, buf);

		buf->weather.temp 	  = rand()%101-50;
		buf->weather.humidity = rand()%101;
		buf->weather.rain	  = rand()%2;

		printf("<%d> scrittura: Temperatura=%d, Umidità=%d, Pioggia=%s\n", getpid(), buf->weather.temp, buf->weather.humidity, (buf->weather.rain ? "si" : "no") );

		endw(m, buf);

		sleep(2);
	}
}

void Utente(Monitor* m, Buffer * buf) {

	int i;
	for(i = 0; i < 10; i++){
		
		/* TBD: Richiamare startr e FineLettura */
		startr(m, buf);

		printf("<%d> lettura: Temperatura=%d, Umidità=%d, Pioggia=%s\n", getpid(), buf->weather.temp, buf->weather.humidity, (buf->weather.rain ? "si" : "no") );

		endr(m, buf);
		
		sleep(1);
	}
}


