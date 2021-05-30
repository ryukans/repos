#pragma once
#include <iostream>
#include <cstring>

using namespace std;
static const int len = 28;

class ContoCorrente
{
	friend ostream& operator << (ostream& out, const ContoCorrente&);
	friend istream& operator >> (istream& out, ContoCorrente&);

public:
	ContoCorrente();
	ContoCorrente(const char* titolare,const char iban[],const float saldo);
	ContoCorrente(const ContoCorrente& cc);
	~ContoCorrente();

	const ContoCorrente& operator= (const ContoCorrente&);
	inline bool operator == (ContoCorrente& cc) { return  !strcmp(titolare, cc.titolare) && !strcmp(iban, cc.iban) && saldo == saldo; }
	inline bool operator != (ContoCorrente& cc) { return !(this == &cc); }
	inline void preleva(float prelievo) { saldo -= prelievo; }
	inline void accredita(float accredito) { saldo += accredito; }
	inline float getSaldo() { return saldo; }

private:
	char* titolare;
	char iban[len];
	float saldo;
};
