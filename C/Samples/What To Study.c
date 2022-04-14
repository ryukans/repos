/*
    Author: Claudio Pisa
    Name: What to study v2.1
    Copyright: None
    Date: 27/02/2017 20:37
    Description: None
*/

#include <stdio.h>
#include <stdlib.h>
#include "utilities.h"
#define SUBJECTS 7
#define MAXSIZE 23 /* Max string size */

typedef char byte;

int main()
{
	srand(time(NULL));

	byte column, row, counter;
	char subjects_table[SUBJECTS][MAXSIZE] = 
	{	"MATH",
		"TPSIT",
		"SYSTEMS AND NETWORKS",
		"ENGLISH",
		"JAVA PROGRAMMING",
		"C PROGRAMMING",
		"HAVE A SHOWER FIRST ;]" };

	counter = 3;
	while(counter >= 0){
		banner();
		row = random(row, 6, NULL);

		for(column = 0; column < MAXSIZE-1; column++)
			putchar(subjects_table[row][column]);
		printf("%c%c", 0x07, 0x0A);

		counter = input_menu(counter);
	}
	return EXIT_SUCCESS;
}