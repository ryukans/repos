#include <stdio.h>
#include "utilities.h"

int main()
{
	unsigned i, n;
	
	for (i = 0, n = 0; i <= 32; ++i, ++n)
		printf("-\nNumber: %d -> (%d)2\nNumber of trailing zeroes: %d\n-\n",
			n, itob(n), trailing_zeros(n));

	getch();

	return 0;
}