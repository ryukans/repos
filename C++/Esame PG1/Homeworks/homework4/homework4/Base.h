#pragma once
#include "Ordinario.h"

class Base : public Ordinario
{


public:
	Base();
	virtual float calcolaSpesa();


private:
	bool franchigia;
	int freeop;
	int canone;


};


