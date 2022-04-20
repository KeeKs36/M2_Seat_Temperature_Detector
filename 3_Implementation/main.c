/*
 * seat_temp_mon.c
 *
 * Created: 20-04-2022 12:04:01
 * Author : Keerthi
 */ 

#include <avr/io.h>
#include<util/delay.h>
#include "Activity1.h"
#include "Activity2.h"
#include "Activity3.h"
int main(void)
{
	SEAT_CH(); //Initializing Drivers seat
	ADC_INITIAL(); //Initializing ADC to accept temperature values
	TIMER_INITIAL(); //Initializing Timer by dividing clock with 64 prescale
	LCD_INITIAL(); //Initializing LCD

	uint16_t read;

	while(1)
	{
		if(SEAT_CHECK)
		{
			PORTD|=(1<<PD2);
			if(HEATER_ON){
				LED_ON;
				_delay_ms(200);
				CLEAR_LCD();
				read=SENSE_ADC(0);
				PWM_OUPUT(read);

			}
			else
			{
				LED_OFF;
				_delay_ms(200);
				HEATER_OFF;
				_delay_ms(200);
				CLEAR_LCD();
			}
		}
		else{
			LED_OFF;
			_delay_ms(200);
			HEATER_OFF;
			_delay_ms(200);
			CLEAR_LCD();
		}
	}
	return 0;
}

