#include <stdio.h>

main()
{

	char array[] = {'a','b','c','d'};
	int digits[10] = {0,1,2,3,4,5,6,7,8,9};
	int index, lenght;

	for(index = 0, lenght = 0; array[index] != '\0'; ++index, ++lenght){
		;
	}// only for char array

	printf("%d\n", sizeof(array));

	printf("%d\n", sizeof(digits)/sizeof(int)); /* int(4 bytes) * number_of_indexes = n; n / int = size_of_int_array */

	printf("len: %d\nindex: %d", lenght, index);

	return 0;
}
