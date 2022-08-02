#include <stdio.h>
#include <math.h>

int main()
{
    char n[] = "15,1";
    int i = 0;
    int exp = 1;
    double n2 = 0.0;

    while (i < strlen(n)) {
        if (n[i] == ',' || n[i] == '.') {
            double tmp = n[i] - '0';
            tmp /= pow(10, exp);
            n2 += tmp;
            ++exp;
        }
        else {
            n2 = n2 * 10 + n[i] - '0';

        }
        ++i;
    }

    printf("%f\n", n2);

    return 0;
}
