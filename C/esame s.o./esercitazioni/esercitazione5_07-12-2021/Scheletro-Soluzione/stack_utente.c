#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define NUM_THREADS 5
#define NUM_INS 4
#define NUM_PREV 10
#define DIM 15

void *Inserisci(void * s)
{

	int i;
	Elem v;
    
    Stack * stack = (Stack *) s;

	for(i = 0; i < NUM_INS; i++) {
		v = rand() % 11;
		StackPush(stack, v);
		printf("Inserimento: %d\n", v);
		sleep(1);
	}

	// Terminazione thread
	pthread_exit(NULL);
}


void *Preleva(void * s)
{

	int i;
	Elem v1, v2;

    Stack * stack = (Stack *) s;
    
	for(i = 0; i < NUM_PREV; i++) {
		v1=StackPop(stack);
		printf("Prelievo: %d\n", v1);

		v2=StackPop(stack);
		printf("Prelievo: %d\n", v2);

		printf("Somma: %d\n", v1+v2);

		sleep(3);
	}

	// Terminazione thread
	pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
	// Istanziamo i thread
	pthread_attr_t attr;
	pthread_t threads[NUM_THREADS];

	int i;

	srand(time(NULL));

	// Istanziamo lo stack
	Stack* stack = malloc(sizeof(Stack));
	StackInit(stack, DIM);

	// Attributi thread
	pthread_mutex_init(&stack->mutex, NULL);
	pthread_cond_init(&stack->cvpush, NULL);
	pthread_cond_init(&stack->cvpop, NULL);
	pthread_attr_init(&attr);
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);


	for(i = 0; i < NUM_THREADS; i++){
		// Creazione thread per l'inserimento
		printf("Inserimento...\n");
		pthread_create(&threads[i], &attr, Inserisci, (void*)stack);
	}

	putchar('\n');

	// Creazione thread per il prelievo
	pthread_create(&threads[5], &attr, Preleva, (void*)stack);
	
	putchar('\n');
	
	for(i = 0; i < 6; i++){
		// Attesa terminazione thread
		printf("Thread %d terminato\n", i);
		pthread_join(threads[i], NULL);
	}

	pthread_attr_destroy(&attr);
	// Rimozione stack
	StackRemove(stack);
	free(stack);

	pthread_exit(NULL);
}

