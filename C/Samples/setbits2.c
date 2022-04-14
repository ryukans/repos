#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y);

int main()
{ //00000000 - 11001011 = 00101100

    printf("%d\n", setbits(0, 5, 4, 203));

    return 0;
}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0<<n)) << (p+1-n);
}
