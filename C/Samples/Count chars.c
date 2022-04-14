#include <stdio.h>
#include <stdlib.h>

enum char_set { ESC = 0x1b, LINE_FEED = 0x0a, SPACE = 0x20 };
void input_menu(void);
void clear(void);

int main(){

	unsigned long int count;

	while(1){
        printf("Type down below\n\n>: ");
        count = 0;
        while(getchar() != LINE_FEED)
            ++count;

        clear();
        printf("Total characters:\n> %d\n", count);
        input_menu();
    }

    getch();
    return 0;
}

void input_menu(void)
{
    char ch;

    while(1){
        printf("\nSpace to continue\nEscape to exit\n");
        ch = getch();

        if(ch == ESC)
            exit(0);

        else if(ch == SPACE){
            clear();
            break;
        }

        else{
            clear();
            printf("Error! Invalid input\n");
        }

    }
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

