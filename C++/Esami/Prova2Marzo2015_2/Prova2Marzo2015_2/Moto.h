#pragma once
#include "Veicolo.h"

class Moto : public Veicolo
{
	friend istream& operator>>(istream& in, Moto& _this) { return _this.input(in); }
	friend ostream& operator<<(ostream& out, const Moto& _this) { return _this.output(out); }

private:
	char* tipo;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;
	//virtual const char* toText() const;

public:
	Moto();
	Moto(const char*, const char*, const char*);
	Moto(const Moto&);
	~Moto() { delete[] tipo; }

	const Moto& operator=(const Moto&);
	bool operator==(const Moto&) const;
	bool operator!=(const Moto&) const;
	
	void setTipo(const char*);

	const char* getTipo() const { return tipo; }
};


