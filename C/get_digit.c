///Original code: http://stackoverflow.com/questions/36992639/pow-function-weird-behavior-when-used-in-brackets-and-with-long-long-integer?rq=1;

#include <stdio.h>
#include <stdlib.h>

int extract_digit(int n, int index);

int main()
{
    int n, index;

    printf("Type number\n>: ");
    scanf(" %d", &n);
    printf("Type the number position (from dx to sx)\n>: ");
    scanf(" %d", &index);

    int digit = extract_digit(n, index);

    printf("\n> %d", digit);

    return EXIT_SUCCESS;
}

int extract_digit(int n, int index)
{
    n /= pow(10, index-1);
    int digit = n % 10;

    return digit;
}
