

/**
 * main.c
 */
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "BUTTON.h"
#include "LED.h"
#include "StoL.h"
#include "LCD.h"

/****************************switch_to_led()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *This function initializes all the system
 ********************************************************************/
void Init_Task(void){
while(1){
LED_Init();
BUTTON_Init();
LCD_init();
vTaskSuspend(NULL);


}

}

int main(void)
{
    /*Create the tasks */
    xTaskCreate(Init_Task,"init Task",100,NULL,4,NULL);
    xTaskCreate(switch_Send_Task,"main task",100,NULL,3,NULL);
    xTaskCreate(switch_Receive_Task,"main task",100,NULL,2,NULL);
    /*start the scheduler*/
    vTaskStartScheduler();
    while(1){

    }
	return 0;
}
