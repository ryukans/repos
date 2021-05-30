#include <stdio.h>
#include <stdlib.h>
#define RANDOM(X, Y, Z) ((X) = rand() % (Y) + (Z))
#define RESET(X) ((X) = NULL)

//enum boolean{FALSE = 0, TRUE = 1};
/*enum random{RAND_CHAR = 0, RAND_NUMBER = 0
};*/

void change_color(int value);

int main()
{
	srand(time(NULL));
	int i, counter, rand_char, rand_int, rand_gap, value;

	while(1){
		if(!RANDOM(value, 2, NULL))
			change_color(1);
		else
			change_color(NULL);

		putchar(RANDOM(rand_char, 222, 33));
		counter++;
		if(counter >= (RANDOM(rand_int, 150, 1))){ /* Word size */ 
			RANDOM(rand_gap, 50, 1); /* Gap size */ 
			for(i = 0; i <= rand_gap; i++)
				putchar('\x20');
			RESET(counter); /* New word */
		}
		
	}

	return EXIT_SUCCESS;
}

void change_color(int value)
{
	if(!value)
		NULL;
	else{
		char command[8] = "color ";
		int font, flag, i, j;

		for(i = 6; i < 8; i++){ 
			if(!RANDOM(flag, 2, NULL)){
				RANDOM(font, 9, NULL); /* Frotm 0 to 9 */ 			
				command[i] = font + '0';	
			}
			else{
				RANDOM(font, 5, 65); /* From A to F */
					char tmp = font;
					command[i] = tmp;
			
			}
		}
		command[8] = '\0';
		system(command);
	} /* End of else */
}

