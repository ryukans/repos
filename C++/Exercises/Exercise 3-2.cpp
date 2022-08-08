#include <iostream>

using namespace std;

int main()
{
    double km = 0, mi = 0;

    cout << "Type miles: ";
    cin >> mi;
    cout << "Miles to kilometers: " << mi*1.609 << endl;

    cout << "Type kilometers: ";
    cin >> km;
    cout << "Kilometers to miles: " << km*0.621 << endl;

    return 0;
}
