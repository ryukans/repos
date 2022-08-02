#include <stdio.h>

#define LENGHT 30

//Exercise 1-13 p.24

main(){ // Begins main
	
	int c;
	int chars = 0;
	int index = 0;
	int word = 0;
	int number= 0;
	int list[200];
	
	
	
    for (index = 0; index < LENGHT; ++index)
    	list[index] = 0;                   
    	

    index = 0;
		
    while ((c = getchar()) != EOF){ // Begins while 
    
		
		if (c != '\n' && c != '\t' && c != ' '){ // Begins 'first condition'
			++chars;
			list[index] = chars;
		} // Ends 'first condition'
		
		
		
		else{ // Begins 'second condition'
	
			chars = 0;
		 	++index;
		 	++word;
			
		} // Ends 'second condition'
		
	
		
	} //Ends while (Ctrl+Z)
	
	if (word == 1){
		
		printf ("Word lenght: %d",list[0]);
	}
	
	else{
		
		for (number= 1, index = 0; index < word; ++index, ++number)
    	printf ("-%d Word lenght: %d\n", number, list[index]);
    }
	

		    
} // Ends main
