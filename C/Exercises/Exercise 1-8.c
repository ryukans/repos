#include <stdio.h>


//Exercise 1-8 p.20
	
main(){
	
	int newline = 0;
	int tab = 0;
	int blank = 0;
	int c;

		printf("Write down here:    **Ctrl+Z+Enter to stop (after a newline)**\n");

	while ((c = getchar()) != EOF){ //begin while
	
		if (c=='\n')
			++newline;
		if (c=='\t')
		    ++tab;
		if (c==' ')
		   ++blank;
    } //while stops
		
	printf("Total new lines: %d\n",newline);
	printf("Total tabs: %d\n",tab);
	printf("Total blanks: %d",blank);


}
