#include <stdio.h>

main(){
	
	int x, nlopt, nwopt, Copt_1, Copt_2, bopt, c, newline, newWord, Char, blanks = 0;
	
	printf ("*Counting options*\n\n 1.New line\n 2.New word\n 3.New char\n 4.Blank");
    scanf ("%d", &x);
    
    if (x == 1){
    	printf  ("New line options\n\n 1.Count EOF chars\n 2.Do not count EOF chars") ;
    	scanf ("%d", &nlopt);
    }
    else if (x == 2){
    	printf ("*New word options\n\n 1.Count EOF\n 2.Do not count EOF");
    	scanf ("%d", &nwopt);
    }
    else if (x == 3){
    	printf ("1.B");
    	printf ("*Char options\n\n 1.Count new line(s)\n 2.Do not count new line(s)\n");
    	scanf ("%d", Copt_1);
	}
	
	
	while ((c = getchar()) != EOF){
		++Char; //Chars counter
		
		if (c == '\n') //New line counter 
			++newline;
		if (c == ' ')
			++blanks;
		if (c == ' ' || c == '\t' || c == '\n')
			++newWord; //New words counter
		if (c == EOF)
			break;
	}
	
	printf ("Total newline: %d \n Total words: %d \n Total chars: %d \n Total blanks: %d", newline-1, newWord-1, Char-newline-blanks, blanks);
	
}

