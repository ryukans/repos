#ifndef UTILS_H_INCLUDED
#define UTILS_H_INCLUDED


const int max_dim = 50;

typedef char stringa [max_dim];

struct Punto {
    stringa giocatore;
    stringa squadra;
    int minuto;
};

typedef Punto vettPnt [max_dim];


void leggiReti(stringa, vettPnt, int&);
void stampaMarcatori(const vettPnt, const int);
bool verificaCampione(const vettPnt, const int, stringa);


#endif // UTILS_H_INCLUDED
