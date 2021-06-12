#pragma once
#include "Data.h"
#include "ErroreUtente.h"

static const int CF_SIZE = 16;
static const int C_SIZE = 20;
static const char DEF_CF[CF_SIZE + 1] = "XXXXXXXXXXXXXXXX";

class Utente
{
	friend ostream& operator<<(ostream&, const Utente&);
	friend istream& operator>>(istream&, Utente&);
private:
	char* codiceFiscale;
	char* cognome;
	Data registrazione;
protected:
	//virtual bool verificaDati(const char*);
	virtual bool verificaDati(const char*) throw(ErroreUtente);
	virtual istream& leggi(istream&);
	virtual ostream& stampa(ostream&) const;

public:
	Utente();
	Utente(const char*, const char*, const int, const int, const int);
	Utente(const char*, const char*, const Data&);
	Utente(const Utente&);
	virtual ~Utente();
	
	const Utente& operator=(const Utente&);
	bool operator==(const Utente&);
	bool operator!=(const Utente&);

	void setUtente(const char*, const char*, const int, const int, const int);
	void setUtente(const char*, const char*, const Data&);
	void setUtente(const Utente&);
	void setCodiceFiscale(const char*);
	void setCognome(const char*);
	void setRegistrazione(const int, const int, const int);
	void setRegistrazione(const Data&);

	const Utente& getUtente() const	{ return *this; }
	char* getCodiceFiscale() const	{ return codiceFiscale; }
	char* getCognome() const		{ return cognome; }
	int getGiorno() const			{ return registrazione.getGiorno(); }
	int getMese() const				{ return registrazione.getMese(); }
	int getAnno() const				{ return registrazione.getAnno(); }
	Data getRegistrazione() const	{ return registrazione; }

	


};