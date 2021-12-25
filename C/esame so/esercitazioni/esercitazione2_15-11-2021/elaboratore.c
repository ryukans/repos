/*ELABORATORE*/
#include "procedure.h"
#include "sem.h"
#include <sys/sem.h>

void elabora(buffer* buf)
{
    if(buf->riemp == 0){
        printf("Strnga vuota\n");
        exit(EXIT_ELABORATORE);
    }

    int i;
    char c;
    for(i = 0; i < buf->riemp; i++){
        c = buf->line[i] - 32;
        putchar(c);
    }
}

int main()
{
    key_t keyshm = ftok(".", 'a');
    key_t keysem = ftok(".", 'b');
    int shmid = shmget(keyshm, sizeof(buffer), IPC_CREAT | 0664);
    int semid = semget(keysem, NUMSEM, IPC_CREAT | 0664);
    buffer* buf = (buffer*) shmat(shmid, NULL, 0);

    iniziolettura(semid, buf);

    sleep(1);
    elabora(buf);

    finelettura(semid, buf);
}