#pragma once
#include <iostream>

using std::istream;
using std::ostream;

class Veicolo
{
	friend istream& operator>>(istream& in, Veicolo& _this) { return _this.input(in); }
	friend ostream& operator<<(ostream& out, const Veicolo& _this) { return _this.output(out); }

private:
	char* nomeTipo;
	char* marca;

	void setNomeTipo(const char*);
	void setMarca(const char*);

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;
	//virtual const char* toText() const;

public:
	Veicolo();
	Veicolo(const char*, const char*);
	Veicolo(const Veicolo&);
	virtual ~Veicolo();

	const Veicolo& operator=(const Veicolo&);
	bool operator==(const Veicolo&) const;
	bool operator!=(const Veicolo&) const;

	const char* getNomeTipo() const { return nomeTipo; }
};

