#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "utils.h"

using namespace std;

void leggiReti(stringa nomeFile, vettPnt v, int &riempv)
{
    /*Nome del file deve essere in minuscolo.*/
    for (int i = 0; i < strlen(nomeFile); i++) { nomeFile[i] = tolower(nomeFile[i]); }

    ifstream file {nomeFile};

    if (!file) {
        cerr << "Errore: file non trovato" << endl;
        exit(1);
    }

    riempv = 0;
    while (!file.eof()) {
       file >> v[riempv].giocatore, file >> v[riempv].squadra, file >> v[riempv++].minuto;
    }

    file.close();
}

void stampaMarcatori(const vettPnt v, const int riempv)
{
    int i;

    cout << "Giocatore" << setw(20) << "Squadra" << setw(20) << "Min\n\n";
    for (i = 0; i < riempv; i++)
        cout << v[i].giocatore << setw(20) << v[i].squadra << setw(20) << v[i].minuto << endl;
}

bool verificaCampione(const vettPnt v, const int riempv, stringa nomeSquadra)
{
    if (strlen(nomeSquadra) == 0) {
        cerr << "Nome squadra non inserito" << endl;
        exit(1);
    }

    /*Nel file il nome della squadra è scritto con la prima lettera in maiscolo e le restanti in minuscolo.
     *Se il primo carattere della quadra inserita è minuscolo, viene convertito in maiscolo.
     *Analogamente se uno o più dei restanti caratteri sono maisculo vengono convertiti in minuscolo.
     */
    nomeSquadra[0] = islower(nomeSquadra[0]) ? toupper(nomeSquadra[0]) : nomeSquadra[0];

    for (int i = 1; i < strlen(nomeSquadra); i++) { nomeSquadra[i] = tolower(nomeSquadra[i]); }

    bool valida = false;
    stringa squadraAvversaria = "";
    for (int i = 0; i < riempv && valida == false; i++) {
        if (strcmp(nomeSquadra, v[i].squadra) == 0) {
            valida = true;
        } else {
            strcpy(squadraAvversaria, v[i].squadra);
        }
    }

    if (!valida) {
        cerr << "La squadra inserita non ha partecipato alla partita" << endl;
        exit(1);
    }

    int ptiSqd, ptiSqdAvv;
    ptiSqd = ptiSqdAvv = 0;
    for (int i = 0; i < riempv; i++) {
        if (strcmp(nomeSquadra, v[i].squadra) == 0) {
            ++ptiSqd;
        } else {
            ++ptiSqdAvv;
        }
    }

    return (ptiSqd > ptiSqdAvv) ? true : false;
}
