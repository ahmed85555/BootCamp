/*
 * Timer_Register.h
 *
 * Created: 2/14/2019 9:37:15 AM
 *  Author: AVE-LAP-005
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_
typedef struct{
	uint8 TCNT0;
	uint8 TCCR0;
	}Timer0;
	
#define TIMER0  ((volatile Timer0*)0x52)
#define TIMSK   *((volatile uint8*)0x59)
#define TIFR   *((volatile uint8*)0x58)
#define OCR0  (*(volatile ptr8)(0x5c))


#endif /* TIMER_REGISTER_H_ */