#pragma once
#include <iostream>
#include <cstring>

using std::ostream;
using std::istream;

class Veicolo
{
	friend istream& operator>>(istream&, Veicolo&);
	friend ostream& operator<<(ostream&, const Veicolo&);

private:
	char* tipo;
	char* marca;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Veicolo();
	Veicolo(const char*, const char*);
	Veicolo(const Veicolo&);
	~Veicolo();

	const Veicolo& operator = (const Veicolo&); 
	bool operator == (const Veicolo&) const;
	bool operator != (const Veicolo&) const;

	void setTipo(const char*);
	void setMarca(const char*);
	const char* getTipo() const {return tipo;}
	const char* getMarca() const {return marca;}

	virtual float calcolaPedaggio() = 0;
	
};
