#include <iostream>


using namespace std;


int main()
{
    string operation;
    double op1 = 0, op2 = 0;

    cout << "Please enter an operation (+, -, * , /, plus, minus, mul, div)\n"
         << "followed by two floating-point values separated by a space: ";

    while (cin >> operation >> op1 >> op2)
    {
        if (operation == "+" || operation == "plus")
            cout << op1 << " + " << op2 << " = " << op1+op2 << endl;
        else if (operation == "-" || operation == "minus")
            cout << op1 << " - " << op2 << " = " << op1-op2 << endl;
        else if (operation == "*" || operation == "mul")
            cout << op1 << " * " << op2 << " = " << op1*op2 << endl;
        else if (operation == "/" || operation == "div") {
            if (op2 == 0)
                cout << "Error -- cannot divide by zero !" << endl;
            else
                cout << op1 << " / " << op2 << " = " << op1/op2 << endl;
        }
        else if (operation == "%" || operation == "mod" || operation == "modulo") {
            if (op2 == 0)
                cout << "Error -- cannot divide by zero !" << endl;
            else
                cout << op1 << " % " << op2 << " = " << op1op2 << endl;
        }
        else
            cout << "Command not recognized." << endl;
    }

    return 0;
}
