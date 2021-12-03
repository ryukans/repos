#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/msg.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <errno.h>

#include "header.h"

void checksum(int queue_filter_checksum, int queue_checksum_visual){

        int ret, i, j, checksum;
        message mess;
        int sum;

        for (j=0; j<NUM_MESSAGES; j++){

                printf("[checksum] Ricevo dal processo Filter...\n");

                ret = msgrcv(queue_filter_checksum, (void*)&(mess), sizeof(message)-sizeof(long), 0, 0);
            
                if(ret<0) {
                        if (errno == ENOMSG){
                                printf("Non ci sono più messaggi da ricevere dal processo filter...exit!\n");
                                break;
                        }
                        else{
                                perror("ERROR!!!");
                                exit(-1);
                        }
                }
                /* TODO: Calcolare la checksum e inviarla al visualizzatore  */
                if(mess.type == MSG_TYPE){
                        /* lavora solo se type == MSG_TYPE, 
                        tale condizione è vera se e sole se il filtro non ha rilevato il carattere 'x'*/

                        i = 0, sum = 0;
                
                        for (i = 0; i < STRING_MAX_DIM; i++){
                                sum += (int) mess.string[i];
                        }
        
                        sum += mess.intarray[0];
                        sum += mess.intarray[1];
                        
                        mess.var = sum;
                        //mess.type = MSG_TYPE; ??
                       
                }
                printf("[checksum] Invio messaggio di CHECKSUM al Visualizzatore...\n");
                msgsnd(queue_checksum_visual, (void*)&(mess), sizeof(message)-sizeof(long), 0);

        
        }
        
        exit(0);
}

