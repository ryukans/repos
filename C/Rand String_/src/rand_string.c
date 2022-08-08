/*
	Author: Claudio Pisa
	Name: Rand String v1.5.1
	Copyright: None
	Date: 06/07/2017 13:43
	Description: N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include "io_utilities.h"
#include "fx.h"



int main()
{
	flag casetype;
    char string[MAXSIZE];
	int strings, stringsize;

	/*
	drawtableX(10, 1);
	drawtableY(15, 0, 4);
	drawtableX(10, 0);*/


	srand(time(NULL));

	printf("String type\n");
	drawline(11);
	putchar(LF);
    stringsize = size(); /* Get size of the string */
	strings = totalstrings(); /* Get the number of strings have to be generated */

	clear();

	printf("Options\n");
	drawline(7);
	putchar(LF);
	settings();

	clear();

	int lb = 1; /* Label; used for a formatted output */
	while(strings--){
		generatestring(string, stringsize); /* Generate the random string */
		printf("\n%d> %s\n\n", lb++, string);
	}

	pause("\nPress any key to exit.\n", True);
	clear();



	return EXIT_SUCCESS;
}
