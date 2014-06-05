#include <stdio.h>
#include <avr/interrupt.h>

#define OWNER

#include "global.h"
#include "interruptions.h"
#include "hserial.h"
#include "handlers.h"
#include "adc.h"

uint8_t u8Value;

int main (void)
{

	setupADC();
	hs_init();	
	hs_start(SERIAL_PORT, BAUD);

	while (1) 
	{
		u8Value = adc_read(ADC_IN);
		hs_writeChar(SERIAL_PORT, 'h');
		hs_writeChar(SERIAL_PORT, '\n');
		_delay_ms(1000);
	}

	return 0;
}