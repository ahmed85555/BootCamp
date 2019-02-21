/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:21 AM
 * Author : AVE-LAP-005
 */ 

#include <avr/interrupt.h>
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"

uint8 flag1=0,flag2=0,flag3=0;
void Blink_leds();
void External_test();
int main(void)
{
	/*SET LEDS direction as output*/
	DIO_SetPinDirection(pin13,OUTPUT);
	DIO_SetPinDirection(pin14,OUTPUT);
	DIO_SetPinDirection(pin15,OUTPUT);
	/* Initilaize timer0 */
	Timer_Init();
	/*Initialize External Interrupt */
	External_Interrupt_Init();
	while (1)
	{
		Timer_delay(1000);	
	Set_CallBack(Blink_leds);
	Set_External_CallBack(External_test);
	}

   
}
void Blink_leds(){
	
	if (flag1==1)
	{
		DIO_WritePin(pin13,High);
		flag1=0;
		flag2=1;
	}
	if (flag2==1)
	{
		DIO_WritePin(pin13,LOW);
		DIO_WritePin(pin14,High);
		flag2=0;
		flag3=0;
	}
	if (flag3==1)
	{
		DIO_WritePin(pin13,LOW);
		DIO_WritePin(pin14,High);
		flag3=0;
		flag1=1;
	}
	
}
void External_test(){

	
	flag1=0;
	flag2=0;
	flag3=0;
	DIO_WritePin(pin13,High);
	
}
