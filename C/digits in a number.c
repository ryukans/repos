// Source: http://www.dreamincode.net/forums/topic/364353-How-many-digits-in-a-number%3F/
#include <stdio.h>
#include <math.h>

int main()
{
    long myNumber = 145634521L;    // Set to any number that can be represented by signed long.

    if(myNumber < 0)
        myNumber = abs(myNumber);

    long numDigits = myNumber > 0 ? log10(myNumber) + 1 : 1;

    printf("Number of digits is %ldn", numDigits);

    return 0;
}
