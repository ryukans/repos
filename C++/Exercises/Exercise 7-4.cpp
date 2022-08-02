#include <iostream>
#include <vector>

int get_number(void);

using namespace std;

vector<string> numbers { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten" };

int main()
{
    int op1, op2;
    char operation = 0;

    cout<< "please enter two digits separated by an operator\n The operator can be + - * / % : ";

    while (true)
    {
        op1 = get_number();
        cin >> operation;
        op2 = get_number();

        switch (operation) {
        case '+': {
            cout << op1 << " + " << op2 << " = " << op1+op2 << endl;
            break;
        }
        case '-': {
            cout << op1 << " - " << op2 << " = " << op1-op2 << endl;
            break;
        }
        case '*': {
            cout << op1 << " * " << op2 << " = " << op1*op2 << endl;
            break;
        }
        case '/': {
           if (op2 == 0)
                cout << "Error -- cannot divide by zero !" << endl;
            else
                cout << op1 << " / " << op2 << " = " << op1/op2 << endl;
            break;
        }
        case '%': {
             if (op2 == 0)
                cout << "Error -- cannot divide by zero !" << endl;
            else
                cout << op1 << " % " << op2 << " = " << op1%op2 << endl;
            break;
        }
        default:
            cout << "Error\n";
        } // end of switch
    }

    return 0;
}


int get_number()
{
    int val;
    if (cin >> val) return val;

    cin.clear();

    string sval;
    cin >> sval;

    for (int i = 0; i < numbers.size(); ++i)
        if (numbers[i] == sval) val = i;

    if (val >= 0 && val <= 10)
        return val;
    else
        cout << "Error -- non valid string";
}
