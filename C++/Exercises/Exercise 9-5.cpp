#include <iostream>

using namespace std;

constexpr lower_c = -273.15;
constexpr lower_f = (9*lower_c)/5.0+32; // converted absolute zero from celsisus to faharhneit

double ftoc(double f);
double ctof(double c);


int main()
{


}


/// https://github.com/bewuethr/stroustrup_ppp/blob/master/chapter05/chapter05_ex09.cpp
double ftoc(double f)
{
    if (f < lower_f)
        throw exception("Lower than absolute zero\n");

    double f_exact = c * 9.0/5.0 + 32;
    int f = c * 9.0/5.0 + 32;

    if (f != f_exact)
        cout << "Result cannot be represented as an int!";

    double c = (5.0/9.0)*(f-32);

    return c;
}


double ctof(double c)
{
    if (c < lower_c)
        throw exception("Lower than absolute zero\n");

    double c_exact = (f - 32) * 5.0/9.0;
    int c =  (f - 32) * 5.0/9.0;
    if (c != c_exact)
        cout << "Result cannot be represented as an int!";

    double f = (9*c)/5.0+32;
}



/*
const int czero = -273, fzero = (9*czero)/5+32;

int ctof (int c) {
    if (c < czero) {
        cout << "Colder than absolute zero\n";
        exit(1);
    }
    if (c%5 != 0) {
        cout << "The conversion cannot be done exactly\n";
        exit(1);
    }

    return (9*c)/5+32;
}

int ftoc (int f) {
    if (f < fzero) {
        cout << "Colder than absolute zero\n";
        exit(1);
    }
    if ((f-32)%9/5 != 0) {
        cout << "The conversion cannot be done exactly\n";
        exit(1);
    }
    return (f-32)*5/9;
}
*/


