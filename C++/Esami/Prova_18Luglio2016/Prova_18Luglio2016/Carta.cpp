#include "Carta.h"
#include <cstring>


Carta::Carta() : tipo(new char[1]), intestatario(new char[1]), numero(new char[MAXSIZE+1])
{
	strcpy_s(tipo, 1, "");
	strcpy_s(intestatario, 1, "");
	strcpy_s(numero, MAXSIZE+1, DEF_NUM);
}


Carta::Carta(const char* _tipo, const char* _intestatario, const char* _numero) : numero(new char[MAXSIZE+1])
{
	setTipo(_tipo);
	setIntestatario(_intestatario);
	try
	{
		setNumero(_numero);
	}
	catch (const char* err_msg)
	{
		std::cerr << err_msg << std::endl;
		strcpy_s(numero, MAXSIZE + 1, DEF_NUM);
	}
}

Carta::Carta(const Carta& C) {
	setCarta(C);
}

Carta::~Carta()
{
	delete[] tipo;
	delete[] intestatario;
	delete[] numero;
}

const Carta& Carta::operator=(const Carta& C)
{
	if (this != &C)
		setCarta(C);

	return *this;
}

void Carta::setCarta(const Carta& C)
{
	setTipo(C.tipo);
	setIntestatario(C.intestatario);
	setNumero(C.numero);
}

void Carta::setTipo(const char* _tipo)
{
	int len = strlen(_tipo) + 1;

	delete[] tipo;
	tipo = new char[len];
	strcpy_s(tipo, len, _tipo);
}

void Carta::setIntestatario(const char* _intestatario)
{
	int len = strlen(_intestatario) + 1;

	delete[] intestatario;
	intestatario = new char[len];
	strcpy_s(intestatario, len, _intestatario);
}

void Carta::setNumero(const char* _numero) throw (const char*)
{
	int len = strlen(_numero);
	if (len != MAXSIZE)
		throw ("Errore: numero carta deve essere di 8 cifre !\n");
	

	for (int i = 0; i < DIGIT; i++)
	{
		if (!isdigit(_numero[i]))
			throw ("Errore: prime 5 cifre del numero di carta devono essere solo numeri !\n");
	}	

	delete[] numero;
	numero = new char[len+1];
	strcpy_s(numero, len+1, _numero);
}


istream& Carta::input(istream& in)
{
	char buffer[100];

	in.getline(buffer, 100);
	setTipo(buffer);

	in.getline(buffer, 100);
	setIntestatario(buffer);

	in.getline(buffer, 100);
	setNumero(buffer);

	return in;
}

ostream& Carta::output(ostream& out) const {
	return out << "Tipo carta: " << tipo << "\nIntestatario: " << intestatario << "\nNumero: " << numero << std::endl;
}


istream& operator>>(istream& in, Carta& C) {
	return C.input(in);
}


ostream& operator<<(ostream& out, const Carta& C) {
	return C.output(out);
}