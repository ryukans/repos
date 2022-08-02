#include <iostream>

using namespace std;

int main()
{
    string previous = "";
    string current;
    int words = 0;

    while (cin >> current) {
        ++words;
        if (current == previous) {
            cout << "\tWord number " << words <<
                ", repeated: " << current << '\n';
        }
        previous = current;
    }

    return 0;
}
