#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int max_dim = 50;

typedef char stringa[max_dim-1];
typedef float matrice[max_dim][max_dim];

struct vett {
    float val;
    int rig;
    int col;
};

typedef vett vett_str[max_dim];

void leggi_mat(const stringa, matrice, int&, int&);
void calc_vett_struct(matrice, int, int, vett_str);
void stampa_struct(const vett_str, int);


int main()
{
    int rig, col;
    matrice m;
    vett_str v;

    //cout << "Inserire nome file: " << endl;
    //cin >> nomeFile;
    leggi_mat("mat.txt", m, rig, col);
    calc_vett_struct(m, rig, col, v);
    stampa_struct(v, rig);

    return EXIT_SUCCESS;
}


void leggi_mat(const stringa nomeFile, matrice m, int& rig, int& col)
{
    if (!strlen(nomeFile)) {
        cerr << "Errore: nome file non specificato" << endl;
        exit(EXIT_FAILURE);
    }

    ifstream file;
    file.open(nomeFile);

    if (!file) {
        cerr << "Errore file non trovato" << endl;
        exit(EXIT_FAILURE);
    }

    file >> rig >> col;

    for (int i = 0; i < rig; i++) {
        for (int j = 0; j < col; j++) {
            file >> m[i][j];
        }
    }
}


void calc_vett_struct(matrice m, int rig, int col, vett_str v)
{
    for (int i = 0; i < rig; i++) {
        bool trovato = false;
        for (int j = 1; j < col && trovato == false; j++) {
            if (m[i][j] > m[i][0]) {
                v[i] = vett{m[i][j], i, j};
                trovato = true;
            }
        }
    }
}


void stampa_struct(const vett_str v, int riempv)
{
    for (int i = 0; i < riempv; i++)
        cout << v[i].val << '(' << v[i].rig << ',' << v[i].col << ')' << endl;
}






