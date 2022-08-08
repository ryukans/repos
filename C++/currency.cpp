#include <iostream>

#define YEN_PER_USD 0.008861
#define EUR_PER_USD 1.17775
#define GBP_PER_USD 1.3171

using namespace std;

int main()
{
	double value = 0;
	char currency = ' ';

	cout << "Enter a value followed by a currency separated by a space\n> ";

	while (cin >> value >> currency) {

		if (currency == "€" || currency == "euro" || currency == "eur") {
			cout << value << " € = " << value*EUR_PER_USD << " $" << endl;
		}

		else if (currency == "￥" || currency == "yen") {
			cout << value << " ￥ = " << value*YEN_PER_USD << " $" << endl;
		}

		else if (currency == "£" || currency == "pound" || currency == "gbp") {
			cout << value << " £ = " << value*GBP_PER_USD <<  " $" << endl;
		}
		else { 
			cout << "\tError -- unknown currency called" << endl;
		}

		cout << "> "; 
	}

	return 0;
}



