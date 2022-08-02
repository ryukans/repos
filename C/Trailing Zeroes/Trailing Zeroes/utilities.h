#include <math.h>

enum boolean { FALSE, TRUE };

unsigned trailing_zeros(
	unsigned number
);

unsigned trailing_zeros(unsigned n)
{
	unsigned zeros;

	zeros = 0;
	while (n > 0 && !(n & 01)) {
		++zeros;
		n >>= 1;
	}

	return zeros;
}
/*
unsigned trailing_zeros(unsigned n) {
	unsigned zeros = 0;

	if ( n ) {
		if (!(n & 0x0000FFFF)) { zeros += 16; n >>= 16; }
		if (!(n & 0x000000FF)) { zeros += 8; n >>= 8; }
		if (!(n & 0x0000000F)) { zeros += 4; n >>= 4; }
		if (!(n & 0x00000003)) { zeros += 2; n >>= 2; }
		zeros += (n & 1) ^ 1;
	}
	return zeros;
}
*/


int itob(int dec)
{
	int bin; /* binary value */
	int exp; /* exponent */
	int rem; /* reminder */
	int bits; /* bits counter */
	int negative_flag = FALSE;

	if (dec < 0) {
		dec = abs(dec);
		negative_flag = TRUE;
	}
	else if (dec == 0) {
		bin = 0;
		return bin;
	}


	bits = bin = rem = 0;
	exp = 1;
	while (dec != 0)
	{
		rem = dec%2;

		/*
		* Execute only if the reminder equals to 1, otherwise it would be useless
		* to do so if the value is 0 because the result of the expression will be 0.
		*/
		if (rem) { bin+=exp; }

		dec/=2;
		exp*=10;
		++bits;
	}

	if (negative_flag == TRUE)
		bin+=pow(10, bits);

	return bin;
}


