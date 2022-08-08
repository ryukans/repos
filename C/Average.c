#include <stdio.h>
#include <ctype.h>
#define MAX 150 //Array lenght.
#define TRUE 1

float average(float numbers[], int total); //Function prototype.

main()
{
	int index, j;
	/*'index' is needed to the for cycle.
	'j' is a counter, it is needed to display an ordered list.*/
	int n = 0;
	//'n' is needed to count how many you will insert into the array.
	float nums[MAX];
	//This array will contain all the ages from input.

//___________________________________________________________________________________
	while(TRUE){
		printf("Enter number of elements:\n");
		scanf("%d", &n);
		//It asks how many numbers you want to insert.

		if (isalpha(n)){
			printf("-------------------------\n"); //This is just for aesthetics.
			printf("Error ! Enter numbers value only\n");
		}

		else if (n == 0){
			printf("-------------------------\n"); //This is just for aesthetics.
			printf("End of program !");
			return 0;//End of program.
		}//If you digit zero there is no need to proceed, so the program terminates here.

		else{
			break;
		}

	}

//___________________________________________________________________________________
	printf("-------------------------"); //This is just for aesthetics.
	printf("\nInsert numbers:\n");

	for (index = 0, j = 1; index < n; ++index, ++j){
		printf("%d one: ", j);
		scanf("%f", &nums[index]);
	}//This cycle obtains the numbers by input.

//___________________________________________________________________________________
	printf("-------------------------"); //This is just for aesthetics.
	printf("\nAverage: %.2f", average(nums, n));
	/*The program prints the resoult out
	but first it calls the function to obtain
	the average by passing to it the
	parameters 'ages' and 'n'.*/

//___________________________________________________________________________________
	return 0;
	//End of program.
}


float average(float numbers[], int total)
{	/*The first parameter is an array
	that contains all the numbers.
	The second parameter is total of
	number obtained by input.*/

	int index;
	/*'index' is needed for the -for loop- cycle.
	'average' will contain the results that will be returned*/
	float avr;
	//'avr' stands for 'average'

//___________________________________________________________________________________
	for (index = 0; index <= total; ++index){
		if (index == total){
 			avr /= (float)total;
 			break;
 		}
 		else{
 			avr += (float)numbers[index];
 		}
 	}
 	/*This cycle calculates the average. When 'index' is equal
 	to 'total', 'average' will be divided by 'total' and will
 	contain the result. That is the mathematic formula
 	to calculate the average.*/

//___________________________________________________________________________________
	return avr;
	/*The program returns the results.
	End of funcion*/
}
