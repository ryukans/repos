unsigned trz(
	unsigned stream
);

unsigned trz(unsigned x)
{
	unsigned bits; /* number of trailing zeros */

	bits = 0;
	if (!(x & 0x0000ffff)) { bits += 16; x >>= 16; }
	if (!(x & 0x000000ff)) { bits +=  8; x >>=  8; }
	if (!(x & 0x0000000f)) { bits +=  4; x >>=  4; }
	if (!(x & 0x00000003)) { bits +=  2; x >>=  2; }

	bits += (x & 01) ^ 01; /* check LSB in the current state of the stream */

	return bits;
}