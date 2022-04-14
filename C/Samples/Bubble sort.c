#include <stdio.h>
#define MAX 6
main()
{

	int list[MAX];
	int i, y;
	int temp; //temporary varaible
	int swapped = 0;
	
	srand(time(NULL));
	
	for (i = 0; i < MAX; ++i){
		list[i] = (rand() % 80) + 1;
	}
	
	printf ("Original list:\n");
	printf ("--------------\n");
	
	for (i = 0; i < MAX; ++i){
		printf("%d\n", list[i]);
	}

		

	for (y = 0; y < MAX-1; y++){
		for (i = 0; i < MAX-1; i++){
			
			if (list[i] > list[i+1]){
				temp = list[i];
				list[i] = list[i+1];
				list[i+1] = temp;
		
			}
		}
	}

	printf ("\nOrdinated list list:\n");
	printf ("--------------\n");
	for (i = 0; i < MAX; i++){
		printf("%d\n", list[i]);
	}
	
	return 0;

}
