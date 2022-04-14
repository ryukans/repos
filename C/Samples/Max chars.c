#include <stdio.h>
#define MAXCHAR 8

main()
{
	char password[MAXCHAR];
	int i;
	char c;
	
	printf("Insert password: MAX 8 CHARS!\n\n");
	for(i = 0; i <= MAXCHAR; i++){
		c = getchar();

		if(i == MAXCHAR){
			break;
		}
		else{
			password[i] = c;
		}
	}

	printf("%s\n", password);

}
