#include <iostream>
#include <fstream>

#define MAX_DIM 10
#define MAX_RIG 4
#define MAX_COL 4

using namespace std;

typedef int matrice [MAX_RIG][MAX_COL];
typedef char stringa [MAX_DIM];

struct Coordinate {
    int rig;
    int col;
};

void leggi_mat_quad(const stringa nome_file, int riemp, matrice m);

bool trova_multiplo(const matrice m, int riemp, Coordinate v[], int &riempv, int k);

void stampa_coordinate(const Coordinate v[], const int riempv);
