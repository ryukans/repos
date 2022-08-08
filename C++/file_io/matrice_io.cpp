#include <iostream>
#include <fstream>

#define MAX_RIG 4
#define MAX_COL 4
#define MAX_DIM 10

using namespace std;

struct Coordinate {
    int rig;
    int col;
};

typedef int matrice [MAX_RIG][MAX_COL];
typedef char stringa [MAX_DIM];

void leggi_mat_quad(
    const stringa,
    int,
    matrice
);
bool trova_multiplo(
    const matrice,
    int, Coordinate[],
    int&,
    int
);

void stampa_coordinate(
    const Coordinate[],
    const int
);


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

    if (!res) { return 1; }

    stampa_coordinate(v, riempv);

    return 0;
}


void leggi_mat_quad(const stringa nome_file, int riemp, matrice m)
{
    ifstream ifs;

    ifs.open(nome_file);

    if (!ifs) {
        cerr << "Errore: file non trovato"<< endl;
        exit(1);
    }

    for (int i = 0; i < riemp; i++)
        for (int j = 0; j < riemp; j++)
            ifs >> m[i][j];

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
        cout << '(' << v[i].rig << ',' << v[i].col << ')' << endl;
    }
}


/*
for (int i = 0; i < riemp; i++) {
        for (int j = 0; j < riemp; j++) {
            cout << m[i][j];
        }
        cout << '\n';
}
*/



