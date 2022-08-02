/*
	Author: Claudio Pisa
	Name: Rand String v1.0b
	Copyright: None
	Date: 12/03/2017 12:12
	Description: N/A
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

void clear(void);
void pause(void);

void get_line(
    char [],
    int
);
int random(
    int,
    int
);


int main()
{
	srand(time(NULL));

	char line[MAXSIZE];
	int times, size, count;

    size = get_size();

	printf("How many time do you want to generate a string ?\n> ");
	scanf(" %d", &times);

	clear();

    count = 1;
	while(times--){
		get_line(line, size);
		printf("\n%d> %s\n\n", ++count, line);
	}

	pause();

	return EXIT_SUCCESS;
}


void get_line(char line[], int size)
{
    char rand_char;
	int i, flag;

	i = 0;
	while(i < size){ /* Generate the string */
        if(!(flag = (random(5, 0)))) /* If is zero, put a space */
            line[i++] = 0x20;
        else
            line[i++] = rand_char = random(25, 65);
	}

	line[i] = '\0';
}


int random(int x, int y)
{ return rand() % (x+1) + y; }



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
	printf("\nPress any key to continue.\n");
	getch();
}
