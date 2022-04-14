#include <avr/io.h> // needed for IO port declarations
#include <inttypes.h> // needed for type declarations
#include <stdlib.h>
#include <MSOE/delay.h>
#include <avr/interrupt.h>

extern uint8_t asmfunction(uint8_t); // Assembler function is external
uint8_t cfunction(uint8_t); // C function prototype

// Global variable accessible by assembler code and C code
uint8_t value;
	
void my_init_stack(void) __attribute__ ((naked)) __attribute__ ((section (".init2")));
	
void my_init_stack(void)
{
	SPH = 0x08;
	SPL = 0x3F;
}
	
int main(void)
{
	sei();
	DDRB = 0xff; // PB3 is output	
	DDRD = 0xff; // PD7 is output
	DDRA = 0xc0; // Motor direction bits are outputs
	PORTA = 0xc0;
	PORTB = 0;
	PORTD = 0;
	value= 0x03;
	
	while(1){
		value = asmfunction(value); // Turns motors ON
		delay_ms(1000); // Wait a second
		value = cfunction(value); // Turns motors OFF
		delay_ms(1000); // Wait a second
	}
	
	return 0; // Never gets here
	
}

uint8_t cfunction(uint8_t a)
{
	if (a == 4){
		PORTB = PORTB & ~(1<<3); // Turn motors OFF
		PORTD = PORTD & ~(1<<7);
		a = 3;
	}
	
	return a;
}

#include <MSOE/delay.c>
