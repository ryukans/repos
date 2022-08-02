#include <stdio.h>

void xorswap(
	unsigned *x,
	unsigned *y
);


int main()
{
	unsigned x, y;

	x = 4; // 00000101
	y = 7; // 00000110

	printf("%d -- %d\n", x, y);

	xorswap(&x, &y);

	printf("%d -- %d\n", x, y);

	system("pause");

	return 0;
}


void xorswap(unsigned *x, unsigned *y)
{
	*x ^= *y ^= *x ^= *y;
}

/*

x=	100
y=	111

x=	011
y=	111

x=	011
y=	100

x=	111
y= 	100

*/
