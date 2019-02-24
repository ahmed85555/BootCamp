/*
 * Scheduler.h
 *
 * Created: 2/23/2019 4:30:55 PM
 *  Author: AVE-LAP-005
 */ 


#ifndef SCHEDULER_H_
#define SCHEDULER_H_
#define NO_OF_TASKS 3
#define MAX_SIZE 4
/* structure of every task*/
typedef struct{
	void (*task)(void);
	uint32 Periodicity;
	uint32 Priority;
	uint32 Delay;
	}TCB;

/* Scheduler APIS */
void Scheduler_Init();
void Scheduler_Start();
void TTC_Scheduler();
uint8 Scheduler_Add_Task(TCB* Task);
/* Array of Structures*/
TCB System_Tasks[MAX_SIZE];


#endif /* SCHEDULER_H_ */