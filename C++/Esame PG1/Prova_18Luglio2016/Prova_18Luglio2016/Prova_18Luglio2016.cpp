#include "Carta.h"
#include "Bancomat.h"

int main()
{
    /* TEST
    Carta c("Tipo 1", "Aldo", "12345ABC");
    Std::cout << c;*/

    Bancomat carta("Debito", "Aldo", "12345ABC", 2, 9, 2021);


    std::cout << carta;

    carta.attiva();

    std::cout << carta.check("12345XXX");

    return 0;
}
