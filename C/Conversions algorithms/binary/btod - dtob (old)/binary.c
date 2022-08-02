/*
	Author: Claudio Pisa
	Name: Binary conversion v1.5b
	Copyright: None
	Date: 08/03/2017 17:24
	Description: N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 1024

void clear(void);
void pause(void);
void set_to_zero(
	int bin[]
);
void print_bin(
	int bin[],
	unsigned long long bits
);
void print_extended_bin( /*Call this function in debug tests only*/
	int bin[],
	unsigned long long bits
);
unsigned long long get_bin(
	int bin[]
);
signed long long bin_to_dec(
	int bin[],
	unsigned long long bits
);
unsigned long long dec_to_bin(
	int bin[],
	signed long long dec
);


int main()
{
	int binary[MAXSIZE];
    signed long long dec;
    unsigned long long bits;

	set_to_zero(binary);

	printf("Type binary>: ");
	printf("In decimal>: %d\n", dec = bin_to_dec(binary, bits = get_bin(binary)) );

	pause();
	clear();

	set_to_zero(binary);

	printf("Type decimal>: ");
	scanf("%lld", &dec);
	printf("In binary>: ");
	print_bin(binary, bits = dec_to_bin(binary, dec));

	pause();
	clear();

	return EXIT_SUCCESS;
}


unsigned long long get_bin(int bin[])
{
	int i;
	unsigned long long bits;
	char ch;

	i = bits = 0;
	while(i < MAXSIZE && (ch = getchar()) != '\n'){
		bin[i++] = ch-48;
		++bits;
	}

	return bits;
}


void print_bin(int bin[], unsigned long long bits)
{
	int i = MAXSIZE-bits;
	while(i < MAXSIZE)
		printf("%d", bin[i++]);

    putchar('\n');
}


void print_extended_bin(int bin[], unsigned long long bits) /* Debug tests only */
{
	int i = 0;
	while(i < MAXSIZE)
		printf("%d", bin[i++]);
}


void set_to_zero(int bin[])
{
	int i = 0;
	while(i < MAXSIZE)
		bin[i++] = 0;
}


signed long long bin_to_dec(int bin[], unsigned long long bits)
{
	int i, exp;
	signed long long dec;

	i = dec = 0;
	exp = bits-1;
	while(i < bits){
		if(bin[i++] == 1)
			dec += pow(2, exp);
		--exp;
	}

	return dec;
}


unsigned long long dec_to_bin(int bin[], signed long long dec)
{
	int i, temp;
	unsigned long long bits;

    i = MAXSIZE-1;
	bits = 0;
	if(dec > 0){
        while(dec >= 1){ ///(dec > 0) as well.
            if((dec%2) == 0)
                bin[i--] = 0;
            else
                bin[i--] = 1;

            ++bits;
            dec/=2;
        }
	}
    else if(dec < 0){
        while(dec <= -1){ ///(dec < 0) as well.
            if((dec%2) == 0)
                bin[i--] = 0;
            else
                bin[i--] = 1;

            ++bits;
            dec/=2;
        }
        bin[(MAXSIZE-1)-bits] = 1; ///Allocate flag bit.
        ++bits;
    }
    else ///If equals to zero.
        return ++bits;

	return bits;
}


void clear()
{
	#if defined(__unix__) || defined(__linux__) || defined(__APPLE__)
		system("clear");
	#endif

	#if defined(_WIN32) || defined(_WIN64)
		system("cls");
	#endif
}


void pause()
{
	printf("\nPress any key to continue.\n");
	getch();
}



