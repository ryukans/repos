/*
 *
 *  Author: Claudio Pisa
 *  Name: setbits
 *  Copyright: None
 *  Date: 28/06/2017 22:01
 *  Description: Exercise 2-6 p.49
 *
 */

unsigned setbits(
	unsigned x,
	int p,
	int n,
	unsigned y
);


int main()
{
	unsigned x = 0;
	unsigned y = 203;

	/*
	 *
	 * 00000000 (setbits) 11001011 = 00101100
	 * ------------------------------
	 *
	 *    ~(~0)  << n(4)     = 11110000 (mask)
	 * 00001111  &  11001011 = 00001011 (mask & y)
	 * 00001011  << p(5)+1-n = 00101100 (left-shifted mask)
	 * 00000000  |  00101100 = 00101100 (x | left-shifter mask)
	 * 00101100
	 *
	 */

	x = setbits(x, 5, 4, y);

	printf("%d\n", x); // 44

	return 0;
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	unsigned mask;

	mask = ~(~0 << n);

    return x | ((mask & y) << (p+1-n));
}

