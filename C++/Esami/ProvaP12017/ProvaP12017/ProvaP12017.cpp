#include "Utente.h"
#include "UtentePosta.h"

int main()
{
    Utente u1("PSICLD98P02F839E", "PISA", 2, 9, 2020);
    cout << u1;

    /*
    Utente u2;
    cin >> u2;
    cout << u2;
    */
    /*
    Data d(2, 9, 1998);
    Data d2(d);
    cout << d2;
    */

    UtentePosta up1("claudiopisa@gmail.com", "PSICLD98P02F839E", "PISA", 2, 9, 2020);
    cout << up1;
    
}
