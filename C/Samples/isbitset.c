#include <stdio.h>

enum boolean { FALSE, TRUE };

int isbitset(
	unsigned long long int bit_stream,
	unsigned int position
);


int main()
{
	unsigned long long int stream;

	stream = 2ULL; /* 00000010 */

	printf("%d\n", isbitset(stream, 2));

    return 0;
}


int isbitset(unsigned long long int x, unsigned int y)
{
	unsigned long long int mask;

	mask = 1;

	x >>= y-1;

    return (x & mask) ? TRUE : FALSE;
}

