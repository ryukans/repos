#include <stdio.h>

enum boolean { FALSE, TRUE };

int is_power_of_two(
	unsigned long long int bit_stream
);


int main()
{
	unsigned long long int stream;

	stream = 8;

	printf("%d\n", is_power_of_two(stream));
	system("pause");

	return 0;
}


int is_power_of_two(unsigned long long int x)
{
	if(!(x & ~x)) /* Alternative: if(!(x & x-1)) */
		return TRUE;
	else
		return FALSE;

}

