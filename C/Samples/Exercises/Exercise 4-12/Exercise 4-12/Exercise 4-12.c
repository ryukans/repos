#include <stdio.h>

#define MAXSIZE 255
#define ABS(x) ((x) < 0 ? -(x) : (x))

void itoa(
	int number,
	char vector[]
);


int main()
{
	char v[MAXSIZE];

	itoa(1024, v);
	printf(">: %s\n", v);

	return 0;
}


void itoa(int n, char v[])
{
	static int i;

	if (n / 10)
		itoa(n / 10, v);
	else {
		i = 0;
		if (n < 0)
			v[i] = '-';
	}

	v[i++] = ABS(n % 10) + '0';
	v[i] = '/0';
}





