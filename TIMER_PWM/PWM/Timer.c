/*
 * Timer.h
 *
 * Created: 2/21/2019 1:31:46 PM
 *  Author: AVE-LAP-005
 */ 
#define F_CPU 16000000UL
#include "Types.h"
#include "TIMER_Confg.h"
#include "Timer.h"
#include "DIO_Interface.h"
#include "Utilites.h"
#include "BitwiseOperations.h"

/****************************************PWM_Init******************************
* Parameters:  
*             I/P:NOINPUT
*             O/P:NOOUTPUT
*             I/O:
* Description:This Function Initializes the Timer with the Mode you will choose
* In the Timer.h you can choose between two modes F_PWM and PHASE_CORRECT
* and you can choose if you want to work in INVERTING or NON_INVERTING in the header file
* Timer.h so you will define the mode fast or phase and define inverting or non inverting
* in the header file Timer.h
********************************************************************************/
void PWM_Init(){
	/*Initialize Motor Pins*/
	DIO_SetPinDirection(OC1A_PIN,OUTPUT);
	DIO_SetPinDirection(OC1B_PIN,OUTPUT);
	DIO_SetPinDirection(MOTOR1_PIN1,OUTPUT);
	DIO_SetPinDirection(MOTOR1_PIN2,OUTPUT);
	DIO_SetPinDirection(MOTOR2_PIN1,OUTPUT);
	DIO_SetPinDirection(MOTOR2_PIN2,OUTPUT);
	DIO_WritePin(MOTOR1_PIN1,LOW);
	DIO_WritePin(MOTOR1_PIN2,High);
	DIO_WritePin(MOTOR2_PIN1,LOW);
	DIO_WritePin(MOTOR2_PIN2,High);
	#ifdef F_PWM
	Set_Bit(TIMER1->TCCRA,WGM11);
	Clear_Bit(TIMER1->TCCRA,WGM10);
	Set_Bit(TIMER1->TCCRB,WGM12);
	Set_Bit(TIMER1->TCCRB,WGM13);
	/* Choose INverting or Non Inverting Mode */
	#ifdef NON_INVERTING
	Set_Bit(TIMER1->TCCRA,COM1A1_PIN);
	Clear_Bit(TIMER1->TCCRA,COM1A0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B1_PIN);
	Clear_Bit(TIMER1->TCCRA,COM1B0_PIN);
	/* set prescelar one */
	Set_Bit(TIMER1->TCCRB,CS10_PIN);
	Clear_Bit(TIMER1->TCCRB,CS11_PIN);
	Clear_Bit(TIMER1->TCCRB,CS12_PIN);
	#endif
	#ifdef INVERTING
	Set_Bit(TIMER1->TCCRA,COM1A0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1A1_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B1_PIN);
	/* set prescelar one */
	Set_Bit(TIMER1->TCCRB,CS10_PIN);
	Clear_Bit(TIMER1->TCCRB,CS11_PIN);
	Clear_Bit(TIMER1->TCCRB,CS12_PIN);
	
	#endif
	#endif
	
	#ifdef PHASE_CORRECT
	Set_Bit(TIMER1->TCCRA,WGM11);
	Clear_Bit(TIMER1->TCCRA,WGM10);
	Clear_Bit(TIMER1->TCCRB,WGM12);
	Set_Bit(TIMER1->TCCRB,WGM13);
	#ifdef NON_INVERTING
	Set_Bit(TIMER1->TCCRA,COM1A1_PIN);
	Clear_Bit(TIMER1->TCCRA,COM1A0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B1_PIN);
	Clear_Bit(TIMER1->TCCRA,COM1B0_PIN);
	/* set prescelar one */
	Set_Bit(TIMER1->TCCRB,CS10_PIN);
	Clear_Bit(TIMER1->TCCRB,CS11_PIN);
	Clear_Bit(TIMER1->TCCRB,CS12_PIN);
	#endif
	#ifdef INVERTING
	Set_Bit(TIMER1->TCCRA,COM1A0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1A1_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B0_PIN);
	Set_Bit(TIMER1->TCCRA,COM1B1_PIN);
	/* set prescelar one */
	Set_Bit(TIMER1->TCCRB,CS10_PIN);
	Clear_Bit(TIMER1->TCCRB,CS11_PIN);
	Clear_Bit(TIMER1->TCCRB,CS12_PIN);
	#endif
	#endif

	
}
void PWM_Generate(uint8 Copy_u8DutyCycle,uint32 Copy_u32freq){
	uint16 Local_Top;
	uint16 Local_Comp_Value;
	#ifdef F_PWM
	#ifdef NON_INVERTING
		/* set ocr value */
	Local_Top=(F_CPU/Copy_u32freq)-1;
	Local_Comp_Value=(((Local_Top+1)/100)*(Copy_u8DutyCycle));
	
	TIMER1->OCRBH = Local_Comp_Value  >> SHIFT_EIGHT;
	TIMER1->OCRBL = (Local_Comp_Value & LOW_MASK);
	

	/* Set top value */
	
	TIMER1->ICRH = (Local_Top & HIGH_MASK) >> SHIFT_EIGHT;
	TIMER1->ICRL = Local_Top & LOW_MASK;
	
	#endif
	#ifdef INVERTING
	
	/* set ocr value */
	Local_Top=(F_CPU/(NUM_TWO*Copy_u32freq));
	Local_Comp_Value=((Local_Top/100)*(100-Copy_u8DutyCycle));
	
	TIMER1->OCRBH = Local_Comp_Value  >> SHIFT_EIGHT;
	TIMER1->OCRBL = (Local_Comp_Value & LOW_MASK);
	

	/* Set top value */
	
	TIMER1->ICRH = (Local_Top & HIGH_MASK) >> SHIFT_EIGHT;
	TIMER1->ICRL = Local_Top & LOW_MASK;
     #endif
     #endif
     #ifdef PHASE_CORRECT
     #ifdef NON_INVERTING
     /* set ocr value */
     Local_Top=(F_CPU/(NUM_TWO*Copy_u32freq));
     Local_Comp_Value=(((Local_Top+1)/100)*(Copy_u8DutyCycle));
     
     TIMER1->OCRBH = Local_Comp_Value  >> SHIFT_EIGHT;
     TIMER1->OCRBL = (Local_Comp_Value & LOW_MASK);
     
     
     /* Set top value */
     
     TIMER1->ICRH = (Local_Top & HIGH_MASK) >> SHIFT_EIGHT;
     TIMER1->ICRL = Local_Top & LOW_MASK;
     #endif
     #ifdef INVERTING
     
     /* set ocr value */
     Local_Top=(F_CPU/(NUM_TWO*Copy_u32freq));
     Local_Comp_Value=((Local_Top/100)*(100-Copy_u8DutyCycle));
     
     TIMER1->OCRBH = Local_Comp_Value  >> SHIFT_EIGHT;
     TIMER1->OCRBL = (Local_Comp_Value & LOW_MASK);
     
     
     /* Set top value */
     
     TIMER1->ICRH = (Local_Top & HIGH_MASK) >> SHIFT_EIGHT;
     TIMER1->ICRL = Local_Top & LOW_MASK;
     #endif
     #endif
	
	
}

