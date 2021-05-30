#ifndef EDITORE_H_INCLUDED
#define EDITORE_H_INCLUDED

#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;

typedef Libro* L;

class Editore
{
    friend ostream& operator<<(ostream&, const Editore&);

public:

    Editore();
    Editore(const char*, const char*, const int, const int);
    Editore(const Editore&);
    ~Editore();

    const Editore& operator=(const Editore&);

    void inserisci_libro(Libro*);
    void rimuovi_libro(Libro*);


private:
    char* nome;
    char* indirizzo;
    int telefono;
    int n; // riempimento
    int dim; // capacità
    L* libri;




};


#endif // EDITORE_H_INCLUDED
