
//Triangle area

int calculate(base,height);


main()
{
	int base;
	int height;
	int res;
	
	printf ("Base value: ");
	scanf ("%d", &base);
	printf ("Height value: ");
	scanf ("%d",&height);
	res = calculate(base,height);
	printf ("%d",res);
	
	return 0;
}


int calculate(x,y)
{
	int z;
	
	z = (x*y)/2;
	
	return z;
}
