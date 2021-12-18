#pragma once 

#include "../header/utils.h"

#define BUFSIZE 5

#define NSEMS 4

enum sems{
    SPACE_AVAIL,
    VALUE_AVAIL,
    MUTEX_P,
    MUTEX_C
};

enum status_flas{
    EMPTY,
    IN_USE,
    FULL
};

typedef int value;

typedef struct {
    value values[BUFSIZE];
    int status[BUFSIZE];
   
} buffer;



void produce(buffer*, value, int semid);
value consume(buffer*, int semid);
void consumep(buffer*, value*, int semid);