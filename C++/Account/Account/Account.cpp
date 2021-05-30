#include "Account.h"


ContoCorrente::ContoCorrente()
{
	titolare = new char[1];
	strcpy_s(this->titolare, 1, "");

	strcpy_s(this->iban, "");

	this->saldo = 0.0F;
}

ContoCorrente::ContoCorrente(const char* titolare, const char iban[], const float saldo)
{
	int size = strlen(titolare) + 1;
	this->titolare = new char[size];
	strcpy_s(this->titolare, size, titolare);

	strcpy_s(this->iban, iban);

	this->saldo = saldo;
}

ContoCorrente::ContoCorrente(const ContoCorrente& cc)
{
	int size = strlen(cc.titolare) + 1;
	titolare = new char[size];
	strcpy_s(titolare, size, cc.titolare);

	strcpy_s(iban, len, cc.iban);

	saldo = cc.saldo;
}

ContoCorrente::~ContoCorrente()
{
	delete[] titolare;
}

const ContoCorrente& ContoCorrente::operator = (const ContoCorrente& cc)
{
	if (this != &cc) {
		delete[] titolare;
		int size = strlen(cc.titolare) + 1;
		titolare = new char[size];
		strcpy_s(titolare, size, cc.titolare);
		strcpy_s(iban, cc.iban);
		saldo = cc.saldo;
	}
	
	return *this;
}


ostream& operator << (ostream& out, const ContoCorrente& cc) 
{
    return out << cc.titolare << ' ' << cc.iban << ' ' << cc.saldo;    
}

istream& operator >> (istream& in, ContoCorrente& cc)
{
    char buffer[100];
    in.getline(buffer, 100);
	int buffsize = strlen(buffer) + 1;

	delete[] cc.titolare;   //delete in order to avoid memory leak
	cc.titolare = new char[buffsize];
    strcpy_s(cc.titolare, buffsize, buffer);
    

    in.getline(cc.iban, len);
    in >> cc.saldo;

	cin.ignore();

    return in;
}

