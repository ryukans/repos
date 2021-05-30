#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include <iostream>
#include <cstring>

using namespace std;

class Libro
{
    friend ostream& operator<<(ostream&, const Libro&);

public:
    Libro();
    Libro(const char*, const int, const int, const int);
    Libro(const Libro&);
    ~Libro();

    const Libro& operator=(const Libro&);

private:
    //static const int _ISBN = 13;
    char* titolo;
    int data_edizione;
    int data_acquisto;
    int isbn;
};

#endif // LIBRO_H_INCLUDED
