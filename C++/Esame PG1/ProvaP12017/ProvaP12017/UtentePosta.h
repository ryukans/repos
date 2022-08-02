#pragma once
#include "Utente.h"
#include "ErroreUtente.h"

static const int DEF_SIZE = 3;
static const char DEF_STRING[DEF_SIZE + 1] = "N/A";

class UtentePosta : public Utente
{
	friend ostream& operator<<(ostream&, const UtentePosta&);
	friend istream& operator>>(istream&, UtentePosta&);
private:
	char* email;

protected:
	virtual bool verificaDati(const char* codiceFiscale, const char* email) throw(ErroreUtente);
	virtual istream& leggi(istream&);
	virtual ostream& stampa(ostream&) const;

public:
	UtentePosta();
	UtentePosta(const char* email, const char* codiceFiscale, const char* cognome, const int giorno, const int mese, const int anno);
	UtentePosta(const char* email, const char* codiceFiscale, const char* cognome, const Data& registrazione);
	UtentePosta(const char* email, const Utente&);
	UtentePosta(const UtentePosta&);
	virtual ~UtentePosta();

	const UtentePosta& operator=(const UtentePosta&);
	bool operator==(const UtentePosta&);
	bool operator!=(const UtentePosta&);

	const UtentePosta& getUtentePosta() const { return *this; }

	istream& setEmail(istream&);
	void setEmail(const char*);

};

