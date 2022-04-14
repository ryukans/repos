/*
	Name: Matrix_virus v1.1
	Copyright: None
	Author: Claudio Pisa
	Date: 25/08/16 15:18
	Description: N/A
*/


main(){
	
	int a,b,i,j,x,y;
	
	//Cycle condition
	a=0;
	b=2500; //Time on display 
	i=0;
	j=1;
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

    while (i < j){
	    ++x;
		y*=y;
		++y;
		printf("%d",y);
		printf("You'll die !");//Sectet text ;) 
    }
	
}
