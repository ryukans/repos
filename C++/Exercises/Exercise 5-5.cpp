#include <iostream>

constexpr double celsius_kelvin = 273.15;

double ctok(double c)
{
    constexpr double lower_temp = -273.15;
    if (c < lower_temp)
        throw std::runtime_error("Lower than absolute zero\n");

    double k = c + celsius_kelvin;

    return k;
}

double ktoc(double k)
{
    constexpr double lower_temp = 0.0;
    if (k < lower_temp)
        throw std::runtime_error("Lower than absolute zero\n");
    double c = k - celsius_kelvin;

    return c;
}


int main()
{
    double c;
    std::cout << "Celsius to Kelvin\n> ";
    std::cin >> c;
    std::cout << '\n' << ctok(c) << std::endl;
    double k;
    std::cout << "Kelvin to Celsius\n> ";
    std::cin >> k;
    std::cout << '\n' << ktoc(k) << std::endl;

    return 0;
}



