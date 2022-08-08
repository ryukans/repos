#include <iostream>

#define YEN_PER_USD 0.008861
#define EUR_PER_USD 1.17775
#define GBP_PER_USD 1.3171
#define CNY_PER_USD 6.62479794
#define NOK_PER_USD 0.167143

using namespace std;

int main()
{
	double value = 0;
	char currency = ' ';

	cout << "Enter a value followed by a currency separated by a space\n> ";

	while (cin >> value >> currency) {

		switch (currency) {
		case 'e':
			cout << value << " € = " << value*EUR_PER_USD << " $" << endl;
			break;
		case 'y':
			cout << value << " ￥ = " << value*YEN_PER_USD << " $" << endl;
			break;
		case 'p':
			cout << value << " £ = " << value*GBP_PER_USD << " $" << endl;
			break;
		case 'u':
			cout << value << " CNY = " << value*CNY_PER_USD << " $" << endl;
			break;
		case 'k':
			cout << value << " KON = " << value*NOK_PER_USD << " $" << endl;
			break;
		default:
			cout << "\tError -- unknown currency called" << endl;
		}

		cout << "> "; 
	}

	return 0;
}



