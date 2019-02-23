/*
 * Scheduler.c
 *
 * Created: 2/23/2019 4:30:29 PM
 *  Author: AVE-LAP-005
 */ 

#include "BitwiseOperations.h"
#include "Types.h"
#include "Timer.h"
#include "Task.h"
#include "DIO_Interface.h"
#include "Scheduler.h"
#include "Utilites.h"

volatile uint8 flag=0;
extern void (*Tasks[NO_OF_TASKS])(void);

/* declare static set_flag function */
static void set_flag();

/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Initilaize timer and initilaize set_callback
* to call set_flag in the isr every tick time and check on the flag to call scheduler

****************************************************************************/
void Scheduler_Init_And_Start(){
	
	Timer_Init();
	Set_CallBack(set_flag);
	while (1)
	{
		if (flag==NUM_ONE)
		{
			flag=NUM_ZERO;
			TTC_Scheduler();
		}
	}
	
	
}

/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Called every tick to execute the tasks sequentially 

****************************************************************************/
void TTC_Scheduler(){
	
	uint32 i=NUM_ZERO;
	for (i=NUM_ZERO;i<NO_OF_TASKS;i++)
	{
		Tasks[i]();
	}
	
	
	
}
/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Sets flag with one with every tick 

****************************************************************************/
static void set_flag(){
	flag=NUM_ONE;
	
}