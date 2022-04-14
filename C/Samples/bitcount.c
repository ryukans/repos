#include <stdio.h>

int bitcount(
    unsigned stream
);

int streamlenght(
    unsigned stream
);


int main()
{
	unsigned x;

	printf("Number: ");
	scanf("%u", &x);
	printf("Bits: %d\n", bitcount(x));
	printf("Bitstream's length: %d\n", streamlength(x));

	putchar('\n');

	system("pause");

	return 0;
}


/* bitcount: count 1 bits int x */
int bitcount(unsigned x)
{
	int b;

	for(b = 0; x != 0; x >>= 1)
		if(x & 01)
			b++;
	return b;
}


/* streamlength: returns the bitstream's length */
int streamlength(unsigned x)
{
    int size;

    size = 0;
    while(x){
        x >>= 1;
        ++size;
    }
    return size;
}

