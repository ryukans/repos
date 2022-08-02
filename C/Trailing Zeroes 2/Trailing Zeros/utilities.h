unsigned long long trz(
	unsigned long long stream
);

unsigned long long itob(
	unsigned long long dec
);

unsigned long long trz(unsigned long long x)
{
	unsigned long long bits; /* number of trailing zeros */

	bits = 0;
	if (!(x & 0xfffffffffffffff0)) { bits += 64; x >>= 64; }
	if (!(x & 0x00000000ffffffff)){ bits += 32; x >>= 32; }
	if (!(x & 0x000000000000ffff)) { bits += 16; x >>= 16; }
	if (!(x & 0x00000000000000ff)) { bits +=  8; x >>=  8; }
	if (!(x & 0x000000000000000f)) { bits +=  4; x >>=  4; }
	if (!(x & 0x0000000000000003)) { bits +=  2; x >>=  2; }

	bits += (x & 01) ^ 01; /* check LSB in the current state of the stream */

	return bits;
}

/* the function doesn't handle negative numbers */
unsigned long long itob(unsigned long long dec)
{
	unsigned long long bin;
	unsigned long long exp;
	unsigned rem;
	unsigned bits;

	if (dec == 0) { return bin = 0; }


	bits = bin = rem = 0;
	exp = 1;
	while (dec != 0)
	{
		rem = dec % 2;

		if (rem == 1) { bin += exp; }

		dec /= 2;
		exp *= 10;
		++bits;
	}

	return bin;
} 

