#include <stdio.h>

int Print(int out1,int out2); //Prototype MUST BE RESPECTED 

main(){
	int input1;
	int input2;
	
	printf ("Write here first one: ");
	scanf ("%d", &input1);
	printf ("Write here second one: ");
	scanf ("%d", &input2);
	Print (input1,input2);
	return 0;
}

int Print(int out1,int out2){

	printf("%d\n",out1);
	printf("%d",out2);
}


