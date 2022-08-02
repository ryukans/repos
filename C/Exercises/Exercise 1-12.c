#include <stdio.h>

// Exercise 1-12 p. 21

main(){
	
	int c;
	
	while ((c = getchar()) != EOF)
	{
	
		if (c == ' ' || c == '\t')
			putchar ('\n');
	    else
	    	putchar(c);
    }
}
