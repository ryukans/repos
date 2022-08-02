#include <stdio.h>

int pow(int base, unsigned int exp);

int main()
{
    unsigned int exp = 1;

    float temp = ('2' - '0');

    temp /= pow(10, exp);

    printf("%f", temp);

    return 0;
}

int pow(int base, unsigned int exp)
{
    if(exp == 0)
        return 1;
    else{
        int i;
        for(i = 1; i < exp; i++)
            base *= base;

        return base;
    }
}
