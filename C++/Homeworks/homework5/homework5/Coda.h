#pragma once
#include "Veicolo.h"

typedef Veicolo* T;

class Coda
{
	struct Nodo {
		T elem;
		Nodo* succ;
	};

private:
	Nodo* testa;

public:
	Coda() : testa(nullptr) {};
	~Coda();

	void push(const T&);
	void append(const T&);
	void pop(T&);
	void top(T&);
};
