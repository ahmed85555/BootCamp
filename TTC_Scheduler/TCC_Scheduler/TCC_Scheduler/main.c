/*
 * TCC_Scheduler.c
 *
 * Created: 2/24/2019 3:43:13 PM
 * Author : AVE-LAP-005
 */ 

#include <avr/io.h>
#include "Types.h"
#include "Timer.h"
#include "Scheduler.h"
#include "Task.h"
#include "DIO_Interface.h"
#include "Task.h"

int main(void)
{
	
   	/* initialize pins 12 and 13 and 14 on portB.4 and portB.5 and portB.6 to be output */
   	DIO_SetPinDirection(pin12,OUTPUT);
   	DIO_SetPinDirection(pin13,OUTPUT);
   	DIO_SetPinDirection(pin14,OUTPUT);
	/*Initilaize Scheduler*/
    Scheduler_Init();
	/*Task one attributes */
	TCB Task1;
	Task1.task=led1_task;
	Task1.Periodicity=1500;
	/*Create Task one*/
	Scheduler_Add_Task(&Task1);
	/*Task Two attributes */
	TCB Task2;
	Task2.task=led2_task;
	Task2.Periodicity=2000;
	/*Create Task Two*/
	Scheduler_Add_Task(&Task2);
	Scheduler_Start();

}

