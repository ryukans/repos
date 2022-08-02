#include <stdio.h>

enum boolean { FALSE, TRUE };

int is_even(
	unsigned long long int bit_stream
);

int is_even(
	unsigned long long int bit_stream
);


int main()
{
	unsigned long long int stream;

	stream = 2ULL;

	printf("%d\n", is_even(stream));
    system("pause");

	printf("%d\n", is_odd(stream));
	system("pause");

	return 0;
}


int is_even(unsigned long long int x)
{
	if(x & 1)
		return 1;
	else
		return 0;
}


int is_odd(unsigned long long int x)
{
	if(x ^ 0)
		return 1;
	else
		return 0;
}
