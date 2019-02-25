/*
 * Timer0.c
 *
 * Created: 2/14/2019 9:38:01 AM
 *  Author: AVE-LAP-005 */
 #define F_CPU 16000000
 #include "Types.h"
 #include "Utilites.h"
 #include "BitwiseOperations.h"
 #include "TIMER_Confg.h"
 #include "Timer.h"
 #include <stdio.h>
 #include <avr/interrupt.h>
 

 void (*Call_Back)(void)=NULL;
 
/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Initilaize timer1 to be in the ctc mode
* with tick time equal to one millisecond

****************************************************************************/

 
 void Timer_Init()
 {	
	/* Enable CTC Mode in TIMER 1 */	 	 
	 Clear_Bit(TIMER1->TCCRA,WGM10);
	 Clear_Bit(TIMER1->TCCRA,WGM11);
	 Clear_Bit(TIMER1->TCCRB,WGM13);
	 Set_Bit(TIMER1->TCCRB,WGM12);
	 /* set ocra */
	
	 TIMER1->OCRAH= OCR_value >> EIGHT_SHIFT;
	 TIMER1->OCRAL= OCR_value & LOW_MASK;
	 /* choose prescelar */
	 Set_Bit(TIMER1->TCCRB,CS00);
	 Clear_Bit(TIMER1->TCCRB,CS01);
	 Clear_Bit(TIMER1->TCCRB,CS02); 
	 
	 /* Enable Interrupt */
	 Set_Bit(TIMSK,OCIE1A);
	 
	 /*Enable Global Interrupt*/
	 sei();
	  
 }
/****************************************************************************
*  INPUT:Pointer to function
*  OUTPUT:NOTHING
* Description: This function used to set the callBack pinter to function to be equal 
* to the argument void (*ptr)(void)

****************************************************************************/
void Set_CallBack(void (*ptr)(void)){
	
	Call_Back=ptr;
	
}

 
 ISR(TIMER1_COMPA_vect){
	
	if (NULL != Call_Back)
	{
		Call_Back();
	}
	
 }
 
 
 
