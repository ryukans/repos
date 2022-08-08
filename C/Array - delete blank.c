
#include <stdio.h>
#define LEN 12 //Array lenght

main()
{
	char list[LEN] = "Hello World";
	int index = 0;
	
	for (index = 0; index < LEN; ++index)
		if (list[index] == ' ')
			;
		else
			printf ("%c", list[index]);
	
	
}
