#include <iostream>

using namespace std;

constexpr lower_c = -273.15;
constexpr lower_f = (9*lower_c)/5.0+32; // converted absolute zero from celsisus to faharhneit

double ftoc(double f);
double ctof(double c);

int main()
{
    /**/

    return 0;
}


double ftoc(double f)
{
    if (f < lower_f)
        throw exception("Lower than absolute zero\n");

    double c = (5.0/9.0)*(f-32);

    return c;
}


double ctof(double c)
{
    if (c < lower_c)
        throw exception("Lower than absolute zero\n");

    double f = (9*c)/5.0+32;
}


