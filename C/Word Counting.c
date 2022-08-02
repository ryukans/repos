#include <stdio.h>

main(){
	
	int c, newline, newWord, newchar, blanks = 0;
	
	while ((c = getchar()) != EOF){
		++newchar; //Chars counter
		
		if (c == '\n') //New line counter 
			++newline;
		if (c == ' ')
			++blanks;
		if (c == ' ' || c == '\t' || c == '\n')
			++newWord; //New words counter
		if (c == EOF)
			break;
	}
	
	printf ("Total newline: %d \n Total words: %d \n Total chars: %d \n Total blanks: %d", newline-1, newWord-1, newchar-newline-blanks, blanks);
	
}
