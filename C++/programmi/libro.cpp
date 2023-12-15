#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct libro {
    string codice;
    string titolo;
    string autore;
    string editore;
    int volumi;
    int capitoli;
    int pagine;
    float prezzo;
}

int main()
{
    libro v[5];

    v.codice = "ABCD1234";
    v.titolo = "TEST 1";
    v.autore = "Aldo";
    v.editore = "Mondadori";
    v.volumi = 3;
    v.capitoli = 10;
    v.pagine = 200;
    v.prezzo = 5.50;

    v.codice = "EFGH5678";
    v.titolo = "TEST 2";
    v.autore = "Aldo";
    v.editore = "Zanichelli";
    v.volumi = 5;
    v.capitoli = 20;
    v.pagine = 200;
    v.prezzo = 15.30;

    v.codice = "ILMN90123";
    v.titolo = "TEST 2";
    v.autore = "Giovanni";
    v.editore = "Zanichelli";
    v.volumi = 1;
    v.capitoli = 50;
    v.pagine = 350;
    v.prezzo = 19.99;

    for(int i = 0; i < 3; i++){
        cout << v.titolo << " " << v.autore << " " << v.editore << " " << v.pagine << v.prezzo << endl;
    }

    ofstream tabella;

    tabella.open("tabella.txt");

    for(int i = 0; i < 3; i++){
        tabella << v.titolo << " " << v.autore << " " << v.editore << " " << v.pagine << v.prezzo << endl;
    }

    tabella.close();

    string autore;

    cout << endl << "Inserisci autore: " << endl;
    cin >> autore;

    for(int i = 0; i < 3; i++){
        int somma = 0
        int media = 0;
        int nlibri = 0;
        if(autore == v[i].autore){
            cout << v[i].titolo << endl;
            somma += v[i].pagine;
            nlibri++;
        }
        media = somma / nlibri;
    }

    return 0;
}