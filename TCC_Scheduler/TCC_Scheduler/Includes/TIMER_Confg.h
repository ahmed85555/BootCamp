/*
 * TIMER_Confg.h
 *
 * Created: 2/21/2019 1:30:56 PM
 *  Author: AVE-LAP-005
 */ 


#ifndef TIMER_CONFG_H_
#define TIMER_CONFG_H_

volatile typedef struct{
uint8 ICRL;
uint8 ICRH;
uint8 OCRBL;
uint8 OCRBH;
uint8 OCRAL;
uint8 OCRAH;
uint8 TCNTL;
uint8 TCNTH;
uint8 TCCRB;
uint8 TCCRA;
	
}strTimer;

/*Timer Interrupt register address to enable Interrupts*/
#define TIMSK (*(volatile uint8*)(0x59))

/*Interrupt Enable Pin*/
#define OCIE1A  4

/*WAVE generation mode bits*/
#define WGM10 0
#define WGM11 1
#define WGM12 3
#define WGM13 4
/*Inverting or non Inverting bits */
#define COM1A0_PIN  6
#define COM1A1_PIN  7
#define COM1B0_PIN  4
#define COM1B1_PIN  5

/*prescelar bits */
#define CS10_PIN 0
#define CS11_PIN 1
#define CS12_PIN 2

#define EIGHT_SHIFT 8
#define LOW_MASK 0x00ff

#define TIMER1 ((strTimer*)(0x46))


#endif /* TIMER_CONFG_H_ */