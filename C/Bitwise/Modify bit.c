#include <stdio.h>

enum boolean { FALSE, TRUE };

unsigned long long int modifybit(
	unsigned long long int bitstream,
	unsigned int position,
	unsigned int state
);


int main()
{
	unsigned long long int stream;

	stream = 2ULL;

	printf("%d\n", stream = modifybit(stream, 5, 7));
	system("pause");

	return 0;
}


unsigned long long int modifybit(unsigned long long int x, unsigned int y, unsigned int state)
{
	unsigned long long int mask;

	mask = 1 << y;

	return (x & ~mask) | (-state & mask);
}

