#include "Editore.h"


Editore::Editore()
    : dim(1), n(0), libri(new L[dim]), nome(new char[1]), indirizzo(new char[1]), telefono(0)
{
    strcpy(nome, "");
    strcpy(indirizzo, "");
}

Editore::Editore(const char* N, const char* IND, const int TEL, const int DIM)
    : dim(DIM), n(0), libri(new L[dim]), nome(new char[strlen(N)+1]), indirizzo(new char[strlen(IND)+1]), telefono(TEL)
{
    strcpy(nome, N);
    strcpy(indirizzo, IND);
}

Editore::Editore(const Editore& E)
    : nome(new char[strlen(E.nome)+1]), indirizzo(new char[strlen(E.indirizzo)+1]), telefono(E.telefono)
{
    strcpy(nome, E.nome);
    strcpy(indirizzo, E.indirizzo);

    for (int i = 0; i < n; i++)
        *libri[i] = *E.libri[i];

}

Editore::~Editore()
{
    delete[] nome;
    delete[] indirizzo;
    delete[] libri;
}

const Editore& Editore::operator=(const Editore& E)
{
    if (this != &E) {
        delete[] nome;
        delete[] indirizzo;
        nome = new char[strlen(E.nome)+1];
        indirizzo = new char[strlen(E.indirizzo)+1];
        telefono = E.telefono;
    }

    return *this;
}


void Editore::inserisci_libro(Libro* libro)
{
	if (n == dim) return;

	*libri[n++] = *libro;
}

void Editore::rimuovi_libro(Libro* libro)
{
	if (n == 0) return;

	*libro = *libri[--n];
}


ostream& operator<<(ostream& out, const Editore& E)
{
    out << E.nome << " " << E.indirizzo << " " << E.telefono << endl;

    return out;
}






