#ifndef __HEADER
#define __HEADER

#define N 5

#define NSEMS 3
#define CONS 0
#define PROD 1
#define MUTEXP 2

#define PATHNAME "."
#define SHMID 'A'
#define SEMID 'B'

typedef struct{
	int elementi[N];
	int testa;
	int coda;
} Buffer;


void waitsem(int semid, int semnum);
void waitnsem(int semid, int semnum, int nops);
void signalsem(int semid, int semnum);
void signalnsem(int semid, int semnum, int nops);

void produci_elemento(int semid, Buffer* buf);
void consuma_elementi(int semid, Buffer* buf);

#endif
