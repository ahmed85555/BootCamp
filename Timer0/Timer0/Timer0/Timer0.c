/*
 * Timer0.c
 *
 * Created: 2/14/2019 9:38:01 AM
 *  Author: AVE-LAP-005 */
 
 #include "Types.h"
 #include "Utilites.h"
 #include "BitwiseOperations.h"
 #include "Timer_Interface.h"
 #include "Timer_Register.h"
 #include "Interrupt_Confg.h"
 #include "DIO_Interface.h"
 #include <avr/interrupt.h>
 
 volatile uint32 timer_counter=0;
 void (*Call_Back)(void);
 void (*Call_Back_External)(void);
/****************************************************************************
*  INPUT:NOTHING
*  OUTPUT:NOTHING
* Description: This function Initilaize timer0 to be in the ctc mode

****************************************************************************/

 
 void Timer_Init(){	
	/* Enable CTC Mode */	 	 
	 Clear_Bit(TCCR0,Bit3);
	 Set_Bit(TCCR0,Bit6);
	  /* choose 64 prescelar */
	  Set_Bit(TCCR0,Bit0);
	  Set_Bit(TCCR0,Bit1);
	  Clear_Bit(TCCR0,Bit2);
	  /*choose OCR0*/
	  OCR0=249;
	  /*Enable CTC Interrupt*/
	  Set_Bit(TIMSK,Bit1);
 }
 
 void External_Interrupt_Init(){
	 /*SET direction of external as input */
	 DIO_SetPinDirection(pin10,INPUT_WITHOUT_PULL);
	  /*Enable External Interrupt */
	  Set_Bit(MCUSCR,Bit6);
	  /*Enable INT2*/
	  Set_Bit(GICR,Bit5);
 }
 
 /****************************************************************************
  INPUT: n ms number of delay
  OUTPUT:NOTHING
  Description: This functions starts the timer and takes the number of ms you need to delay

 ****************************************************************************/
 void Timer_delay(uint32 n){
	 timer_counter=n;
 }
 
 void Enable_Global_Interrupt(){
	 /* Enable Global Interrupt */
	 Set_Bit(STATUS_REG,NUM_SEVEN);
	 
 }
 void Set_CallBack(void (*ptr)(void)){
	 Call_Back=ptr;
	 
 }
 void Set_External_CallBack(void (*ptr)(void)){
	 Call_Back_External=ptr;
 }
 ISR(TIMER0_COMP_vect){
	 uint32 i=0;
	 if (i<timer_counter)
	 {
		 i++;
	 }else{
		 i=0;
		 Call_Back();
		 
	 }
	 
 }
 ISR(INT1_vect){
	 if (DIO_ReadPin(10))
	 {
		 Call_Back_External();
	 }
 }