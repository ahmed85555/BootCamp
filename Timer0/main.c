/*
 * GPIO.c
 *
 * Created: 2/13/2019 10:41:21 AM
 * Author : AVE-LAP-005
 */ 


#include "Types.h"
#include "BitwiseOperations.h"
#include "DIO_Interface.h"
#include "Timer_Interface.h"

int main(void)
{
	uint8 laststate=0x00;
	Timer_Init();
	DIO_SetPinDirection(pin10,INPUT_WITHOUT_PULL);
	DIO_SetPinDirection(pin13,OUTPUT);
	int y=DIO_ReadPin(pin13);
	while(1)
	{
	if (DIO_ReadPin(pin10))
	{
	while (DIO_ReadPin(pin10))
	{
		DIO_WritePin(13,High);
	}
		DIO_WritePin(13,High);
		Timer_delay(1000);
	}
	DIO_WritePin(pin13,LOW);
	}
    
   
}

