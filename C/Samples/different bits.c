/*
 *
 * Author: Claudio Pisa
 * Name: Different bits
 * Date: 24/06/2017 18:42
 * Description: The function counts the number of different bits between two numbers.
 *
 */
#include <stdio.h>

unsigned int different_bits(
    unsigned long long stream0,
    unsigned long long stream1
);

int main()
{
    unsigned long long n0, n1;

    n0 = 4; /* Binary: 00000100 */
    n1 = 7; /* Binary: 00000111 */

    printf("%d\n", different_bits(n0, n1));

    return 0;
}


unsigned different_bits(unsigned long long x, unsigned long long y)
{
    unsigned long long xor; /* Stores the result from the XOR operation */
    unsigned bits; /* Stores the number of different bits between the two numbers */

    xor = x ^ y;
    bits = 0;
    while (xor) {
        bits += (xor & 01);
        xor >>= 1;
    }

    return bits;
}


