/*
    Name: Exercise 2-2
    Author: Claudio Pisa
    Date: 26/03/17
    Description:

    for(i = 0; i < MAXCAHRS-1 && (c = getchar()) != LINE_FEED; ++i)
	    line[i] = c;


    Write a loop equivalent to the for loop above without using && or ||.
*/

/*
OLD DOCUMENTATION:

	Name: Getline
	Copyright: NONE
	Author: Claudio Pisa
	Date: 22/08/16 19:42
	Description: Exercise 2-2 p.38


	for(i = 0; i < MAXCAHRS-1 && (c = getchar()) != LINE_FEED; ++i){
	    line[i] = c;
    }


Write a loop equivalent to the for loop above without using && or ||.
*/


#include <stdio.h>
#define MAXCHARS 100

int main()
{

	char line[MAXCHARS];
	int i = 0;
	int c;

    while(i < MAXCHARS-1){
        if((c = getchar()) == EOF)
            break;
        else if(c == '\n')
            break;
        else
            line[i++] = c;
	}

	if(c == '\n')
        line[i++] = c;
    line[i] = '\0';

	printf("%s", line);

	getch();

	return 0;
}

