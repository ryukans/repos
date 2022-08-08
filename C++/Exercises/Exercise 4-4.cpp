#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string prompt = " ";
    vector<int> numbers;
    for (int i = 1; i <= 100; ++i)
        numbers.push_back(i);


    cout << "Think a number between 0 and 100\n\n";

    bool found = false;
    int attempts = 0;
    int low = 1, mid = 0, high = 100;


    while (low <= high && found == false) {
        mid = (low+high / 2);
        ++attempts;

        cout << "Is your number " << mid << " ?\n";
        cin >> prompt;

        if (prompt == "y" || prompt == "yes") {
            found = true;
        }
        else if (prompt == "n" || prompt == "no") {
            cout << "Is your number less/grater than " << mid << " ?\n";
            cin >> prompt;
            if (prompt == "g" || prompt == "greater") {
                low = mid + 1;
            }
            else if (prompt == "l" || prompt == "less") {
                high = mid - 1;
            }
        }
    }

    cout << "It took " << attempts << " attempts to guess the number\n";

    return 0;
}


