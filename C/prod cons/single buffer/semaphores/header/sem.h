#ifndef _SEM_H_
#define _SEM_H_

#include "../header/utils.h"
#include <errno.h>
#include <sys/types.h>

int waitsem(int semid, int semnum);
int signalsem(int semid, int numsem);

#endif