#include <stdio.h>
#include "swap.h"

int main()
{
	int n1 = 5, n2 = 8;

	__swap__(int, n1, n2);
	__print__(n1, n2);
	__xorswap__(n1, n2);
	__print__(n1, n2);
	_sumswap_(n1, n2);
	

	return 0;
}
