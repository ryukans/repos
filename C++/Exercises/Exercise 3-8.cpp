#include <iostream>

using namespace std;

int main()
{
    int n = 0;

    cout << "Enter a number to check if it's odd or even\n>: ";
    cin >> n;
    cout << "The number " << n << " is " << ((n % 2 == 0) ? "odd" : "even") << endl;


    return 0;
}
