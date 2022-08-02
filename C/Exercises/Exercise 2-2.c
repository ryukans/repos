/*
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
#define LINE_FEED '\x0a'
#define MAXCHARS 100
#define TRUE 1

main()
{
	char line[MAXCHARS];
	int i = 0;
	int c;


	
	while(TRUE){
		
		if(i < MAXCHARS-1){
			
			if((c = getchar()) != LINE_FEED){
			line[i++] = c;
			}
			
			else if(c == LINE_FEED){
				break;
			}
			else if(c == '\n'){
				break;
			}
		
		}
		
		if(i > MAXCHARS-1){
			break;
		}
	}
	
	return 0;
}
