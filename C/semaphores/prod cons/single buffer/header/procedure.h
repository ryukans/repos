#pragma once

#include "../header/utils.h"

#define NUMSEM 2
#define AVAIL_SPACE 0
#define AVAIL_MSG 1

typedef int T;

void producer(T* shmptr, int sem);
void consumer(T* shmptr, int sem);
