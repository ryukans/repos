#include <stdio.h>

unsigned wordlength(void);

int main()
{
	printf("%u\n", wordlength());

	return 0;
}

/* wordlength: returns the size of the WORD on your computer */
unsigned wordlength()
{
	unsigned word, len;

	word = ~0U;
	len = 0;
	while(word){
		word >>= 1;
		++len;
	}

	return len;
}
