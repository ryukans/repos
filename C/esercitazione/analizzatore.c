/*PROCESSO ANALIZZATORE*/
#include "sem.h"
#include "procedure.h"

void analizza(buffer* buf)
{
    if(buf->riemp == 0){
        printf("Strnga vuota\n");
        exit(EXIT_ANALIZZATORE);
    }

    int i;
    for(i = buf->index; i > 0; i--)
        putchar(buf->line[i]);
}
 
int main()
{
    key_t keyshm = ftok(".", 'a');
    key_t keysem = ftok(".", 'b');
    int shmid = shmget(keyshm, sizeof(buffer), IPC_CREAT | 0664);
    int semid = semget(keysem, NUMSEM, IPC_CREAT | 0664);
    buffer* buf = (buffer*) shmat(shmid, NULL, 0);

    iniziolettura(semid, buf);

    sleep(2);
    analizza(buf);

    finelettura(semid, buf);

    return EXIT_ANALIZZATORE;
}