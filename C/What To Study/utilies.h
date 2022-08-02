#include <stdio.h>
#include <stdlib.h>

typedef char byte;

void banner();
byte random(byte, byte, byte);
byte input_menu(byte);

void banner()
{
	byte times = 3;

	printf("The subject u are gonna study today is");
	while(times--){
		Sleep(1000);
		printf("%c%c%c", 0x20, 0x2E, 0x20);
	}
}


byte random(byte x, byte y, byte z)
{ return x = rand() % (y + 1) + z; }


byte input_menu(byte counter)
{
	byte ch;

	if(counter == 0){
		printf("\nYou cannot go further !\n");
		pause();
		exit(0);
	}
	else{
		while(1){
            printf("\n\nTry again ? Max repetitions: %d\n\n\nSpace to continue\nEsc to exit\n", counter);
			ch = getch();
			if(ch == 0x20){
				--counter;
                clear();
				break;
			}
			else if(ch == 0x1B){
				clear();
				exit(0);
			}
			else{
				clear();
				printf("Error!\n");
				pause();
				clear();
			} //end of inner else statment
		} //end of while statment
	} //end of the outer else statment
	return counter;
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