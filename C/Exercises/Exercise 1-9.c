#include <stdio.h>


#define ZERO 0 /*Makes the counter equals to zero*/

//Exercise 1-9 p.20

main(){

	int c;
	int blanks;



        while ((c = getchar())!= EOF){

	    	if (c == ' '){       			//If the inserted character is a blank
	    		++blanks;        			//the counter (blanks) will be increased by one.
	    	                 				//______________________________________________
				if (blanks > 1)  			//If the blanks counter is greater than one (it means that there are more than one blank)
	    			;           			//do nothing, so it doest print the blank (null statement).
	    	                 				//_________________________________________________________
				else             			//Else
	    			putchar (c); 			//print it out.

			}

			else{                			//But, if the inserted character is not a blank
	    		putchar (c);     			//print it out
	    		blanks = ZERO;   			//and the counter must be equal to zero.
	    	}
		}
}


