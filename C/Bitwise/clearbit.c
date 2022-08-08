/*
 *
 * Author: Claudio Pisa
 * Name: Set bit
 * Date: 24/06/2017 18:42
 * Description:
 *
 * The program set one bit OFF in a binary stream.
 *
 * stream:		decimal = 34 in binary = 00100010
 * position:	decimal = 5  in binary = 00000101
 * mask:		decimal = 1  in binary = 00000001
 *
 * We want to set the fifth bit OFF (we are counting from 0), to do so a mask is needed.
 * Initially the value of the mask is 1, then it's shifted over the number of times for the position.
 * After shifting: 00100000 i.e. 32 in decimal notation.
 * The next step is to flip all the bits (if is 1 becomes 0 and vice versa) by using the bitwise NOT operator.
 * The mask from 00100000 becomes 11011111.
 * Afterwards an AND operation is done between the bit stream and the mask:
 *
 *    		00100010
 *   	AND
 *   		11011111
 *   	   ----------
 *   		00000010
 *
 * The result is 00000010 i.e. 2 in decimal notation.
 * Basically in the example nothing has been done but dividing 32 by 16.
 *
 */

#include <stdio.h>

unsigned long long clearbit(
	unsigned long long stream,
	unsigned position
);

unsigned long long __clearbit(
    unsigned long long stream,
    unsigned position
);


int main()
{
	unsigned long long stream;

    stream = 34ULL;

    printf("with clearbit >: %lld\n", clearbit(stream, 5));
    printf("with __clearbit >: %lld\n", __clearbit(stream, 5));

    system("pause");

	return 0;
}

unsigned long long clearbit(unsigned long long x, unsigned y)
{
	unsigned long long mask;

	mask = 1 << y;

    //mask = ~mask; pretty useless, can be avoided

	return x & ~mask; /// Briefed: x &= ~(1 << y)
}

/* __clearbit: alternative way using different mask. */
unsigned long long __clearbit(unsigned long long x, unsigned y)
{
	unsigned long long mask;

	mask = ~((~0U) << y);

    return x & mask; /// Briefed: x &= ~((~0U) << y)
} //TODO: Comment this method.


