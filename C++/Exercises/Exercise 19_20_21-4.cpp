#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void flush(void);

int main()
{
    vector<string> names;
    vector<int> scores;
    string n;
    int s;
    bool repeated = false;

    while (!repeated && cin >> n >> s && n != "NoName") {
        for (int i = 0; i < names.size(); ++i)
            if (n == names[i]) repeated = true;
        names.push_back(n);
        scores.push_back(s);
    }


    cout << endl;
    flush();

    for (int i = 0; i < names.size(); ++i)
        cout << names[i] << " / " << scores[i] << endl;

    cout << endl;
    flush();

    while (cin >> n) {
        bool found = false;
        for (int i = 0; i < names.size(); ++i)
            if (n == names[i]) {
                cout << scores[i] << endl;
                found = true;
            }
        if (!found)
            cout << "Name not found" << endl;
    }

    cout << endl;
    flush();

    while (cin >> s){
        bool found = false;
        for (int i = 0; i < scores.size(); ++i)
            if (s == scores[i]) {
                cout << names[i] << endl;
                found = true;
            }
        if (!found)
            cout << "Score not found" << endl;
    }

    return 0;
}



void flush()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}



