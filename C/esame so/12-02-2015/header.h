#include <pthread.h>

#define MAXOPS 4
#define BUFSIZE 5

enum status_flags{FREE, IN_USE, FULL};

typedef int op;

typedef struct{
	op ops[MAXOPS];
	int nops;
} buffer;

typedef struct elab_monitor{
	buffer elabs[BUFSIZE];
	int status[BUFSIZE];
	int nfree;
	int nfull;

	pthread_mutex_t mutex;
	pthread_cond_t cvprod;
	pthread_cond_t cvcons;
} ElabMonitor;


void* Requestor(void*);
void* Elaborator(void*);

void init_monitor(ElabMonitor*);
void remove_monitor(ElabMonitor*);

//produce
void setop(ElabMonitor*, int nops);
//consume
int getsumop(ElabMonitor*);

int	 pstart(ElabMonitor*);
void pstop(ElabMonitor*, int index);
int	 cstart(ElabMonitor*);
void cstop(ElabMonitor*, int index);
