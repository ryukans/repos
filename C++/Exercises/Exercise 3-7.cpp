#include <iostream>

using namespace std;

int main()
{
    string s1, s2, s3;
    string shortest, mid, longest;

    cout << "Enter three strings separated by a space:\n";
    cin >> s1 >> s2 >> s3;

    if (s1 <= s2 && s1 <= s3){
        shortest = s1;
        if (s2 <= s3) {
            mid = s2;
            longest = s3;
        }
        else {
            mid = s3;
            longest = s2;
        }
    }
    else if (s2 <= s1 && s2 <= s3) {
        shortest = s2;
        if (s1 <= s3) {
            mid = s1;
            longest = s3;
        }
        else {
            mid = s3;
            longest = s1;
        }
    }
    else {
        shortest = s3;
        if (s1 <= s2) {
            mid = s1;
            longest = s2;
        }
        else {
            mid = s2;
            longest = s1;
        }
    }

    cout << shortest << ", " << mid << ", " << longest << endl;

    char c;
    cin >> c;

    return 0;
}
