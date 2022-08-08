#include <stdio.h>
#include <limits.h>

int main()
{
    char n = CHAR_MIN;

    printf("%d", n);

    n = -n;

    printf("%d", n);


    return 0;
}
