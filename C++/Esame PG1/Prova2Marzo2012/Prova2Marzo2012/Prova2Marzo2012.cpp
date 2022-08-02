#include "Packet.h" 
#include "Vector.h"

using std::cout;
using std::cin;

int main()
{
    Packet p("Cladudio", 24.5, "Oval");
    cout << p;

    Vector v(2);
    cin >> v;
    //cout << v;

    //v.removeHeavy();

    cout << v[1];
    cout << v[3];

    return 0;
}
