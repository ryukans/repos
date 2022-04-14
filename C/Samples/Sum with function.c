

int sum (int num1, int num2, int *num3);

main()
{
	int num1 = 5;
	int num2 = 4;
	int *num3 = 0;
	sum(num1,num2,num3);
	printf("%d", num3);
	return 0;
}


int sum(int num1, int num2, int *num3)
{
	*num3 = num1 + num3;
	return *num3;
	
}

