/*
	Name: Random password generator
	Copyright: None
	Author: N/A
	Web source: https://en.wikipedia.org/wiki/Random_password_generator
	Date: 20/09/16 00:26
	Description: In this case, the standard C function rand, which is a pseudo-random number generator, is initially seeded using the C functions time, but later iterations use rand instead. 
	According to the ANSI C standard, time returns a value of type time_t, which is implementation defined, but most commonly a 32-bit integer containing the current number of seconds since January 1. 
	There are about 31 million seconds in a year, so an attacker who knows the year (a simple matter in situations where frequent password changes are mandated by password policy) 
	and the process ID that the password was generated with, faces a relatively small number, by cryptographic standards, of choices to test. 
	If the attacker knows more accurately when the password was generated, he faces an even smaller number of candidates to test – a serious flaw in this implementation.
	In situations where the attacker can obtain an encrypted version of the password, such testing can be performed rapidly enough so that a few million trial passwords can be checked in a matter of seconds.
	The function rand presents another problem. All pseudo-random number generators have an internal memory or state. 
	The size of that state determines the maximum number of different values it can produce: an n-bit state can produce at most 2^n different values.
	On many systems rand has a 31 or 32 bit state, which is already a significant security limitation. Microsoft documentation does not describe the internal state of the Visual C++ implementation 
	of the C standard library rand, but it has only 32767 possible outputs (15 bits) per call. Microsoft recommends a different, more secure function, rand_s, be used instead. 
	The output of rand_s is cryptographically secure, according to Microsoft, and it does not use the seed loaded by the srand function. 
	However its programming interface differs from rand.
*/


#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int
main(void)
{
    /* Length of the password */
    unsigned short int length = 8;
    /* Seed number for rand() */
    srand((unsigned int) time(0));


    /* ASCII characters 33 to 126 */
    while(length--) {
    	putchar(rand() % 94 + 33);
    }
    printf("\n");

    return EXIT_SUCCESS;
}
