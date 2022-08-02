/* The following program takes in a temperature value in Celsius and converts it to Kelvin. */

#include <iostream>

using namespace std;

double ctok(double c)
{
    constexpr lowest_temp = -273.15;

    /*if (c < lowest_temp) EXERCISE 4
        throw runtime_error("Lower than absolute zero\n"); */

    double k = c + 273.15;

    return k;
}

int main()
{

    double c = 0;

    if (c < lowest_temp)
        cerr << "Error -- lowest is " << lowest_temp << endl;
    else {
        double k = ctok(c);
        cout << k << endl;
    }
}
