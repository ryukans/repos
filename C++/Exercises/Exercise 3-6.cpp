#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    int min, mid, hig;

    cout << "Enter three integer separated by a space:\n";
    cin >> x >> y >> z;

    if (x <= y && x <= z){
        min = x;
        if (y <= z) {
            mid = y;
            hig = z;
        }
        else {
            mid = z;
            hig = y;
        }
    }
    else if (y <= x && y <= z) {
        min = y;
        if (x <= z) {
            mid = x;
            hig = z;
        }
        else {
            mid = z;
            hig = x;
        }
    }
    else {
        min = z;
        if (x <= y) {
            mid = x;
            hig = y;
        }
        else {
            mid = y;
            hig = x;
        }
    }

    cout << min << ',' << mid << ',' << hig << endl;

    char c;
    cin >> c;

    return 0;
}




