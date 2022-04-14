#include <stdio.h>

main()
{
	//char array[5] = "Hello";
	int c;
	
	int *A400;

	int i = 0; 


	printf ("%p\n", &A400);
	
	c = *A400;
	
	c += 1;
	
	printf ("%p", &A400);

/*	
	for (i = 0; i < 5; i++){
		scanf ("%d", &c);
		A400 += 1;
		A400 =  c; 
	}
		
		
		
		printf ("%d", A400);
	
*/
	
	
	
	
	/*
	for (i = 0, j = 0; i < 5; ++i, ++j){
		pvar + j = array[i];
	}
	
	i = 0; j = 0;
	
	for (i = 0, j = 0; i < 5; ++i, ++j){
		printf("Current address: \n\n%p \n\nCorrent value: \n\n%d", &pvar, pvar)
	}
	*/
	
	
	
}
