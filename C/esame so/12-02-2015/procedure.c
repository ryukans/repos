#include "header.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

void init_monitor(ElabMonitor* m)
{
	pthread_mutex_init(&m->mutex, NULL);
    pthread_cond_init(&m->cvprod, NULL);
    pthread_cond_init(&m->cvcons, NULL);

    m->nfree = BUFSIZE;
	m->nfull = 0;
    for(int i = 0; i < BUFSIZE; i++){
        for(int j = 0; j < MAXOPS; j++)
            m->elabs[i].ops[j] = 0;
        m->elabs[i].nops = 0;
        m->status[i] = FREE;
    }
}

void remove_monitor(ElabMonitor* m)
{
	pthread_mutex_destroy(&m->mutex);
	pthread_cond_destroy(&m->cvprod);
	pthread_cond_destroy(&m->cvcons);
}

int pstart(ElabMonitor* m)
{
    pthread_mutex_lock(&m->mutex);

    while(m->nfree == 0)
        pthread_cond_wait(&m->cvprod, &m->mutex);

    int index = 0;

    while(index < BUFSIZE && m->status[index] != FREE)
        ++index;
    m->status[index] = IN_USE;
    m->nfree--;

    pthread_mutex_unlock(&m->mutex);

    return index;
}

void pstop(ElabMonitor* m, int index)
{
    pthread_mutex_lock(&m->mutex);

    m->status[index] = FULL;
    m->nfull++;
    pthread_cond_signal(&m->cvcons);

    pthread_mutex_unlock(&m->mutex);
}

int cstart(ElabMonitor* m)
{
	int i, index, min, nops;

    pthread_mutex_lock(&m->mutex);

    while(m->nfull == 0)
        pthread_cond_wait(&m->cvcons, &m->mutex);
    
    min = MAXOPS+1;
    i = index = nops = 0;
    while(i < BUFSIZE){
        nops = m->elabs[i].nops;
        if(m->status[i] == FULL && nops < min){
            min = nops;
            index = i;
        }
        ++i;
    }
    m->status[index] = IN_USE;
    m->nfull--;

    pthread_mutex_unlock(&m->mutex);

    return index;
}

void cstop(ElabMonitor* m, int index)
{
    pthread_mutex_lock(&m->mutex);

    m->status[index] = FREE;
    m->nfree++;
    pthread_cond_signal(&m->cvprod);

    pthread_mutex_unlock(&m->mutex);
}

//produce()
void setop(ElabMonitor* m, int nops)
{
	int index, op;
	
	index = pstart(m);

	op = 0;
	for(int i = 0; i < nops; i++){
		op = rand()%10+1;
		m->elabs[index].ops[i] = op;
		//printf("[DEBUG] - operand %d generated\n", op);
	}
	m->elabs[index].nops = nops;

	printf("[SETOP] - Operands generated:\n");
	for(int i = 0; i < nops; i++)
		printf("%d ", m->elabs[index].ops[i]);

	putchar('\n');
	
	pstop(m, index);
}

//consume()
int getsumop(ElabMonitor* m)
{
	int index, nops, sumop;

	index = cstart(m);

	printf("[GETSUMOP] - Sum of operands:\n");
	nops = m->elabs[index].nops;
	for(int i = 0; i < nops; i++)
		printf("%d ", m->elabs[index].ops[i]);
	
	putchar('\n');

	sumop = 0;
	for(int i = 0; i < nops; i++)
		sumop += m->elabs[index].ops[i];

	cstop(m, index);

	return sumop;
}
