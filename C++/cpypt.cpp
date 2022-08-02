#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

string encode(
    string text,
    int param
);

string decode(
    string chiper,
    int param
);

int main()
{
	cout << "Type string" << endl;
	string text, cipher;
	cin >> text;

	cipher = encode(text, 3);
	cout << cipher << endl;
	cipher = decode(cipher, 3);
	cout << cipher;
}

string encode(string text, int param)
{
    string cipher = "";

    for (int i = 0; i < text.length(); ++i) {
		if (isupper(text[i]))
			cipher += ((text[i] - 65 + param) % 26) + 65;
		if (islower(text[i]))
			cipher += ((text[i] - 97 + param) % 26) + 97;
	}

	return cipher;
}


string decode(string cipher, int param)
{
    string decoded = "";

    for (int i = 0; i < cipher.length(); ++i) {
		if (isupper(cipher[i]))
			decoded += ((cipher[i] - 65 - param) % 26) + 65;
		if (islower(cipher[i]))
			decoded += ((cipher[i] - 97 - param) % 26) + 97;
	}

	return decoded;


}





