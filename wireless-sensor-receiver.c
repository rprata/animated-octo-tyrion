#include <stdio.h>
#include <avr/interrupt.h>

#define OWNER

#include "global.h"
#include "interruptions.h"
#include "hserial.h"
#include "handlers.h"
#include "adc.h"

#define BLINK_DELAY_MS 300

uint8_t u8Value;

int main (void)
{
	/* set pin 5 of PORTB for output*/
	DDRB |= _BV(DDB5); //D13
	
	setupADC();
	hs_init();	
	hs_start(SERIAL_PORT, BAUD);

	while (1) 
	{
		if (hs_available(SERIAL_PORT))
		{
			u8Value = hs_getChar(SERIAL_PORT);
			if (u8Value == 'h')
			{
				/* set pin 5 high to turn led on */
				PORTB |= _BV(PORTB5);
				_delay_ms(BLINK_DELAY_MS);

				/* set pin 5 low to turn led off */
				PORTB &= ~_BV(PORTB5);
				_delay_ms(BLINK_DELAY_MS);
			}
		}
	}

	return 0;
}