#include <stdio.h>

/*
    x = 0;

    00000101

    -x = 1;

    00000001
xor
    00000101
    00000100


    00000100
and
    00000100
    00000100

    00000101
xor
    00000100
    00000001

*/

int main()
{


    return 0;
}



unsigned long long change(unsigned long long x, unsigned y, unsigned z)
{
    return x ^= (-z ^ x) & (1 << y);
}








