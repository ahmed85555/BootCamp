/*
 * Task.c
 *
 * Created: 2/23/2019 6:14:09 PM
 *  Author: AVE-LAP-005
 */ 
#include "Types.h"
#include "BitwiseOperations.h"
#include "Task.h"
#include "DIO_Interface.h"
#include "Utilites.h"


	/*Task Number one */
void led1_task(){
   /*Write one to the write high to the three leds*/
	DIO_WritePin(pin12,High);

	
}
/*Task Number TWo */

void led2_task(){
/*Write one to the write high to the three leds*/
	DIO_WritePin(pin13,High);

 
}

void led3_task(){
/*Write one to the write high to the three leds*/
	DIO_WritePin(pin14,High);
}
void led4_task(){
/*Write zero to the write high to the three leds*/
	 
	if(DIO_ReadPin(pin15)==LOW)
	{
		DIO_WritePin(pin15,High);
	}else{
		
		DIO_WritePin(pin15,LOW);
	}
 
}
/* Task to remove when click the switch*/
void Task_remove(){
	if(DIO_ReadPin(pin10)==High){
	Remove_Task(NUM_FOUR);
	}
}


