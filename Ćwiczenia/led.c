#include <LPC21xx.H>
#include "led.h"

#define LED0_bm (1 << 16)
#define LED1_bm (1 << 17)
#define LED2_bm (1 << 18)
#define LED3_bm (1 << 19)

void LedInit(void){
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
	
}

void LedOn(unsigned char ucLedIndeks){
	
	int iLedMask[] = {LED0_bm, LED1_bm, LED2_bm, LED3_bm};
	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = iLedMask[ucLedIndeks];

}

//enum eDirection{LEFT, RIGHT};
unsigned int uiLedCounter=0;
void LedStep(enum eDirection(eStepDirection)){
	
	switch(eStepDirection){
	
	  case LEFT:
			uiLedCounter++;
		  break;
		
		case RIGHT:
			uiLedCounter--;
		  break;
  }
	LedOn(uiLedCounter%4);
}

void LedStepLeft(void){
	
	LedStep(LEFT);
	
}

void LedStepRight(void){
	
	LedStep(RIGHT);
	
}
