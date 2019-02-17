/*
 * delay.c
 *
 * Created: 2/13/2019 4:43:23 PM
 *  Author: AVE-LAP-005
 */ 
#include "Types.h"


void delay_ms(uint32 N){
	/* the nearest Number to 1 Millisecond if the cpu timer 1 MHZ is 29 for loop so we will multiple with 29 */
	
	for (int i=0;i<N*29;i++)
	{
		
	}
	
}