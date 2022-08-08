/*
 *
 * Author: Claudio Pisa
 * Name: Different bits
 * Date: 25/06/2017 14:32
 * Description: The function counts the number of different bits between two numbers.
 *
 */
#include <stdio.h>

unsigned int count_different_bits(
    unsigned long long int first_bitstream,
    unsigned long long int second_bitsream
);

int main()
{
    unsigned long long int n0, n1;

    n0 = 4; /* Binary: 00000100 */
    n1 = 7; /* Binary: 00000111 */

    printf("%d\n", count_different_bits(n0, n1));

    return 0;
}


unsigned int count_different_bits(unsigned long long int x, unsigned long long int y)
{
    unsigned long long int xor; /* Stores the result from the XOR operation */
    unsigned int bits; /* Stores the number of different bits between the two numbers */

    xor = x ^ y;
    bits = 0;
    while(xor){
        bits += xor & 1;
        xor = xor >> 1;
    }

    return bits;
}

