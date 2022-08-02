#include <stdio.h>
#include <stdlib.h>

typedef char byte;

void banner();
void clear();
void pause();
byte random(byte, byte, byte);
byte input_menu(byte counter);

void banner()
{
	byte times = 3;

	printf("The subject u are gonna study today is");
	while(times--){
		//Sleep(1000);
		printf("%c%c%c", 0x20, 0x2E, 0x20);
	}
}

byte random(byte x, byte y, byte z)
{ return x = rand() % (y + 1) + z; }

byte input_menu(byte attempts)
{
	byte ch;

    while(1){
        !attempts ? printf("Attemps exhausted!\nPress any key to continue.\n") : \
        printf("\n\nTry again ? Attempts remaining: %d\n\n\nSpace to continue\nEsc to exit\n", attempts-1);
        ch = getch();
        if(ch == 0x20){
            --attempts;
            clear();
            break;
        }
        else if(ch == 0x1B){
            clear();
            attempts = 0;
            break;
        }
        else{
            clear();
            printf("Error!\n");
            pause();
            clear();
        }
    }

    return attempts;
}

void clear()
{
	#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}

void pause()
{
	printf("Press any key to continue.\n");
	getch();
}
