#pragma once
#include <iostream>

using std::istream;
using std::ostream;

static const int MAXSIZE = 8;
static const int DIGIT = 5;
static const char DEF_NUM[MAXSIZE+1] = "XOXOXOXO";

class Carta
{
	friend istream& operator>>(istream&, Carta&);
	friend ostream& operator<<(ostream&, const Carta&);

private:
	char* tipo;
	char* intestatario;
	char* numero;
	

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Carta();
	Carta(const char*, const char*, const char*);
	Carta(const Carta&);
	~Carta();

	const Carta& operator=(const Carta&);

	void setCarta(const Carta&);
	void setTipo(const char*);
	void setIntestatario(const char*);
	void setNumero(const char*) throw (const char*);
	
	const char* getTipo() const { return tipo; }
	const char* getIntestatario() const { return intestatario; }
	const char* getNumero() const { return numero; }
	
	virtual bool check(const char*) const = 0;
};
