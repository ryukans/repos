unsigned bitcount(
	unsigned long long stream
);

unsigned bitcount(unsigned long long x)
{
	unsigned bits;

	bits = 0;
	while (x) {
		++bits;
		x >>= 1;
	}

	return bits;
}


