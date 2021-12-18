#include "sem.h"
#include "procedure.h"
#include <time.h>

int main()
{
    srand(time(NULL));

    key_t keyshm = ftok(".", 'a');
    int shmid = shmget(keyshm, sizeof(Buffer), IPC_CREAT | 0664);
    Buffer* buf;
    buf->index = 0;
    buf->riemp = (11+rand()%(SIZE+1));
    
    key_t keysem = ftok(".",'b');
    int semid = semget(keysem, NUMSEM, IPC_CREAT | 0664);
    semctl(semid, MUTEXL, SETVAL, 1);
    semctl(semid, SYNCH, SETVAL, 1);


    int nscrittori = 1;
    int nlettori = 2;
    int nprocessi = nlettori + nscrittori;


    pid_t pid;
    int i, status;
    
    for(i = 0; i < nprocessi; i++){
        pid = fork();

        if(pid == 0){
            if(i == 0) { 
                printf("Generatore\n");
                execl("./generatore", "./generatore", NULL);
            }
            if ((i%2 == 0)){
                printf("Elaboratore\n");
                execl("./elaboratore", "./elaboratore", NULL);
            }
            else{
                printf("Analizzatore\n");
                execl("./analizzatore", "./analizzatore", NULL);
            }
            exit(0);
        }
    }
    
    for (i = 0; i < nprocessi; i++){
        pid = wait(&status);
        
        if(pid == -1)
            perror("Errore\n");
        else
            printf("Processo figlio [%d] terminato: %d\n", pid, status);
    }
    
    //dealloco mem e semafori
    shmctl(shmid, IPC_RMID, NULL);
    semctl(semid, 0, IPC_RMID);

    return 0;
}
