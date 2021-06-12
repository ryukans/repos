#pragma once
#include "Bolletta.h"

typedef Bolletta* B;

class ListaBollette
{
private:
	struct Nodo {
		B bolletta;
		Nodo* succ;
	};
	Nodo* testa;


public:
	ListaBollette() : testa(nullptr) {};
	~ListaBollette();

	bool push(const B&);
	void push(Nodo*&, const B&);
	bool insert(const B&);
	void insert_r(Nodo*&, const B&);
	bool append(const B&);
	bool pop(B&);
	bool top(B&) const;
	bool empty() const { return testa == 0; }
	bool full() const { return false; }
	bool esiste(const B&);
};
