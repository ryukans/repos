/*
	Name: Matrix_virus v1.2
	Copyright: None
	Author: Claudio Pisa
	Date: 06/09/16 21:24
	Description: N/A
*/

#include <stdio.h>

main(){

	int a,b,x,y;
	//First cycle conditions
	a=0;
	b=2500; //Time on display
    //_______________

    //Numbers
	x=1;
	y=1;
	//________________


	while (a <= b){
		printf("Fatal error !\t");
		printf("Please wait...\n");
		++a;
	}

    for( ; ; ){
		++x;
		x *= x++;
    	printf("%d", x);
    	printf("You'll die !");
    }

}
