#include <iostream>
#include <vector>

void get_number(void);

using namespace std;

vector<string> numbers { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

int main()
{
    while (true) {
        get_number();
    }

    return 0;
}

void get_number()
{
    int val;
    if (cin >> val)
        cout << numbers[val] << endl;

    cin.clear();

    string sval;
    cin >> sval;

    for (int i = 0; i < numbers.size(); ++i)
        if (numbers[i] == sval) val = i;

    if (val >= 0 && val <= 10)
        cout << val << endl;
    else
        cout << "Error -- non valid string";
}
