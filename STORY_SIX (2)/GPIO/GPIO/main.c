/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:21 AM
 * Author : AVE-LAP-005
 */ 

#include <avr/io.h>
#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO_Interface.h"
#include "delay.h"

int main(void)
{
	
	DIO_SetPinDirection(pin13,OUTPUT);
	DIO_SetPinDirection(pin14,OUTPUT);
	DIO_SetPinDirection(pin15,OUTPUT);
	while(1)
	{
	DIO_WritePin(pin13,High);
	delay_ms(2000);
	DIO_WritePin(pin13,LOW);
	delay_ms(2000);
	DIO_WritePin(pin15,High);
	delay_ms(2000);
	DIO_WritePin(pin15,LOW);
	delay_ms(2000);
	DIO_WritePin(pin14,High);
	delay_ms(2000);
	DIO_WritePin(pin14,LOW);
	delay_ms(2000);
	
	
   
}
}

