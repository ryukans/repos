#include "stack.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void StackInit(Stack * s, int dim) 
{
	s->dati = (Elem*)malloc(sizeof(Elem)*dim);
	s->testa = 0;
	s->dim = dim;
}


void StackRemove(Stack * s) 
{
	pthread_mutex_destroy(&s->mutex);
	pthread_cond_destroy(&s->cvpush);
	pthread_cond_destroy(&s->cvpop);
}

void StackPush(Stack * s, Elem e) 
{
	pthread_mutex_lock(&s->mutex);

	while(s->testa == s->dim){
		printf("Error: stack is full!\n");
		pthread_cond_wait(&s->cvpush, &s->mutex);
	}

	s->dati[s->testa++] = e;

	pthread_cond_signal(&s->cvpop);

	pthread_mutex_unlock(&s->mutex);
}


Elem StackPop(Stack * s)
{
	int elemento;

	pthread_mutex_lock(&s->mutex);

	while(s->testa == 0){
		printf("Error: stack is empty!\n");
		pthread_cond_wait(&s->cvpop, &s->mutex);
	}

	elemento = s->dati[s->testa--];

	pthread_cond_signal(&s->cvpush);

	pthread_mutex_unlock(&s->mutex);

	return elemento;
}

int StackSize(Stack * s)
{
	int size;

	pthread_mutex_lock(&s->mutex);

	size = s->testa;	

	pthread_mutex_unlock(&s->mutex);

	return size;
}
