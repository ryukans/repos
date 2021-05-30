#include "Libro.h"
#include "Editore.h"


using namespace std;

int main()
{

    Libro libro("Libro generico", 291998, 292000, 1234567891234);
    cout << libro;

    Editore editore("Editore generico", "Via Claudio", 999999999);

    cout << editore;

    return 0;
}
