#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double a = 0, b = 0, c = 0;
    double delta, x1, x2;

    cin >> a >> b >> c;

    if (a == 0.0)
        cout << "The leading coefficient may not be zero\n";

    delta = sqrt(b*b-4.0*a*c);

    if (delta < 0.0)
        cout << "There are no real solutions\n";
    else {
        x1 = (-b+delta) / (2.0*a);
        x2 = (-b-delta) / (2.0*a);

        cout << x1 << " " << x2;
    }

    return 0;
}
