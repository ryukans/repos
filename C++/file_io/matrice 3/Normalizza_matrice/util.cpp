#include "util.h"

#include <iostream>
#include <fstream>

using namespace std;

void stampa_mat(const matrice m, int rig, int col)
{
    for (int i = 0; i < rig; i++) {
        for (int j = 0; j < col; j++) {
            cout << m[i][j] << ' ';
        }
        cout << '\n';
    }
    cout << '\n';
}

void leggi_mat(const stringa nome_file, matrice m, int& rig, int& col)
{
    fstream file {nome_file};

    if (!file) {
        cerr << "File non trovato";
        exit(1);
    }

    file >> rig >> col;

    for (int i = 0; i < rig; i++)
        for (int j = 0; j < col; j++)
            file >> m[i][j];

    file.close();
}

int calc_min(const matrice m, int rig, int col)
{
    int min_val = m[0][0];

    for (int i = 0; i < rig; i++)
        for (int j = 0; j < col; j++)
            if (m[i][j] < min_val)
                min_val = m[i][j];

    return min_val;
}

int calc_max(const matrice m, int rig, int col)
{
    int max_val = m[0][0];

    for (int i = 0; i < rig; i++)
        for (int j = 0; j < col; j++)
            if (m[i][j] > max_val)
                max_val = m[i][j];

    return max_val;
}

void normalizza_mat(const matrice m, matrice mn, int rig, int col, int min_v, int max_v)
{
    int i, j, k, h;

    for (i = 0; i < rig; i++) {
        for (j = 0, k = 0, h = 0; j < col; j++, k++, h++) {
            mn[k][h] = (min_v != max_v) ?
                (m[i][j]-min_v)/(max_v-min_v) : (m[i][j]/max_v);
        }
    }
}
