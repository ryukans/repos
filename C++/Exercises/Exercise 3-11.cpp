#include <iostream>

#define PENNIE      1
#define NICKEL      5
#define DIME        10
#define QUARTER     25
#define HALF_DOLLAR 50
#define ONE_DOLLAR  100

using namespace std;

int main()
{
    double pennies, nickels, dimes, quarters, half_dollars, one_dollars, total;
    cout << "How many pennies ?\n";
    cin >> pennies;
    cout << "How many nickels ?\n";
    cin >> nickels;
    cout << "How many dimes ?\n";
    cin >> dimes;
    cout << "How many quarters ?\n";
    cin >> quarters;
    cout << "How many half dollars ?\n";
    cin >> half_dollars;
    cout << "How many one-dollar coins ?\n";
    cin >> one_dollars;

    total = pennies + nickels*5.0 + dimes*10.0 + quarters*25.0 + half_dollars*50.0 + one_dollars*100.0;

    cout << "You have " << pennies << ((pennies == 0.0) ?  " pennie\n" : " pennies\n")
         << "You have " << nickels << ((nickels == 0.0) ? " nickel\n" : " nickels\n")
         << "You have " << dimes << ((dimes == 0.0) ? " dime\n" : " dimes\n")
         << "You have " << quarters << ((quarters == 0.0) ? " quarter\n" : " quarters\n")
         << "You have " << half_dollars << ((half_dollars == 0.0) ? " half-dollar\n" : " half-dollars\n")
         << "You have " << one_dollars << ((one_dollars == 0.0) ? " one-dollars coin\n" : " one-dollars coins\n")
         << "The value of all your coins is $" << total/100.0
         << endl;



    return 0;
}
