#include "common.h"
#include <sys/wait.h>

#define N_CLIENT 5

static int msgq_guest;
static int msgq_print;

int main()
{
    mex_client mc;
    mex_server ms;

    int i;
    int msgq_guest = msgget(IPC_PRIVATE, IPC_CREAT | 0664);
    int msgq_print = msgget(IPC_PRIVATE, IPC_CREAT | 0664);


    /*Creazione processo printer*/
    pid_t pid = fork();
    if(pid == 0){
        printer(msgq_print);
        _exit(0);
    }

    /*creazione del processo server*/
    pid = fork();
    if(pid == 0){
        server(msgq_guest, msgq_print);
        _exit(0);
    }

    /*Creazione processi client*/
    for (i = 0; i < N_CLIENT; i++){
        if(!fork()){
            printr(msgq_print);
            _exit(0);
        }
    }
    
    /*Attesa terminazione client*/
    for (i = 0; i < N_CLIENT; i++){
        wait(0);
    }
    
    /*Invio messaggio di terminazione del server*/
    mex_client exit = {.type = EXIT_REQ};
    msgsnd(msgq_guest, (void*)&exit, MSGSZ(mex_client), 0);


    /*Attesa terminazione processi server e printer*/

    for (i = 0; i < 2; i++){
        wait(0);
    }

    msgctl(msgq_guest, IPC_RMID, 0);
    msgctl(msgq_print, IPC_RMID, 0);
    

    /*Rimozione strutture IPC e uscita*/

}