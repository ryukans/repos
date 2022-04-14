#include <stdio.h>
#include <stdlib.h>
#define STRING_SIZE 150 /* WORD SIZE */
#define RANDOM(X, Y, Z) ((X) = rand() % (Y) + (Z))
#define RESET(X) ((X) = NULL)
//#define RESET_ARRAY(X[])

enum boolean{ FALSE, TRUE };

void change_color(int);
void get_line(char[]);

int main()
{

	srand(time(NULL));

	char line[STRING_SIZE];
	int i, counter, rand_char, rand_int, rand_gaps, value;

	while(TRUE){  /* From 0 to n (From 0 to 3 is raccommended) */
		(!RANDOM(value, 4, FALSE)) ? change_color(TRUE) : change_color(FALSE); /* Color change rate */
		get_line(line);
		puts(line); /* From 1 to 10 */
		RANDOM(rand_gaps, 10, 1); /* Gap size */
		for(i = 0; i <= rand_gaps; i++)
			putchar('\t');
	}

	return EXIT_FAILURE;

}

void change_color(int permit)
{
	#define COMMAND_SIZE 20

	if(!permit)
		NULL;

	else{
		int i, value, rand_backgroud_color, rand_font_color;
		char command[COMMAND_SIZE];

	#if 0
		/*If 'value' equals to 0 a random number will be generated from 48 to 57, i.e. decimal value of 0, 1, 2, 3... 9
		else a random number will be generated form 65 to 5, i.e. decimal value of A, B, C, D... F */
		if(!RANDOM(value, 2, NULL)) // Get background color
			RANDOM(rand_backgroud_color, 10, 48);
		else
			RANDOM(rand_backgroud_color, 6, 65);


		if(!RANDOM(value, 2, NULL)) // Get font color
			RANDOM(rand_font_color, 10, 48);
		else
			RANDOM(rand_font_color, 6, 65);

		sprintf(command, "color %c%c", rand_backgroud_color, rand_font_color);
	#endif


		char keys[16] = "0123456789ABCDEF";
		sprintf(command, "color %c%c", keys[RANDOM(rand_backgroud_color, 16, NULL)], keys[RANDOM(rand_font_color, 16, NULL)]);
		//sprintf(command, "color 0%c", keys[RANDOM(rand_font_color, 16, NULL)]);
		system(command);
	}

}

void get_line(char line[])
{
	char rand_char;
	int i, rand_size;

	for(i = 0; i < STRING_SIZE; i++) /* Array reset */
		line[i] = 0;


	for(i = 0; i < RANDOM(rand_size, STRING_SIZE, NULL); i++)
		line[i] = RANDOM(rand_char, 222, 33);

}

