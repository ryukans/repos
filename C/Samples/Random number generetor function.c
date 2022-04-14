#include <stdio.h>

//Random number generetor function.
main()
{

	int i;
	int t;
	int long r = 7;
	int long y;

	srand(time(NULL)); //To generate random numbers every time.

	i = rand();
	y = i % r;
	
	printf("How many time do you want to generate a number ?\n>: ");
	scanf("%d", &t);

	system("cls");

	printf("Type range\n>: ");
	scanf("%d", &r);
	//r = r + 1;

	system("cls");

	printf("________________\n\n");

	for (i = 0; i < t; ++i){
		y = (rand() % r); //Random number within a range.
		printf ("> %d\n", y);
	}

	return 0;
}
