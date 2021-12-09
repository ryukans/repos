#pragma once

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int waitsem(int sem_id, int numsem);
int signalsem(int sem_id, int numsem);


