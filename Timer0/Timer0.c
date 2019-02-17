/*
 * Timer0.c
 *
 * Created: 2/14/2019 9:38:01 AM
 *  Author: AVE-LAP-005 */
 
 #include "Types.h"
 #include "BitwiseOperations.h"
 #include "Timer_Interface.h"
 #include "Timer_Register.h"
/****************************************************************************/
/*  INPUT:NOTHING
/*  OUTPUT:NOTHING
/*  Description: This function Initilaize timer0 to be in the ctc mode

/****************************************************************************/

 
 void Timer_Init(){	
	/* Enable CTC Mode */	 	 
	 Clear_Bit(TIMER0->TCCR0,Bit3);
	 Set_Bit(TIMER0->TCCR0,Bit6);
	 
 }
 
 /****************************************************************************/
 /*  INPUT: n ms number of delay
 /*  OUTPUT:NOTHING
 /*  Description: This functions starts the timer and takes the number of ms you need to delay

 /****************************************************************************/
 void Timer_delay(uint32 n){
	 int i=0;
	 /* choose 64 prescelar */
	 Set_Bit(TIMER0->TCCR0,Bit0);
	 Set_Bit(TIMER0->TCCR0,Bit1);
	 Clear_Bit(TIMER0->TCCR0,Bit2);
	 /*choose OCR0*/
	  OCR0=249;
	 for (i=0;i<n;i++)
	 {
		 while (!(TIFR & 0x02));
		 TIFR|=(1<<2);
	 }
	
 }
 