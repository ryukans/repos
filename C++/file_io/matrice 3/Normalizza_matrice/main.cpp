#include <iostream>
#include <fstream>
#include "util.h"

using namespace std;

int main()
{
    int rig, col;
    matrice m;
    matrice mn;

    leggi_mat("data.txt", m, rig, col);
    stampa_mat(m, rig, col);

    int min_v = calc_min(m, rig, col);
    int max_v = calc_max(m, rig, col);

    cout << "Valore minimo: " << min_v << endl;
    cout << "Valore massimo: " << max_v << endl;

    normalizza_mat(m, mn, rig, col, min_v, max_v);
    cout << "Normalizzata" << endl;
    stampa_mat(mn, rig, col);

    return 0;
}


//mn[k][h] = (min_val != max_val) ? (m[i][j]-min_val)/(max_val-min_val) : (m[i][j]/max_val);

/*
 if (min_v != max_v)
    mn[k][h] = ((m[i][j]-min_v)/(max_v-min_v));
else
    mn[k][h] = (m[i][j]/max_v);

*/




