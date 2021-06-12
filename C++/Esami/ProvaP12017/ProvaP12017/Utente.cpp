#include "Utente.h"

Utente::Utente() : codiceFiscale(new char[CF_SIZE + 1]), cognome(new char[1]), registrazione()
{
	setCodiceFiscale(DEF_CF);
	setCognome("");
}

Utente::Utente(const char* cf, const char* _cognome, const int gg, const int mm, const int aa)
	: codiceFiscale(new char[CF_SIZE + 1]), cognome(new char[strlen(_cognome) + 1]), registrazione(gg, mm, aa)
{
	setCognome(_cognome);
	try {
		verificaDati(cf);
		setCodiceFiscale(cf);
	}
	catch (ErroreUtente eu) {
		cerr << eu.getErr() << endl;
		setCodiceFiscale(DEF_CF);
	}
}

Utente::Utente(const char* cf, const char* _cognome, const Data& R)
	: codiceFiscale(new char[CF_SIZE + 1]), cognome(new char[strlen(_cognome) + 1]), registrazione(R)
{
	setCognome(_cognome);
	try {
		verificaDati(cf);
		setCodiceFiscale(cf);
	}
	catch (ErroreUtente eu) {
		cerr << eu.getErr() << endl;
		setCodiceFiscale(DEF_CF);
	}
}


Utente::Utente(const Utente& U) {
	setUtente(U);
}

Utente::~Utente()
{
	delete[] codiceFiscale;
	delete[] cognome;
}

const Utente& Utente::operator=(const Utente& U)
{
	if (this != &U) {
		setUtente(U);
	}
	return *this;
}

bool Utente::operator==(const Utente& U) {
	return (!strcmp(codiceFiscale, U.codiceFiscale)) && (!strcmp(cognome, U.cognome)) && (registrazione == U.registrazione);
}

bool Utente::operator!=(const Utente& U) {
	return !(*this == U);
}

void Utente::setUtente(const char* cf, const char* cognome, const int gg, const int mm, const int aa)
{
	setCodiceFiscale(cf);
	setCognome(cognome);
	setRegistrazione(gg, mm, aa);
}

void Utente::setUtente(const char* cf, const char* cognome, const Data& R)
{
	setUtente(cf, cognome, R.getGiorno(), R.getMese(), R.getAnno());
}

void Utente::setUtente(const Utente& U)
{
	setCodiceFiscale(U.codiceFiscale);
	setCognome(U.cognome);
	registrazione = U.registrazione;
}


void Utente::setCodiceFiscale(const char* cf)
{
	if (codiceFiscale)
		delete[] codiceFiscale; // possibile ridondanza nel controllo

	codiceFiscale = new char[CF_SIZE + 1];
	strcpy_s(codiceFiscale, CF_SIZE + 1, cf);
}

void Utente::setCognome(const char* c)
{
	if (cognome) // possibile ridondanza nel controllo
		delete[] cognome;

	int c_len = strlen(c) + 1;
	cognome = new char[c_len];
	strcpy_s(cognome, c_len, c);
}

void Utente::setRegistrazione(const int gg, const int mm, const int aa)
{
	registrazione.setGiorno(gg);
	registrazione.setMese(mm);
	registrazione.setAnno(aa);
}

void Utente::setRegistrazione(const Data& R) {
	registrazione = R;
}

bool Utente::verificaDati(const char* cf) throw(ErroreUtente)
{
	if ((strlen(cf) < CF_SIZE) || (strlen(cf) > CF_SIZE))
		throw ErroreUtente("Errore Codice Fiscale: lunghezza errata !\n", ErroreUtente::CF_ERR);

	int i, alpha, digit;
	i = alpha = digit = 0;
	while (cf[i] != '\0') {
		if (isalpha(toupper(cf[i])))
			++alpha;
		else if (isdigit(cf[i]))
			++digit;
		else
			throw ErroreUtente("Errore Codice Fiscale: carattere non valido\n", ErroreUtente::CF_ERR);
		++i;
	}

	if (!alpha || !digit)
		throw ErroreUtente("Errore Codice Fiscale: codice non in formato alfanumerico\n", ErroreUtente::CF_ERR);

	return true;
}

istream& Utente::leggi(istream& in)
{
	char cf[CF_SIZE];
	char c[C_SIZE];
	in >> cf;
	in >> c;

	setCodiceFiscale(cf);
	setCognome(c);

	return in;
}

ostream& Utente::stampa(ostream& out) const {
	return out << cognome << '-' << codiceFiscale << "\nData registrazione " << registrazione << endl;
}

ostream& operator<<(ostream& out, const Utente& U) {
	return U.stampa(out);
}

istream& operator>>(istream& in, Utente& U) {
	return U.leggi(in);
}
