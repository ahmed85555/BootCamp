/*
 * Stol.c
 *
 *  Created on: Mar 18, 2019
 *      Author: AVE-LAP-005
 */

#include <stdlib.h>
#include "LED.h"
#include "BUTTON.h"
#include "LCD.h"
#include "FreeRTOSConfig.h"
#include "include/FreeRTOS.h"
#include "include/queue.h"

/****************************switch_Send_Task()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *
 ********************************************************************/
QueueHandle_t xQueue;

void switch_Send_Task()
{
    xQueue = xQueueCreate(2, sizeof(char));
    uint8_t get_button1=0;
    uint8_t get_button2=0;

    while(1){
        get_button1=Get_BUTTON1();
        get_button2=Get_BUTTON2();
        if(get_button1==1){
            get_button1++;
            xQueueOverwrite( xQueue, &get_button1 );

        }
        if(get_button2==1){
            get_button2=get_button2+2;
            xQueueOverwrite( xQueue, &get_button2 );
           }
       vTaskDelay(70);
       }

}
/****************************switch_Receive_Task()*************************
 *I/P:NOTHING
 *O/P:NOTHING
 *
 ********************************************************************/
void switch_Receive_Task()
{
    uint8_t receive=0;
    uint8_t count1=0;
    uint8_t count2=0;
    while(1){

        xQueueReceive(xQueue,&receive,1);
        if(receive==2){
            count1++;
            LCD_gotoRowColumn(1, 0);
            LCD_displayChar(count1+48);
            receive=0;
            xQueueOverwrite( xQueue, &receive );

        }
        if(receive==3)
        {
            count2++;
           LCD_gotoRowColumn(2, 0);
           LCD_displayChar(count2+48);
           receive=0;
           xQueueOverwrite( xQueue, &receive );
        }

       vTaskDelay(50);
       }

}
