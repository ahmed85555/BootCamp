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
#include "Utilites.h"

int main(void)
{
	
   	/* initialize pins 12 and 13 and 14 on portB.4 and portB.5 and portB.6 to be output */
   	DIO_SetPinDirection(pin12,OUTPUT);
   	DIO_SetPinDirection(pin13,OUTPUT);
   	DIO_SetPinDirection(pin14,OUTPUT);
	DIO_SetPinDirection(pin15,OUTPUT); 
	DIO_SetPinDirection(pin10,INPUT_WITHOUT_PULL);     
	/*Initilaize Scheduler*/
    Scheduler_Init();
	/*Task one attributes */
	TCB Task1={led1_task,t_1000ms,NUM_ONE,t_1000ms,NUM_ONE};
	/*Create Task one*/
	Scheduler_Add_Task(&Task1);
	/*Task Two attributes */
	TCB Task2={led2_task,t_2000ms,NUM_ZERO,t_2000ms,NUM_TWO};
	Scheduler_Add_Task(&Task2);
	/*Task one attributes */
	TCB Task3={led3_task,t_3000ms,NUM_THREE,t_3000ms,NUM_THREE};
	/*Create Task one*/
	Scheduler_Add_Task(&Task3);
	/*Task Two attributes */
	TCB Task4={led4_task,t_4000ms,NUM_FOUR,t_4000ms,NUM_FOUR};	
	/*Create Task Two*/
	Scheduler_Add_Task(&Task4);
	/*led four will toggle every 5 minutes when click on button1 the task4 will blocked on it's last state */
	TCB Task5={Task_remove,t_5000ms,NUM_SIX,t_5000ms,NUM_SEVEN};
	Scheduler_Add_Task(&Task5);	
	/*Start Scheduler*/
	Scheduler_Start();
	

}

