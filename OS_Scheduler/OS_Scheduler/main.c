/*
 * OS_Scheduler.c
 *
 * Created: 2/23/2019 3:40:21 PM
 * Author : AVE-LAP-005
 */ 

#include <avr/io.h>
#include "Types.h"
#include "Timer.h"
#include "Scheduler.h"
#include "DIO_Interface.h"
#include "Task.h"

int main(void)
{
	/* initialize pins to be output */
   DIO_SetPinDirection(12,OUTPUT);
   DIO_SetPinDirection(13,OUTPUT);
   DIO_SetPinDirection(14,OUTPUT);
   /* Call the scheduler */
   Scheduler_Init_And_Start();
}

