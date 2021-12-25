#include "../header/viewer.h"

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void recieve(qid_t src)
{
	int res;
	msg_t msg;

	msgrcv(src, (void*)&msg, sizeof(msg_t)-sizeof(long), 0, 0);
	if(res < 0){
		perror("recieve error: msgrcv() failed\n");
		exit(-1);
	}
	
	printf("\n[VIEWER]: message from host:\n%s\n", msg.buffer);
}