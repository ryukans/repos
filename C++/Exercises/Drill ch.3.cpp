#include <iostream>

using namespace std;

int main()
{
    string first_name, last_name;

    cout << "Enter the name of the person you want to write to:\n";
    cin >> first_name >> last_name;
    cout << "Dear " << first_name << ",\nhow are you ? I'm fine. I miss you.\n";

    string friend_name;

    cout << "Friend name:\n";
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately ?\n";

    char friend_sex = 0;

    cout << "Friend's sex: (m/f)\n";
    cin >> friend_sex;

    if (tolower(friend_sex) == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    if (tolower(friend_sex) == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";

    int age = 0;

    cout << "Age:\n";
    cin >> age;

    if (age <= 0 || age >= 110)
        cout << "You are kidding !\n";
    else if (age < 12)
        cout << "Next year you'll be " << age+1 << '\n';
    else if (age == 17)
        cout << "Next year you'll be able to vote\n";
    else if (age >= 70)
        cout << "I hope you are enjoying your retirement\n";


    cout << "Your sincerely\n\nClaudio Pisa";

    return 0;
}
