/*
 * Scheduler.c
 *
 * Created: 2/23/2019 4:30:29 PM
 *  Author: AVE-LAP-005
 */ 
#include <stdio.h>
#include "BitwiseOperations.h"
#include "Types.h"
#include "Timer.h"
#include "Task.h"
#include "DIO_Interface.h"
#include "Scheduler.h"
#include "Utilites.h"

volatile uint8 flag=0;
static volatile uint32 size=0;
/* declare static set_flag function */
static void set_flag();

/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Initilaize timer and initilaize set_callback
* to call set_flag in the isr every tick time and check on the flag to call scheduler

****************************************************************************/
void Scheduler_Init() 
{
	uint32 i=0;
	for (i=0;i<MAX_SIZE;i++)
	{
		System_Tasks[i].task=NULL;
		System_Tasks[i].Periodicity=0;
		System_Tasks[i].Delay=0;
		System_Tasks[i].Priority=0;
	}
	
	
}
/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Starts The Scheduler 

****************************************************************************/
void Scheduler_Start(){
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
	
	for (i=NUM_ZERO;i<size;i++)
	{
	if(NUM_ZERO==(System_Tasks[i].Delay--))
	{
		System_Tasks[i].task();
		System_Tasks[i].Delay=System_Tasks[i].Periodicity;
	}
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
/****************************************************************************
*  INPUT:Pointer To Function
*  OUTPUT:NOTHING
* Description: This function Adds task to the array of tasks

****************************************************************************/
uint8 Scheduler_Add_Task(TCB* Task){
	
	if(size<MAX_SIZE){
		System_Tasks[size].task=Task->task;
		System_Tasks[size].Periodicity=Task->Periodicity;
		System_Tasks[size].Delay=Task->Periodicity;
		System_Tasks[size].Priority=Task->Priority;
		size++;
		
	}else{
		return 0;
	}
	
}
