#include <iostream>
#include <fstream>
#include <cstring>

const int max_dim = 50;
typedef char stringa[max_dim+1];
typedef stringa vett_str[max_dim];

using namespace std;

struct studente {
    stringa cognome;
    int esami;
    float media;
};

typedef studente vett_struct[max_dim];

void leggi_file(const stringa, vett_struct, int&);
void trova_studenti_minmed(const vett_struct, vett_str, int, int& riempvs);
void stampa_cognomi(const vett_str, int);


int main()
{
    int riempv; //riempimento vettore di struttire
    int riempvs; //riempimento vettore studenti
    vett_struct v;
    vett_str vs;

    leggi_file("file.txt", v, riempv);
   /* for (int i = 0; i < riempv; i++)
        for (int j = 0; j < strlen(v[i].cognome); j++)
            cout << v[i].cognome[j];*/
    trova_studenti_minmed(v, vs, riempv, riempvs);
    stampa_cognomi(vs, riempvs);

    return 0;
}

void leggi_file(const stringa nomeFile, vett_struct v, int& riempv)
{
    fstream input;

    input.open(nomeFile);

    if (!input) {
        cout << "Errore file non trovato";
        exit(1);
    }

    int i = 0;
    while(!input.eof()) {
        input >> v[i].cognome;
        input >> v[i].esami;
        input >> v[i].media;
        i++;
    }
    riempv = i;

    input.close();
}


void trova_studenti_minmed(const vett_struct v, vett_str vs, int riempv, int& riempvs)
{
    //verifica media totale degli esami superati da tutti gli sudenti
    int i, med, sum;

    i = med = sum = 0;
    while (i < riempv) {
        sum += v[i++].esami;
    }
    med = sum/riempv; // la somma di tutti gli esami superati diviso il numero di esami (riempv) restituisce la media.

    int j, k;
    j = k = 0; //rig e col
    for (int i = 0; i < riempv; i++) {
        if (v[i].esami < med) {
            strcpy(vs[j], v[i].cognome);
            ++j;
        }
    }
    riempvs = j;
}


void stampa_cognomi(const vett_str vs, int riempvs)
{
    for (int i = 0; i < riempvs; i++) {
        for (int j = 0; j < strlen(vs[i]); j++)
            cout << vs[i][j];
        cout << '\n';
    }
}







