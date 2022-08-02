#include <stdio.h>

main(){
	
    int c;
    int newline;
    
    for (newline = 0; (c=getchar()) != EOF;); {
        if (c=='\n')
        	++newline;
    }
    printf("%d",newline);
}
