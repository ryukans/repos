/*
	Author: Claudio Pisa
	Name: binary converter v2.0Beta
	Copyright: None
	Date: 08/03/2017 17:24
	Description: N/A
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum boolean { FALSE, TRUE };

void clear(void);
void pause(void);

long long int btoi(
	long long int bin
);

long long int itob(
	long long int dec
);


int main()
{

	long long int binary, decimal;

	//printf("Decimal value from -9223372036854775808 to 9223372036854775807 (2^63-1)\n\n");

	pause();
	clear();

	printf("Type binary: ");
	scanf("%lld", &binary);
	printf("In decimal>: %lld\n", decimal = btoi(binary));

	pause();
	clear();

	printf("Type decimal>: ");
	scanf("%lld", &decimal);
	printf("In binary>: %lld", binary = itob(decimal));

	pause();
	clear();

	return EXIT_SUCCESS;
}


long long int btoi(long long int bin)
{
	long long int dec; /* Stores the decimal value */
	int rem; /* Stores the reminder */
	int exp; /* Stores the value of the exponent */

	dec = rem = exp = 0;
	while(bin != 0){
		rem = bin%10;

		/*
		 * Execute only if the reminder equals to 1, otherwise it would be useless
		 * to do so if the value is 0 because the result of the expression will be 0.
		 */
		if(rem == 1){ dec+=pow(2, exp); }

		bin/=10;
		++exp;
	}

	return dec;
}


long long int itob(long long int dec)
{
	long long int bin; /* Stores the binary value */
	long long int exp;
	long long int rem; /* Stores the reminder */
	int bits;
	int negative_flag = FALSE;

	if(dec < 0){
		dec = abs(dec);
		negative_flag = TRUE;
	}
	else if(dec == 0){
		bin = 0;
		return bin;
	}


	bits = bin = rem = 0;
	exp = 1;
	while(dec != 0)
    {
        rem = dec%2;

        /*
		 * Execute only if the reminder equals to 1, otherwise it would be useless
		 * to do so if the value is 0 because the result of the expression will be 0.
		 */
        if(rem == 1){ bin+=exp; }

        dec/=2;
        exp *= 10;
        ++bits;
    }


    if(negative_flag == TRUE)
        bin+=pow(10, bits);

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

