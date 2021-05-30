#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define RANDOM(X, Y, Z) ((X) = rand() % (Y) + (Z))
#define RESET(X) ((X) = 0)

//enum boolean{FALSE = 0, TRUE = 1};
/*enum random{RAND_CHAR = 0, RAND_NUMBER = 0
};*/

void change_color(void);

void menu(void);

int main()
{
	srand(time(NULL));
	int i, counter, rand_char, rand_int, rand_gap;


	while(1){
		change_color();
		putchar(RANDOM(rand_char, 222, 33));
		counter++;
		if(counter > (RANDOM(rand_int, 15, 1))){
			RANDOM(rand_gap, 500, 1);
			for(i = 0; i < rand_gap; i++)
				putchar('\x20');
			RESET(counter); /* New word */
		}

	}

	return EXIT_SUCCESS;
}

void change_color(void)
{
	char command[7] = "color 0";
	int font, flag;
	int i = sizeof(command)/sizeof(char);


	if(!RANDOM(flag, 2, 0)){
		RANDOM(font, 9, 1);
		command[i] = font + '0';
	}
	else{
		RANDOM(font, 5, 65);
		char tmp = font;
		command[i] = tmp;
	}

	command[++i] = '\0';

	system(command);
}

void menu(void)
{
	char ch, ch_2;
	printf("1.Start\n2.Options\n>");
	getchar(ch);
	switch(ch){
		case '1':
			return 1;
			break;
		case '2';
			printf("1.Set max word length\n2.Set gap\n3.Colours options\n>");
			getchar(ch);
			switch(ch){
				case '1':
					printf("Type word length\nMax value is 100>: ");
					scanf("%d", &/*VARIABLE*/);
					if(/*VARIABLE*/ > 100 && /*VARIABLE*/ < 0)
						printf("Error");
					break;
				case '2':
					printf("Type gap length\nMax value is 3500>: ");
					scanf("%d", &/*VARIABLE*/);
					if(/*VARIABLE*/ > 3500 && /*VARIABLE*/ < 0)
						printf("Error");
					break;
				case '3':
					printf("1.Chage background colour\n2.Change font colour\n> ");
					getchar(ch_2);
					switch(ch_2){
						case '1':
							/* Set flag on/off */
							break;
						case '2':
							/* Set flag on/off */
							break;
						default:
							printf("Error !");
					} //Third switch
					break;
				default:
					printf("Error !");
			} // Second switch
			break; // case 2 - switch 1
		default:
			printf("Error !");

	} // First switch

}
