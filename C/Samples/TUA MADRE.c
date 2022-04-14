#include <stdio.h>
#include <stdlib.h>
#define STRING_SIZE 70
#define RANDOM(X, Y, Z) ( (X) = rand() % (Y) + (Z) )

void change_color(void);

//void get_line(char line[]);

int main()
{
	srand(time(NULL));
	char line[] = "TUA MADRE !!!!\n";
//	char line2[STRING_SIZE];

	while(1){
		change_color();
	//	get_line(line2);
	//	printf("%s", line2);
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\%s", line);
		system("cls");

	}

	return EXIT_FAILURE;
}


void change_color()
{
	char keys[16] = "0123456789ABCDEF";
	char command[20];
	int background, font;

	sprintf(command, "color %c%c", keys[RANDOM(background, 16, NULL)], keys[RANDOM(font, 16, NULL)]);

	system(command);
}

#if 0
void get_line(char line[])
{
	char rand_char;
	int str_size;
	int i;

	for(i = 0; i < STRING_SIZE; i++) /*Reset the array */
		line[i] = 0;

	i = 0;
	while(i < RANDOM(str_size, STRING_SIZE, NULL))
		line[i++] = RANDOM(rand_char, 222, 33);

}
#endif
