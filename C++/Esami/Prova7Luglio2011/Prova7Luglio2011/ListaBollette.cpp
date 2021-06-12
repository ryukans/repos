#include "ListaBollette.h"



ListaBollette::~ListaBollette()
{
}

bool ListaBollette::push(const B& b)
{
	if (full()) return false;

	Nodo* n = new Nodo;

	n->bolletta = b;
	n->succ = testa;
	testa = n;
	
	return true;
}

void ListaBollette::push(Nodo*& t, const B& b) 
{
	if (full()) return;

	Nodo* n = new Nodo;

	n->bolletta = b;
	n->succ = t;
	t = n;
}

bool ListaBollette::insert(const B& b)
{
	if (full()) return false;

	// TODO controllo dubplicati

	const char* _this = testa->bolletta->getCodiceCliente();
	const char* other = b->getCodiceCliente();
	if (!testa || strcmp(other, _this) < 0)
		push(b);

	Nodo* prec = testa;
	while (prec->succ && strcmp(b->getCodiceCliente(), testa->bolletta->getCodiceCliente()) < 0)
		prec = prec->succ;

	Nodo* n = new Nodo;

	n->bolletta = b;
	n->succ = prec->succ;
	prec->succ = n;

	return true;
}

void ListaBollette::insert_r(Nodo*& t, const B& b)
{
	if (full()) return;

	// TODO controllo dubplicati

	const char* _this = t->bolletta->getCodiceCliente();
	const char* other = b->getCodiceCliente();
	if (!testa || strcmp(other, _this) < 0)
		push(t, b);
	else
		insert_r(t->succ, b);
}

bool ListaBollette::append(const B& b)
{
	if (empty()) push(b);

	Nodo* n = new Nodo;
	Nodo* tmp = testa;
	
	while (tmp->succ)
		tmp = tmp->succ;

	n->bolletta = b;
	n->succ = nullptr;
	tmp->succ = n;

	return true;
}

bool ListaBollette::pop(B& b)
{
	if (empty())
		return false;

	Nodo* tmp = testa;

	b = testa->bolletta;
	testa = testa->succ;
	delete tmp;

	return true;
}

bool ListaBollette::top(B& b) const
{
	if (empty())
		return false;

	b = testa->bolletta;
	
	return true;
}

bool ListaBollette::esiste(const B& b)
{
	if (empty())
		return false;

	Nodo* curr = testa;
	while (curr) {
		if (!strcmp(b->getCodiceCliente(), curr->bolletta->getCodiceCliente()))
			return true;
		curr = curr->succ;
	}
	return false;
}
