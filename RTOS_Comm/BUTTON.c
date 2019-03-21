#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_gpio.h"
#include "driverlib/gpio.h"
#include "driverlib/rom.h"
#include "utils/uartstdio.h"
#include "include/FreeRTOS.h"
#include "include/task.h"
#include "include/queue.h"
#include "include/semphr.h"
#include "driverlib/sysctl.h"
#include "BUTTON.h"

#define PRESSED 1
#define NOT_PRESSED 0


/* function to initialize the PUSH BUTTON*/
extern void BUTTON_Init(void){
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
        while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
             { }
           GPIOPinTypeGPIOInput(GPIO_PORTF_BASE, (GPIO_PIN_4|GPIO_PIN_0));
           HWREG(GPIO_PORTF_BASE+GPIO_O_LOCK) = GPIO_LOCK_KEY;
           HWREG(GPIO_PORTF_BASE+GPIO_O_CR) |= 0x01;
           GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
           GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);


}

/* function to get the value of the PUSH BUTTON*/
extern uint8_t Get_BUTTON1(void){

    uint8_t key;
    if(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_4)){
        key=PRESSED;

    }
    else{
        key=NOT_PRESSED;
    }
    return key;
}

extern uint8_t Get_BUTTON2(void){
    uint8_t key;
    if(!GPIOPinRead(GPIO_PORTF_BASE,GPIO_PIN_0)){
        key=PRESSED;
    }
    else{
        key=NOT_PRESSED;

    }
    return key;
}
