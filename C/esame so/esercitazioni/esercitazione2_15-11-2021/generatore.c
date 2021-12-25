/*PROCESSO GENERATORE*/
#include "sem.h"
#include "procedure.h"
#include <time.h>

void genera(buffer* buf)
{
    if (buf->index > riemp){
        perror("Impossibile aggiornare\n");
        exit(EXIT_FAILURE);
    }

    char c = 'a' + (rand()%26);

    buf->line[(buf->index)++] = c;
}

int main()
{
    key_t keyshm = ftok(".", 'a');
    key_t keysem = ftok(".", 'b');
    int shmid = shmget(keyshm, sizeof(buffer), IPC_CREAT | 0664);
    int semid = semget(keysem, NUMSEM, IPC_CREAT | 0664);
    buffer* buf = (buffer*) shmat(shmid, NULL, 0);

    inizioscrittura(semid);

    srand(time(NULL));
    sleep(1);
    genera(buf);

    finescrittura(semid);

	return EXIT_GENERATORE;
}