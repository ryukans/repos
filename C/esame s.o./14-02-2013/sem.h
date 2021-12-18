#pragma once

#include <stdlib.h>
#include <unistd.h>
#include <sys/sem.h>
#include <sys/types.h>
#include <sys/ipc.h>


void waitsem(int numsem, int idsem);
void signalsem(int numsem, int idsem);