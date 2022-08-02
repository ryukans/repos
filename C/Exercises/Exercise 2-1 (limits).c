/* Program to print maximum,minimum limits of char,int,long using calculation */

/* The logic used is
* ~0 will give bits in 1s.
* (unsigned <type>) will cast it unsigned.
* >> 1 right shifts 1 bit to remove the sign bit.
* (<type>) casting it the required type again
*/

///Source: http://www.learntosolveit.com/cprogramming/Ex_2.1_cal_limits.html

#include<stdio.h>
#include <limits.h>
#include <float.h>

void clear(void);
void pause(
    char * __msg
);

int main(void)
{
    /*printf("Minimum Signed Char %d\n",-(char)((unsigned char) ~0 >> 1) - 1);
    printf("Maximum Signed Char %d\n",(char) ((unsigned char) ~0 >> 1));

    printf("Minimum Signed Short %d\n",-(short)((unsigned short)~0 >>1) -1);
    printf("Maximum Signed Short %d\n",(short)((unsigned short)~0 >> 1));

    printf("Minimum Signed Int %d\n",-(int)((unsigned int)~0 >> 1) -1);
    printf("Maximum Signed Int %d\n",(int)((unsigned int)~0 >> 1));

    printf("Minimum Signed Long %ld\n",-(long)((unsigned long)~0 >>1) -1);
    printf("Maximum signed Long %ld\n",(long)((unsigned long)~0 >> 1));



    printf("Maximum Unsigned Char %d\n",(unsigned char)~0);
    printf("Maximum Unsigned Short %d\n",(unsigned short)~0);
    printf("Maximum Unsigned Int %u\n",(unsigned int)~0);
    printf("Maximum Unsigned Long %lu\n",(unsigned long)~0); */

    printf("Minimum unsigned value is always 0.\n");

    pause("Press any key to continue\n");
    clear();

    printf("Char values:\n\n");
    printf("Char size:\t%d bits (1 byte)\n", CHAR_BIT);
    printf("Min:\t\t%d\n", CHAR_MIN);
    printf("Max:\t\t%d\n", CHAR_MAX);
    printf("\nSigned/unsigned values:\n\n");
    printf("Signed min:\t%d\n", SCHAR_MIN);
    printf("Signed max:\t%d\n", SCHAR_MAX);
    printf("Unsigned max:\t%u\n", UCHAR_MAX);

    printf("\n\nNOTE:\nPlain chars are signed or unsigned is machine-dependent, but printable\ncharacters are always positive.\n");

    pause(NULL);
    putchar('\n');

    printf("int values:\n\n");
    printf("int min:\t%d\n", INT_MIN);
    printf("int max:\t%d\n", INT_MAX);
    printf("short min:\t%d\n", SHRT_MIN);
    printf("short max:\t%d\n", SHRT_MAX);
    printf("long min:\t%ld\n", LONG_MIN);
    printf("long max:\t%ld\n", LONG_MAX);
    printf("long long min:\t%lld\n", LONG_LONG_MIN);
    printf("long long max:\t%lld\n", LONG_LONG_MAX);
    printf("\nUnsigned values:\n\n");
    printf("unsigned int max:\t%u\n", UINT_MAX);
    printf("unsigned short max:\t%u\n", USHRT_MAX);
    printf("unsigned long max:\t%lu\n", ULONG_MAX);
    printf("unsigned long long max\t%llu\n", ULONG_LONG_MAX);

    pause(NULL);
    putchar('\n');

    printf("float and double values:\n\n");
    printf("flot min:\t%f\n", FLT_MIN);
    printf("float max:\t%f\n", FLT_MAX);
    printf("double min:\t%lf\n", DBL_MIN);
    printf("double max:\t%lf\n", DBL_MAX);
    printf("long double min:\t%Le\n", LDBL_MIN);
    printf("long double max:\t%Lf\n", LDBL_MAX);

    pause(NULL);
    clear();

    return 0;
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


void pause(char * __msg)
{
    if(__msg != NULL){
        printf("%s", __msg);
        getch();
    }
    else{
        getch();
        putchar('\n');
    }
}
