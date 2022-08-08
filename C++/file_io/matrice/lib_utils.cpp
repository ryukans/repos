#include <iostream>
#include <fstream>
#include "lib_utils.h"

//definitions

void leggi_mat_quad(const stringa nome_file, int riemp, matrice m)
{

    std::fstream ifs {nome_file};

    if (!ifs) {
        std::cerr << "Errore: file non trovato"<< std::endl;
        exit(1);
    }

    for (int i = 0; i < riemp; i++)
        for (int j = 0; j < riemp; j++)
            ifs >> m[i][j];

    ifs.close();
}

bool trova_multiplo(const matrice m, int riemp, Coordinate v[], int &riempv, int k)
{
    riempv = 0;
    bool mul = false;
    for (int i = 0; i < riemp; i++)
        for (int j = 0; j < riemp; j++)
            if (!(m[i][j] % k)) {
                mul = true;
                v[riempv++] = Coordinate{i, j};
            }

    return mul;
}

void stampa_coordinate(const Coordinate v[], const int riempv)
{
    for (int i = 0; i < riempv; i++) {
        std::cout << '(' << v[i].rig << ',' << v[i].col << ')' << std::endl;
    }
}
