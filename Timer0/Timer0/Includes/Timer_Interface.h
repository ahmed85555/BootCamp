/*
 * Timer_Interface.h
 *
 * Created: 2/14/2019 9:37:33 AM
 *  Author: AVE-LAP-005
 */ 


#ifndef TIMER_INTERFACE_H_
#define TIMER_INTERFACE_H_
#define Bit0 0
#define Bit1 1
#define Bit2 2
#define Bit3 3
#define Bit4 4
#define Bit5 5
#define Bit6 6
#define Bit7 7
void Timer_Init();
void Timer_delay(uint32 n);
void Enable_Global_Interrupt();
void Set_CallBack(void (*ptr)(void));
void External_Interrupt_Init();
void Set_External_CallBack(void (*ptr)(void));


#endif /* TIMER_INTERFACE_H_ */