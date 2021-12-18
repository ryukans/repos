#include <sys/types.h>

#define MUTEX 0

enum mutexflags{LOCK, UNLOCK};

typedef struct mutex_flags{
    u_int lock: 1;
    u_int : 0;  //unlock
} flag_t;

typedef struct monitor{
    int mutex;
    flag_t mutexop;

    int ncvs;
    int semcv;

    int shmcountcv; // countcv shm id
    int* countcv;
}monitor;

void init_monitor(monitor*, int ncvs);
void remove_monitor(monitor*);
void monitorctl(monitor*);

void mutexlock(monitor*);
void mutexunlock(monitor*);
int  monitorop(monitor*, u_int op);

void condwait(monitor*, int idcv);
void condsignal(monitor*, int idcv);
int  queueconds(monitor*, int idcv);