#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    string name, lastName;
    double age = -1;

    cout << "Enter your name, last name and age:\n";
    cin >> name >> lastName >> age;

    system("cls");

    cout << "Name: " << name
         << "\nLast name: " << lastName
         << "\nAge: " << age
         << "\nYour age in months: " << 12*age
         << endl;

    return 0;
}
