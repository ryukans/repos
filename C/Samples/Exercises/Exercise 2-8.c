/*
 *
 * Author: Claudio Pisa
 * Name: rightrot
 * Copyright: None
 * Date: 28/06/2017 23:30
 * Description: Exercise 2-8 p.49
 *
 */
#include <stdio.h>

int wordlength(void);

int bitlen(unsigned d);

unsigned rightrot(
	unsigned bitseteam,
	int number_of_bits
);

int main()
{  // 11000110 - 11011000 (rotated)
   // 00000111 & 11000110 = 00000110 (mask)
   // 00011000 (right-shifted x)
   // 00000110 << 8-n
   // 11000000
   // 00011000 | 1100000 = 11011000

	unsigned x = 198;

	x = rightrot(x, 3);

	printf("%u\n", x); // 216

	// 00110001 | 10000000 = 10110001

	return 0;
}


unsigned rightrot(unsigned x, int n)
{
	unsigned mask;

	mask = (~(~0 << n) & x);

	x = x >> n;

	return (mask << wordlength()-n) | x;
}


int wordlength()
{
	int word_size;
	unsigned word = (unsigned) ~0;

	while(word){
		word = word >> 1;
		++word_size;
	}

	return word_size;
}
