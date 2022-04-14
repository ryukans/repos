#include <stdio.h>

main(){
	int c, line;
	line = 0;
	
	while ((c = getchar()) != EOF)
		if (c=='\n')
			++line;
	printf("%d",line);

}
