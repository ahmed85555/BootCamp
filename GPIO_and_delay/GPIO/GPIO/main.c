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

int main(void)
{
	int x=0x33;
	Clear_Bit(x,1);
	DIO_SetPinDirection(pin0,Input_PUll_UP);
	DIO_WritePin(pin9,High);
	
    /* Replace with your application code */
   
}

