#include <stdio.h>
#define MAX 3
main()
{
	int i, j;
	int n[MAX];
	int x,y,z;
	
	
	
	printf("Insert down below:\n\n");
	
	for (i = 0, j = 1; i < MAX; ++i, ++j){
		printf("%d Value = ", j);
		gets(n[i]);
	//	scanf("%d", &n[i]);
	}
	
	printf("\n\nWith datas stored in an array\n");
  	printf("-----------------------------\n\n");
	
	for (i = 0; i < MAX; ++i){
		printf("Variable value: %d \tMemory address: %p\n\n", n[i], &n[i]);
	}
	
	printf("\nWith datas stored in variables\n");
	printf("------------------------------\n\n");
	
	x = n[0]; 
	y = n[1]; 
	z = n[2];
	
	printf("Variable value: %d \tMemory address: %p\n\n", x, &x);
	printf("Variable value: %d \tMemory address: %p\n\n", y, &y);
	printf("Variable value: %d \tMemory address: %p\n\n", z, &z);
	
}
