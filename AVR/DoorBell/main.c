/*
 * DoorBell.c
 *
 * Created: 27.12.2019 19:10:32
 * Author : Bishop_Workshop
 */ 
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
	//System init
	
	//Set configuration PIN in input PORT
	DDRB=0;
	PORTB= 1<<PIN4; //PIn4 In high
	
	DDRD |=(1<<PD5);//Set PWM pin to out
	
	//Init Timer and PWM out
	//50Hz, 1500us pulse;
	
	
	TCCR1A =0;
	TCCR1B=0;
		
	
	TCCR1A|=(1<<COM1A1)|(1<<WGM11);//Non ivert PWM Output On	
	TCCR1B|=(1<<WGM12)|(1<<WGM13)|(1<<CS12);//Fast PWM-Mode
	OCR1A=47;// set  1500us
	ICR1 = 624;//set 50Hz 
	
	
    
    while (1) 
    {
		if(PINB&=(1<<4))
		{
			_delay_ms(150);
			OCR1A = 37;
			_delay_ms(150);
			OCR1A = 57;
			
		}
		else 
		 OCR1A =47;
		 asm volatile("nop");
		
    }
}
