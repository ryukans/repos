#include "../header/utils.h"

#define BUFSIZE 100
#define NSEMS 4

enum sems{
    //cooperation sems
    SPACE_AVAIL,
    VALUE_AVAIL,
    //competition sems
    MUTEX_P,
    MUTEX_C
};

typedef int value;

typedef struct buffer{
    value values[BUFSIZE];
    int head;
    int tail;
    int count;
} buffer;

void init_buffer(buffer*);
void produce(buffer*, value, int sem_id);
void producesw(buffer*, value, int sem_id);
int  consume(buffer*, int sem_id);
int  consumesw(buffer*, int sem_id);
void consume_p(buffer*, value*, int sem_id);
