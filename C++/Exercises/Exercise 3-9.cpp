#include <iostream>

using namespace std;

int main()
{
    string number = "";

    cin >> number;

    if (number == "1")
        cout << "one";
    else if (number == "2")
        cout << "two";
    else if (number == "3")
        cout << "three";
    else if (number == "4")
        cout << "four";
    else
        cout << "Not a number I know";

    return 0;
}

