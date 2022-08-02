#include <iostream>
#include "lib_utils.h"

using namespace std;

int main()
{
    matrice m;
    stringa nome_file;
    Coordinate v[MAX_DIM];
    int riemp, riempv, k;

    cout << "Inserire nome del file contenente la matrice quadrata:" << endl;
    cin >> nome_file;

    cout << "Inserire riempimento della matrice:" << endl;
    cin >> riemp;

    leggi_mat_quad(nome_file, riemp, m);

    cout << "Inserisci il valore di k:" << endl;
    cin >> k;

    bool res = trova_multiplo(m, riemp, v, riempv, k);

    if (!res) { return EXIT_FAILURE; }

    stampa_coordinate(v, riempv);

    return EXIT_SUCCESS;
}



