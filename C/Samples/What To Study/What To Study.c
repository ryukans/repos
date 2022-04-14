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

	byte column, row, attempts;
	char subjects_table[SUBJECTS][MAXSIZE] =
	{	"MATH",
		"TPSIT",
		"SYSTEMS AND NETWORKS",
		"ENGLISH",
		"JAVA PROGRAMMING",
		"C PROGRAMMING",
		"HAVE A SHOWER FIRST ;]" };

	attempts = 4;
	while(attempts >= 0){
        if(!attempts){
            //printf("\nYou cannot go further !\n");
            break;
        }
        else{
            banner();
            row = random(row, 6, NULL);
            for(column = 0; column < MAXSIZE-1; column++)
                putchar(subjects_table[row][column]);
            printf("%c", 0x0A);
            attempts = input_menu(attempts);
        } //end of else statement
	} //end of while

    printf("\nREACHED! :D");
	pause();
	return EXIT_SUCCESS;
}
