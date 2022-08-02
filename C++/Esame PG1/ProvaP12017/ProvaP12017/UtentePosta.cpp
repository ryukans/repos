#include "UtentePosta.h"


UtentePosta::UtentePosta() : email(new char[DEF_SIZE + 1]), Utente() {
	setEmail(DEF_STRING);
}

UtentePosta::UtentePosta(const char* _email, const char* cf, const char* cognome, const int gg, const int mm, const int aa)
	: email(new char[DEF_SIZE + 1]), Utente()
{
	setCognome(cognome);
	setRegistrazione(gg, mm, aa);

	try {
		verificaDati(cf, _email);
		setCodiceFiscale(cf);
		setEmail(_email);
	}
	
	catch (ErroreUtente eu) {
		cerr << eu.getErr() << endl;
		switch (eu.getCodice())
		{
		case eu.BOTH_FAIL:
			setEmail(DEF_STRING);
			setCodiceFiscale(DEF_CF);
			break;
		case eu.EMAIL_ERR:
			setEmail(DEF_STRING);
			setCodiceFiscale(cf);
			break;
		case eu.CF_ERR:
			setEmail(_email);
			setCodiceFiscale(DEF_CF);
			break;
		}
	} 
	
}

UtentePosta::UtentePosta(const char* _email, const char* cf, const char* cognome, const Data& R)
	: email(new char[DEF_SIZE + 1]), Utente()
{
	setCognome(cognome);
	setRegistrazione(R);

	try	{
		verificaDati(cf, _email);
		setCodiceFiscale(cf);
		setEmail(_email);
	}
	catch (ErroreUtente eu) {
		cerr << eu.getErr() << endl;
		switch (eu.getCodice())
		{
		case eu.BOTH_FAIL:
			setEmail(DEF_STRING);
			setCodiceFiscale(DEF_CF);
			break;
		case eu.EMAIL_ERR:
			setEmail(DEF_STRING);
			setCodiceFiscale(cf);
			break;
		case eu.CF_ERR:
			setEmail(_email);
			setCodiceFiscale(DEF_CF);
			break;
		}
	}
	
}

UtentePosta::UtentePosta(const char* _email, const Utente& U)
	: email(new char[DEF_SIZE + 1]), Utente()
{
	setCognome(U.getCognome());
	setRegistrazione(U.getRegistrazione());

	try {
		verificaDati(U.getCodiceFiscale(), _email);
		setCodiceFiscale(U.getCodiceFiscale());
		setEmail(_email);
	}
	catch (ErroreUtente eu) {
		cerr << eu.getErr() << endl;

		switch (eu.getCodice())
		{
		case eu.BOTH_FAIL:
			setEmail(DEF_STRING);
			setCodiceFiscale(DEF_CF);
			break;
		case eu.EMAIL_ERR:
			setEmail(DEF_STRING);
			setCodiceFiscale(U.getCodiceFiscale());
			break;
		case eu.CF_ERR:
			setEmail(_email);
			setCodiceFiscale(DEF_CF);
			break;
		}

	}
	
}

UtentePosta::UtentePosta(const UtentePosta& UP)
	: email(new char[strlen(UP.email) + 1]), Utente(UP)
{
	strcpy_s(email, strlen(UP.email) + 1, UP.email);
}

UtentePosta::~UtentePosta() {
	delete[] email;
}

const UtentePosta& UtentePosta::operator=(const UtentePosta& UP)
{
	if (this != &UP) {
		Utente::operator=(UP);
		setEmail(UP.email);
	}
	return *this;
}

bool UtentePosta::operator==(const UtentePosta& UP) {
	return Utente::operator==(UP) && !strcmp(email, UP.email);
}

bool UtentePosta::operator!=(const UtentePosta& UP) {
	return !(*this == UP);
}

void UtentePosta::setEmail(const char* _email)
{
	if (email)
		delete[] email;

	email = new char[strlen(_email) + 1];
	strcpy_s(email, strlen(_email) + 1, _email);
}

istream& UtentePosta::setEmail(istream& in)
{
	char email_buffer[100];
	in >> email_buffer;
	setEmail(email_buffer);

	return in;
}
/* Vecchio
bool UtentePosta::verificaDati(const char* email)
{
	int i, c;

	i = c = 0;
	while (email[i] != '\0' && !c) {
		if (email[i++] == '@')
			++c;
	}

	if (c == 0)
		return false;

	return true;
}*/

bool UtentePosta::verificaDati(const char* cf, const char* email) throw(ErroreUtente)
{
	bool cf_err = false;
	bool email_err = false;
	try {
		Utente::verificaDati(cf);
	}
	catch (ErroreUtente eu) {
		cf_err = true;
	}
	
	/*  Alternativo
	int i, c;

	i = c = 0;
	while (email[i] != '\0' && !c) {
		if (email[i++] == '@')
			++c;
	}
	*/

	int i = 0;
	while (email[i] != '\0' && email[i] != '@')
		++i;

	if (email[i] != '@') 
		email_err = true;

	if (cf_err || email_err)
		throw ErroreUtente(cf_err, email_err);

	/* Alternativa 1
	* 
	if (cf_err && email_err)
		throw ErroreUtente("Codice Fiscale e Email non valide\n");
	else if (cf_err && !email_err)
		throw ErroreUtente("Codice Fiscale non valido\n");
	else
		throw ErroreUtente("Email non valida\n");
	*/

	/* Alternativa 2
	* 
	if (cf_err && email_err)
		throw ErroreUtente(ErroreUtente::BOTH_FAIL);
	else if (cf_err && !email_err)
		throw ErroreUtente(ErroreUtente::CF_ERR);
	else
		throw ErroreUtente(ErroreUtente::EMAIL_ERR);
	*/

	return true;
}

istream& UtentePosta::leggi(istream& in)
{
	Utente::leggi(in);
	setEmail(in);
	return in;
}

ostream& UtentePosta::stampa(ostream& out) const
{
	Utente::stampa(out);
	return out << "\nemail: " << email << endl;
}

ostream& operator<<(ostream& out, const UtentePosta& UP) {
	return UP.stampa(out);
}

/* Versione che sfrutta incapsulamento 
ostream& operator<<(ostream& out, const UtentePosta& UP) {
	return out << UP.getUtente().getCognome() << "\nemail: " << UP.email << endl;
}*/

istream& operator>>(istream& in, UtentePosta& UP)  {
	return UP.leggi(in);
}



















