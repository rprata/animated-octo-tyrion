#include <avr/io.h>
#include <util/delay.h>

#define BLINK_DELAY_MS 1000

#define TRUE 1
#define FALSE 0 

int main (void)
{
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5); //D13

	while (TRUE) 
	{
		/* set pin 5 high to turn led on */
		PORTB |= _BV(PORTB5);
		_delay_ms(BLINK_DELAY_MS);

		/* set pin 5 low to turn led off */
		PORTB &= ~_BV(PORTB5);
		_delay_ms(BLINK_DELAY_MS);
	}

	return 0;
}