#include <stdio.h>

/* TODO: BETTER DOCUMENTATION

        00100000 mask
    XOR
        00100010 stream
        00000010

*/

unsigned long long int flipbit(
	unsigned long long int stream,
	unsigned int position
);

int main()
{
	unsigned long long int stream;

    stream = 34UL;

    printf("%lld\n", flipbit(stream, 5));
    system("pause");

	return 0;
}

unsigned long long int flipbit(unsigned long long int x, unsigned int y)
{
	unsigned long long int mask;

	mask = 1 << y;

	return x ^ mask;  /// Briefed: x ^= 1 << y
}

