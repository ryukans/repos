#include "../../sem/header/sem.h"
#include <sys/types.h>

#define NSEMS 4
#define DEFAULT 0

enum sems{
    MUTEXR,
    MUTEXW,
    SYNCHRW,
    MUTEX
};

typedef int mess_t;

typedef struct{
    mess_t mess;
    int nreaders;
    int nwriters;
} buffer;

typedef struct pid_type{
    key_t key;
    id_t id;  
} pid;

void init_buffer(buffer*);
mess_t _read(buffer*, id_t semid);
void write(buffer*, mess_t, id_t semid);
