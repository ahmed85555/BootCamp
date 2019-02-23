/*
 * TIMER_PWM.c
 *
 * Created: 2/21/2019 1:28:39 PM
 * Author : AVE-LAP-005
 */ 

#include "Types.h"
#include "Timer.h"
#include "DIO_Interface.h"
#include "Utilites.h"


int main(void)
{
	PWM_Init();
	
    /* Choose your Mode in The Timer.h file and choose if you want your mode inverting or non inverting*/
	/* Choose your Duty Cycle AND Frequency you want */
   PWM_Generate(0,300);
}

