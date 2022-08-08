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


int bin_to_dec(
	int bin
);

void dec_to_bin(
	int dec
);


int main()
{
	long int binary, decimal;

	printf("Decimal value from -9223372036854775808 to 9223372036854775807 (2^63-1)\n\n");

	pause();
	clear();

	printf("Type binary: ");
	scanf("%ld", &binary);
	printf("In decimal>: %ld\n", decimal = bin_to_dec(binary));

	pause();
	clear();

	printf("Type decimal>: ");
	scanf("%ld", &decimal);
	printf("In binary>: %ld", binary = dec_to_bin(decimal));
	dec_to_bin(binary, decimal);
	print_extended_bin(binary);

	pause();
	clear();

	return EXIT_SUCCESS;
}


int bin_to_dec(int bin)
{
	int dec; /* Stores the decimal value */
	int rem; /* Stores the reminder */
	int exp; /* Stores the value of the exponent */
	
	exp = 0;
	while(bin != 0){
		rem = bin%10;
		
		/*
		 * Execute only if the reminder equals to 1, otherwise it would be useless
		 * to do so if the value is 0 because the result of the expression will be 0.
		 */
		if(reminder == 1){ dec += rem*(pow(2, exp)); }

		bin/=10;
		++exp;
	}

	return dec;
}


void dec_to_bin(int dec)
{
	int bin; /* Stores the binary value */
	int rem; /* Stores the reminder */

	if(dec < 0)
		dec = abs(dec);
	else if(!dec){
		bin = 0;
		return bin;
	}


	bin = 0;
	while (n!=0)
    {
        rem = n%2;

        /*
		 * Execute only if the reminder equals to 1, otherwise it would be useless
		 * to do so if the value is 0 because the result of the expression will be 0.
		 */
        if(rem == 1){ bin += rem*i; }
        
        n/=2;
        i *= 10;
    }

    return bin;
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

