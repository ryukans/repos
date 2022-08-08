#include <iostream>
#include <fstream>

using namespace std;

int const max_dim = 100;

typedef char stringa [max_dim+1];
typedef Pronostico partite [max_dim*max_dim];
enum {VITTORIA_TRASFERTA = 0, PAREGGIO = 1, VITTORIA_CASA = 3};

struct Pronostico {
    stringa casa;
    stringa trasferta;
    int goal1;
    int goal2;
};

int main()
{
    partite v;

    return 0;
}


void leggi_risltati(stringa file, partite v, int& riempv)
{
    ifstream {file};

    if (!file) {
        cerr << "Errore: file non trovato" << endl;
        exit(1);
    }

    riempv = 0;
    while (!file.eof()) {
        file >> v[riempv].casa, file >> v[riempv].trasferta;
        file >> v[riempv].pti_casa, file >> v[riempv].pti_trasferta;
        ++riempv;
    }

    file.close(); // chiudi input stream
}

/*Valori di ritorno [0,1] U [3]:
 * 3 se pti_casa > pti_trasferta
 * 1 se pti_casa = pti_trasferta
 * 0 se pti_casa < pti_trasferta
*/
int calcola_punti(int goal1, int goal2)
{
    if (goal1 > goal2) {
        return 3; // 3 punti
    }
    else if (goal1 == goal2) {
        return 1; // 1 punto
    }
    else
        return 0; // 0 punti
}

/* Valori di ritorno [0, MAX_INT]:
 * ritorina il punteggio totalizzato dalla squadra.
*/
int calcola_punteggio(const& partite v, const int riempv, const& stringa squadra)
{
    int pti = 0;
    int j = riempv;

    for (int i = 0; i < j; i++) {
        if (strcmp(squadra, v[i].casa) == 0) {
            pti += calcola_punti(v[i].goal1, v[i].goal2);
        }
        else if (strcmp(squadra, v[i].trasferta) == 0) {
            pti += calcola_punti(v[i].goal2, v[i].goal1);
        }
    }

    return pti;
}

void stampa_risultati(const& partite v, const int riempv)
{
    for (int i = 0; i < riempv, i++)
        cout << v[i].casa << " " << v[i].trasferta << " " << v[i].goal1 << " " << v[i].goal2 << endl;
}







