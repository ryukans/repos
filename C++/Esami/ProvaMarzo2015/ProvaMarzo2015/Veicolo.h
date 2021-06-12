#pragma once
#include <iostream>
#include <cstring>

using std::istream;
using std::ostream;

class Veicolo
{
	friend istream& operator>>(istream&, Veicolo&);
	friend ostream& operator<<(ostream&, const Veicolo&);

private:
	char* nome;
	char* marca;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

	virtual char* toText() const;

public:
	Veicolo();
	Veicolo(const char*, const char*);
	Veicolo(const Veicolo&);
	virtual ~Veicolo();

	const Veicolo& operator=(const Veicolo&);
	bool operator==(const Veicolo&);
	bool operator!=(const Veicolo&);


	void setNome(const char*);
	void setMarca(const char*);
	char* getNome() const { return nome; }
	char* getMarca() const { return marca; }
};
