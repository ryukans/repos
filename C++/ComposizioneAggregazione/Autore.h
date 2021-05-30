#ifndef AUTORE_H_INCLUDED
#define AUTORE_H_INCLUDED

#include "Libro.h"
#include <cstring>
#include <iostream>

using namespace std;

typedef Libro L;

class Autore
{
public:
    Autore();
    Autore(const char*, const char*, const int, const int);
    ~Autore();

    const Autore& operator=(const Autore&);

private:
    char* nome;
    char* cognome;
    int bday;
    int n; // riempimento
    int dim; // capacità
    L* libri;

};


#endif // AUTORE_H_INCLUDED
