#pragma once
#include <iostream>

using std::istream;
using std::ostream;

class Bolletta
{
	friend istream& operator>>(istream&, Bolletta&);
	friend ostream& operator<<(ostream&, const Bolletta&);

private:
	char* codiceCliente;
	float importo;
	float costoAlSecondo;
	int numTelefonate;

protected:
	virtual istream& input(istream&);
	virtual ostream& output(ostream&) const;

public:
	Bolletta();
	Bolletta(const char*, const float, const float, const int);
	Bolletta(const Bolletta&);
	virtual ~Bolletta();

	const Bolletta& operator=(const Bolletta&);

	void setBolletta(const char*, const float, const float, const int);
	void setBolletta(const Bolletta&);
	void setCodiceCliente(const char*);
	void setImporto(const float);
	void setCostoAlSecondo(const float);
	void setNumTelefonate(const int);

	const char* getCodiceCliente() const { return codiceCliente; }
	float getImporto() const			 { return importo; }
	float getCostoAlSecondo() const		 { return costoAlSecondo; }
	int getNumTelefonate() const		 { return numTelefonate; }

	virtual void aggiornaBolletta(const int);

};
