/*
 *
 * Author: Claudio Pisa
 * Name: invert
 * Copyright: None
 * Date: 28/06/2017
 * Description: Exercise 2-7 p.49
 *
 */
#include <stdio.h>

unsigned invert(
	unsigned x,
	int p,
	int n
);


int main()
{
	// 10011010
	// 11110000 (maks)
	// ~mask = 00001111
	// 00001111 << (p+1-n)
	// 01111000
	// xor
	// 10011010
	//
	// 11100010

	unsigned x = 154;

	x = invert(x, 6, 4);

	printf("u\n", x);

	return 0;
}


unsigned invert(unsigned x, int p, int n)
{
	unsigned mask;

	mask = (~(~0 << n) << p+1-n);

	return x ^ mask;
}