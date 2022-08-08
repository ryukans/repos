#include <iostream>

using namespace std;

int main()
{
    double d = 0;

    while (cin >> d) {
        int i = d;
        char c = i;
        int i2 = c;

        cout << "\nd  = " << d
             << "\ni  = " << i
             << "\ni2 = " << i2
             << "\nchar(" << c << ")\n";
    }

    return 0;
}
