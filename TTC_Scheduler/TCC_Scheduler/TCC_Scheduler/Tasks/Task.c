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



	/*Task Number one */
void led1_task(){
 
	DIO_WritePin(pin12,High);
	DIO_WritePin(pin13,High);
	DIO_WritePin(pin14,High);
	
}
/*Task Number TWo */

void led2_task(){

	DIO_WritePin(pin12,LOW);
	DIO_WritePin(pin13,LOW);
	DIO_WritePin(pin14,LOW);
	
 
}




