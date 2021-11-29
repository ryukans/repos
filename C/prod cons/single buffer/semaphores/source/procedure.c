#include "../header/procedure.h"
#include "../header/sem.h"

void producer(int* data, int sem)
{
    waitsem(sem, AVAIL_SPACE);

    sleep(2);
    *data = rand()%100;

    signalsem(sem, AVAIL_MSG);
}

void consumer(int* data, int sem)
{
    waitsem(sem, AVAIL_MSG);

    sleep(2);
    printf("Consumer used data: %d\n", *data);

    signalsem(sem, AVAIL_SPACE);
}