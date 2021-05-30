#include <stdio.h>
#include <math.h>

enum boolean { FALSE, TRUE };
enum divisors { DOT = '.', COMMA = ',' };

int length(char array[]);

int main()
{
    char n[] = "15,1234";
    int i;
    int flag = FALSE;
    int exp = 1;
    double n2 = 0.0;

    for(i = 0; i < length(n); i++){

        if(n[i] == COMMA || n[i] == DOT) {
                double temp = n[++i] - '0';
                temp /= pow(10, exp);
                n2 += temp;
                exp++;
		}
        else
            n2 = n2 * 10 + (n[i] - '0');
    }

    printf("%f", n2);

    return 0;
}

int length(char line[])
{
    int i = 0;
    while(line[i] != '\0')
        i++;

    return i;
}

