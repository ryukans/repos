#include "Coda.h"


Coda::~Coda()
{
	testa;
	Nodo* tmp;
	while (testa) {
		tmp = testa;
		testa = testa->succ;
		delete tmp;
	}
}

void Coda::push(const T& t)
{
	Nodo* n = new Nodo;
	
	n->elem = t;
	n->succ = testa->succ;
	testa = n;
}

void Coda::append(const T& t)
{
	if (testa == 0) {
		push(t);
		return;
	}

	Nodo* n = new Nodo;
	Nodo* i = testa;
	while (i->succ)
		i = i->succ;

	n->elem = t;
	n->succ = nullptr;
	i->succ = n;
}


void Coda::pop(T& t)
{
	if (testa == 0) return;

	Nodo* tmp = testa;

	t = testa->elem;
	testa = testa->succ;
	delete tmp;
}

void Coda::top(T& t)
{
	if (testa == 0) return;

	t = testa->elem;
}

