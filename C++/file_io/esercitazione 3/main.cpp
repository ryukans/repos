#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>

using namespace std;

const int max_dim = 50;

typedef char stringa [max_dim+1];
typedef stringa vett_str[max_dim];


void leggi_parole(stringa file, vett_str v, int& riemp);
void crea_stringa_max(const vett_str v, int riemp, stringa max_car);
void stampa_vett_str(const vett_str v, int riemp);

int main()
{
    int riemp;
    vett_str v;
    stringa max_car;

    leggi_parole("file.txt", v, riemp);
    crea_stringa_max(v, riemp, max_car);
    stampa_vett_str(v, riemp);

    cout << "Risultato: \n" << max_car << endl;
}


void leggi_parole(stringa file, vett_str v, int& riemp)
{
    ifstream input;

    input.open(file);

    if(!input){
        cerr << "Errore: file non trovato";
        exit(1);
    }

    int i = 0;
    while (!input.eof()) {
        input >> v[i++];
    }
    riemp = i;

    input.close();
}

void crea_stringa_max(const vett_str v, int riemp, stringa max_car)
{
    // riemp è il numero di riga

    for (int i = 0; i < riemp; i++) {
        char c = v[i][0]; // c è il carattere più grande della parola
        for (int j = 1; j < strlen(v[i]); j++) {
            if (v[i][j] > c)
                c = v[i][j];
        }
        max_car[i] = c;
    }
}

void stampa_vett_str(const vett_str v, int riemp)
{
    cout << "Parole lette da file: ";
    for (int i = 0; i < riemp; i++) {
        cout << v[i] << " ";
    }
    cout << '\n';
}


