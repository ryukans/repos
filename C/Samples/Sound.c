#include <stdio.h>
#include <windows.h>

unsigned long int random(
    unsigned long int x,
    unsigned long int y
);

int main(void)
{
    srand((unsigned int) time(0));

    int i;
    unsigned long rand_freq, rand_duration;

    for(i = 0; i <= 1000; i++){
        rand_freq = random(1500, 500);
        rand_duration = random(50, 10);
        printf("N\t\tFrequency\t\tDuration\n%d\t\t%d\t\t\t%d\n\n", i, rand_freq, rand_duration);
        Beep(rand_freq, rand_duration);
        Sleep(500);
    }

    getch();

    return 0;
}


unsigned long int random( unsigned long int x, unsigned long int y)
{
    if(!x && !y)
        return rand();
    else
        return rand() % (x + 1) + y;
}



