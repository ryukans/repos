#include "Autore.h"


Autore::Autore()
    : dim(1), n(0), libri(new L[dim]), nome(new char[1]), cognome(new char[1]), bday(0)
{
    strcpy(nome, "");
    strcpy(cognome, "");
}


Autore::Autore(const char* N, const char* C, const int BD, const int DIM)
    : dim(DIM), n(0), libri(new L[dim]), nome(new char[strlen(N)+1]), cognome(new char[strlen(C)+1]), bday(BD)
{
    strcpy(nome, N);
    strcpy(cognome, C);
}


Autore::Autore(const Autore& A)
    : dim(A.dim), n(0), libri(new L[dim]), nome(new char[strlen(A.nome)+1]), cognome(new char[strlen(A.cognome)+1]), bday(A.bday)
{
    strcpy(nome, A.nome);
    strcpy(cognome, A.cognome);

    for (int i = 0; i < n; i++)
        libri[i] = A.libri[i];
}

Autore::~Autore()
{
    delete[] nome;
    delete[] cognome;
    delete[] libri;

}

const Autore& Autore::operator=(const Autore& A)
{
    if (this != &A) {
        delete[] nome;
        delete[] cognome;
        nome = new char[strlen(A.nome)+1];
        cognome = new char[strlen(A.cognome)+1];
        bday = A.bday;
    }

    return *this;
}


void Autore::inserisci_libro(Libro libro)
{
	if (n == dim) return;

	libri[n++] = libro;
}

void Autore::rimuovi_libro(Libro& libro)
{
	if (n == 0) return;

	libro = libri[--n];
}




