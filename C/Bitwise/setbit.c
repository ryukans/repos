/*
 *
 * Author: Claudio Pisa
 * Name: Set bit
 * Date: 24/06/2017 18:42
 * Description:
 *
 * The program set one bit ON in a binary stream.
 *
 * stream:		decimal = 2 in binary = 00000010
 * position:	decimal = 5 in binary = 00000101
 * mask:		decimal = 1 in binary = 00000001
 *
 * We want to set the fifth bit ON (we are counting from 0), to do so a mask is needed.
 * Initially the value of the mask is 1, then it's shifted over the number of times for the position
 * After shifting: 00100000 i.e. 32 in decimal notation.
 * Afterwards an OR operation is done between the bit stream and the new value of the mask:
 *
 *    		00000010
 *   	 OR
 *   		00100000
 *   	   ----------
 *   		00100010
 *
 * The result is 00100010 i.e. 34 in decimal notation.
 * Basically in the example nothing has been done but multiplying 2 times 32.
 *
 */

#include <stdio.h>

unsigned long long int setbit(
	unsigned long long stream,
	unsigned position
);


int main()
{
	unsigned long long stream;

    stream = 2ULL;

    printf("%lld\n", setbit(stream, 5));
	system("pause");

	return 0;
}


unsigned long long setbit(unsigned long long x, unsigned y)
{
	int mask;

	mask = 1 << y;

	return x | mask; /// Briefed: x |= 1 << y
}





