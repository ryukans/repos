#include <stdio.h>
#define RANDOM(X, Y, Z) ((X) = rand() % (Y) + (Z))

int main()
{
	srand(time(NULL));

	char command[8] = "color ";
	int font, flag, i, j;

	for(i = 6; i < 8; i++){
		if(!RANDOM(flag, 2, 0)){
			RANDOM(font, 9, 0); /* Frotm 0 to 9 */ 			
			command[i] = font + '0';	
		}
		else{
			RANDOM(font, 6, 65); /* From A to F */
				char tmp = font;
				command[i] = (char) font;
			
		}
	}
	
	command[8] = '\0';
	
	printf("%s\n", command);
	
	system(command);


}
