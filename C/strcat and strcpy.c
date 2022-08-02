#include <string.h> 
#include <stdio.h>

main()
{

	char array[500] = "Hello World !";
	
	strcat(array, " Ciao Mondo !");
	printf("%s", array);
	
	printf("\n\n");
		
	strcpy(array, "Just deleted previous staff");
	printf("%s", array);
	
	return 0;


}
