#include <stdio.h>

int main()
{
	unsigned x;

	printf("Number: ");
	scanf("%u", &x);
	printf("Total 1-bits: %d\n", bitcount(x));

	putchar('\n');

	system("pause");

	return 0;
}


int bitcount(unsigned x)
{
	int b;

	for(b = 0; x != 0; ++b)
		x &= (x-1);
	return b;
}
