#pragma once
#include "utils.h"

using std::cerr;

class ErroreUtente
{
	

private:
	char* errore;
	int codice;

public:

	enum CodiciErrore
	{
		DEF_ERR,
		CF_ERR,
		EMAIL_ERR,
		BOTH_FAIL
	};
	
	ErroreUtente() 
		: errore(new char[1]), codice(DEF_ERR)
	{
		strcpy_s(errore, 1, "");
	}

	ErroreUtente(const char* err)
		: errore(new char[strlen(err) + 1]), codice(DEF_ERR)
	{
		strcpy_s(errore, strlen(err) + 1, err);
	}

	ErroreUtente(const int cod = DEF_ERR) : codice(cod)
	{
		switch (codice)
		{
		case BOTH_FAIL:
			strcpy_s(errore, 100, "Codice Fiscale e Email non valide\n");
			break;
		case CF_ERR:
			strcpy_s(errore, 100, "Codice Fiscale non valido\n");
			break;
		case EMAIL_ERR:
			strcpy_s(errore, 100, "Email non valida\n");
			break;
		default:
			strcpy_s(errore, 100, "ERRORE\n");
			break;
		}
	}

	ErroreUtente(const bool cf_err, const bool email_error, const int cod = DEF_ERR) : errore(new char[100])
	{
		if (cf_err && email_error) {
			strcpy_s(errore, 100, "Codice Fiscale e Email non valide\n");
			codice = BOTH_FAIL;
		}
		else if (cf_err && !email_error) {
			strcpy_s(errore, 100, "Codice Fiscale non valido\n");
			codice = CF_ERR;
		}
		else {
			strcpy_s(errore, 100, "Email non valida\n");
			codice = EMAIL_ERR;
		}
	}

	ErroreUtente(const ErroreUtente& EU) 
		: errore(new char[strlen(EU.errore) + 1]), codice(EU.codice)
	{
		strcpy_s(errore, strlen(EU.errore) + 1, EU.errore);
	}
	
	~ErroreUtente() { delete[] errore; }

	const char* getErr() { return errore; }
	int getCodice() { return codice; }
};

