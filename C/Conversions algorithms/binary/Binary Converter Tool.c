/*
	Author: Claudio Pisa
	Name: Binary Converter Tool v1.6b
	Copyright: None
	Date: 08/03/2017 17:24
	Description: N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAXSIZE 1024

enum boolan { FALSE, TRUE };

void clear(void);
void pause(void);
void set_to_zero(
	int bin[]
);
void print_bin(
	int bin[],
	int bits
);
void print_extended_bin( /* Debug tests only */
	int bin[],
	int bits
);
int get_bin(
	int bin[]
);
int bin_to_dec(
	int bin[],
	int dec
);
int dec_to_bin(
	int bin[],
	int dec
);


int main()
{
	int binary[MAXSIZE], decimal, bits;

	set_to_zero(binary);
	printf("Decimal value from -9223372036854775808 to 9223372036854775807 (2^63-1)\n\n");
	printf("Type binary>: ");
	printf("In decimal>: %d\n", decimal = bin_to_dec(binary, bits = get_bin(binary)) );

	pause();
	clear();

	set_to_zero(binary);

	printf("Type decimal>: ");
	scanf("%d", &decimal);
	printf("In binary>: ");
	print_bin(binary, bits = dec_to_bin(binary, decimal));

	pause();
	clear();

	return EXIT_SUCCESS;
}


int get_bin(int bin[])
{
	int i, bits;
	char ch;

	i = bits = 0;
	while(i < MAXSIZE && (ch = getchar()) != '\n'){
		bin[i++] = ch-48;
		++bits;
	}

	return bits;
}


void print_bin(int bin[], int bits)
{
	int i = MAXSIZE-bits;
	while(i < MAXSIZE)
		printf("%d", bin[i++]);

    putchar('\n');
}


void print_extended_bin(int bin[], int bits) /* Debug tests only */
{
	int i = 0;
	while(i < MAXSIZE)
		printf("%d", bin[i++]);
}


void set_to_zero(int bin[])
{
	int i = 0;
	while(i < MAXSIZE)
		bin[i++] = NULL;
}


int bin_to_dec(int bin[], int bits)
{
	int i, exp, dec;

	i = dec = 0;
	exp = bits-1;
	while(i < bits){
		/* Execute only if the value is 1, Because It would be useless
		 * to do so if the value would be 0 because the result of the expression will be 0. */
		if(bin[i++] == 1)
			dec += pow(2, exp);
		/* Exponent value always must be decremented wether the value is 1 or 0. */
		--exp;
	}

	return dec;
}


int dec_to_bin(int bin[], int dec)
{
	int i, bits, temp, negative_flag;

    i = MAXSIZE-1;
	bits = 0;
	negative_flag = FALSE;

	if(dec < 0){
		negative_flag = TRUE;
		dec = abs(dec); // Convert to positive integer
	}
	else if(!dec)
		return ++bits;


	while(dec >= 1){
		bin[i--] = dec % 2;
		++bits;
		
		dec/=2;
	}


	if(negative_flag == TRUE){
		bin[(MAXSIZE-1)-bits] = 1; ///Allocate flag bit.
        ++bits;
	}

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

