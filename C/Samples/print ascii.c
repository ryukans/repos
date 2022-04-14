#include <stdio.h>

int main()
{
    int i;

    for(i = 32; i < 127; ++i){
        if(!(i % 15) && i != 45)
            putchar('\n');
        putchar(i);
    }

    return 0;
}
