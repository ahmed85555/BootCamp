/*
 * Timer_Register.h
 *
 * Created: 2/14/2019 9:37:15 AM
 *  Author: AVE-LAP-005
 */ 


#ifndef TIMER_REGISTER_H_
#define TIMER_REGISTER_H_

	
#define TCCR0  (*(volatile Timer0*)(0x52))
#define TIMSK   *((volatile uint8*)0x59)
#define TIFR   *((volatile uint8*)0x58)
#define OCR0  (*(volatile ptr8)(0x5c))

/*Registers for external interrupt*/

#define MCUSCR  (*(volatile ptr8)(0x54))
#define MCUCR  (*(volatile ptr8)(0x54))
#define GIFR  (*(volatile ptr8)(0x5A))
#define GICR  (*(volatile ptr8)(0x5B))



#endif /* TIMER_REGISTER_H_ */