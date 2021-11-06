#pragma once

#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>

int wait_sem(int sem_id, int numsem);
int signal_sem(int sem_id, int numsem);


