#include <stdio.h>

/* TODO: DOCUMENTATION */

unsigned checkbit(
    unsigned long long stream,
    unsigned position
);


int main()
{
    unsigned long long stream = 4ULL;

    printf("%d\n", checkbit(stream, 2));


    return 0;
}


unsigned checkbit(unsigned long long x, unsigned y)
{
    return (x >> y) & 01;
}
