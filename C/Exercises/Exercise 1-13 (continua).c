
#include <stdio.h>
#define LENGHT 1000 //Array lenght 
#define NULL 0 //Zero value

//Exercise 1-13 p.24
main(){ // Begins main
	int input;
	int chars = NULL;
	int index = NULL;
	int word = NULL;
	int number= NULL;
	int list[LENGHT];
	
	for (index = NULL; index < LENGHT; ++index)
    	list[index] = NULL;                   
    	
    index = NULL;
    	
    while ((input = getchar()) != EOF){ // Begins while 
		if (input != '\n' && input != '\t' && input != ' '){ // Begins 'first condition'
			++chars;
			list[index] = chars;
		} // Ends 'first condition'
		
		else{ // Begins 'second condition'
			chars = NULL;
		 	++index;
		 	++word;
		} // Ends 'second condition'
	} //Ends while by Ctrl+Z
	
	if (word == 1){
		printf ("Word lenght: %d",list[NULL]);
	}
	
	else{
		for (number= 1, index = NULL; index < word; ++index, ++number)
    	    printf ("%d) Word lenght: %d\n", number, list[index]);
    }
} // Ends main
