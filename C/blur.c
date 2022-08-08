#include <stdio.h>

int main()
{
    int i, j;

    while(1){
        system("color 4");

        for(i = 0; i < 15; ++i)
            for(j = 0; j < 85; ++j)
                printf("%c", 0xb2);

        system("color 2");

        for(i = 0; i < 15; ++i)
            for(j = 0; j < 85; ++j)
                printf("%c", 0xb1);

        system("color 1");

        for(i = 0; i < 15; ++i)
            for(j = 0; j < 85; ++j)
                printf("%c", 0xb0);
    }

    return 0;
}
