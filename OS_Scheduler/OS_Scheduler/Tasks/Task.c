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


/* array of tasks to check every task */
void (*Tasks[NO_OF_TASKS])(void)={led1_task,led2_task,led3_task};
	/*Task Number one */
void led1_task(){
	
	DIO_WritePin(12,High);
}
/*Task Number TWo */

void led2_task(){
	DIO_WritePin(13,High);
	
}

/*Task Number Three */
void led3_task(){
	DIO_WritePin(14,High);
	
}


