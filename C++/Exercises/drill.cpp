#include <iostream>
#include <vector>

using namespace std;

int main()
{
    try {
        int res = 7;
        vector<int> v(10);
        v[5] = res;
        cout << "Success !" << '\n';
        char c; cin >> c;

        return 0;
    }
    catch (exception& e) {
        cerr << "error: " << e.what() << '\n';
        char c; cin >> c;

        return 1;
    }

}

