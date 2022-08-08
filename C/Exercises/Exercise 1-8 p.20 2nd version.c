#include <stdio.h>

//Exercise 1-8 p.20 2nd version
main(){
	
    int c;
    int newline;
    int tab;
    int blank;
    
    printf("Write down here:   Ctrl+Z+Enter to stop (after a newline)**\n");
    
    for (newline = 0, tab = 0, blank = 0; (c=getchar()) != EOF;) { //For starts
        if (c=='\n')
        	++newline;
        if (c=='\t')
        	++tab;
        if (c==' ')
        	++blank;
    } //For stops
   
   
    printf("Total new lines: %d\n",newline);
	printf("Total tabs: %d\n",tab);
	printf("Total blanks: %d",blank);

}
