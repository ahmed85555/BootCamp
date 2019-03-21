
#include <stdbool.h>
#include <stdint.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/queue.h"
#include "include/semphr.h"
#include "driverlib/sysctl.h"
#include "LED.h"
#define ZERO 0

/****************************LED_Init()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *Description:this fun initializes the leds
 ********************************************************************/
void LED_Init(void )
{
    /*Enable Clock on GPIOF on pin1 and 2 and 3*/
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
         { }
     GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, (GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3));

}
/****************************LED1on_Task()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *
 ********************************************************************/
void LED1on_Task(void){
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,GPIO_PIN_1 );
    }
/****************************LED1off_Task()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *
 ********************************************************************/
void LED1off_Task(void){
    GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1,0 );
    }


