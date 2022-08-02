/* Convert from inches to centimeters and vice versa */

#include <iostream>

#define CM_PER_INCH 2.54

using namespace std;

int main()
{
	double length = 0;
	string unit = "";

	cout << "Enter a length followed by a unit\n> ";
	cin >> length >> unit;

	if (unit == "i" || unit == "in" || unit == "inch")
		cout << length << " in = " << length*CM_PER_INCH << " cm\n";
	else if (unit == "c" || unit == "cm" || unit == "centimeters")
		cout << length << " cm = " << length/CM_PER_INCH << " in\n";
	else
		cout << "\tError -- unknown unit called\n";


	return 0;
}
