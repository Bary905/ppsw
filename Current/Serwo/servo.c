#include <LPC21xx.H>

#include "timer_interrupts.h"
#include "led.h"
#include "servo.h"

#define DETECTOR_bm (1 << 10)

void DetectorInit(void){
	
	IO0DIR = IO0DIR & (~DETECTOR_bm);
	
}

enum DetectorState {ACTIVE, INACTIVE};
enum DetectorState eReadDetector(void){
	
	if((IO0PIN & DETECTOR_bm)==0){
		return ACTIVE;
	}
	else{
		return INACTIVE;
	}
}

enum ServoState {CALLIB, IDLE, IN_PROGRESS, OFFSET};

struct Servo{
	enum ServoState eState;
	unsigned int uiCurrentPosition;
	unsigned int uiDesiredPosition;
}; struct Servo sServo;

void Automat(void){

	switch(sServo.eState) {
				
				case CALLIB:
					if( ACTIVE == eReadDetector() ){
						sServo.uiCurrentPosition = 12;
						sServo.uiDesiredPosition = 0;
						sServo.eState = IDLE;
						
					}
					else{
						LedStepLeft();
					}
					break;
					
				case OFFSET:
					if( sServo.uiCurrentPosition == sServo.uiDesiredPosition ){
						sServo.uiCurrentPosition = 0;
						sServo.uiDesiredPosition = 0;
						sServo.eState = IDLE;
					}
					else{
						LedStepRight();
						sServo.uiCurrentPosition--;
					}
					break;
					
				case IDLE:
					if( sServo.uiCurrentPosition != sServo.uiDesiredPosition ){
						sServo.eState = IN_PROGRESS;
					}
					else{
						sServo.eState = IDLE;
					}
					break;
				
				case IN_PROGRESS:
					if( sServo.uiCurrentPosition == sServo.uiDesiredPosition ){
						sServo.eState = IDLE;
					}
					else if( sServo.uiCurrentPosition > sServo.uiDesiredPosition ){
						LedStepLeft();
						sServo.uiCurrentPosition--;
					}
					else if( sServo.uiCurrentPosition < sServo.uiDesiredPosition ){
						LedStepRight();
						sServo.uiCurrentPosition++;
					}
					break;
					
	}
	
}

void ServoInit(unsigned int uiFrequency){
	
	LedInit();
	DetectorInit();
	Timer0Interrupts_Init((1000000/uiFrequency), &Automat);
	sServo.eState = CALLIB;
	
}

void ServoCallib(void){
	
	sServo.eState = CALLIB;
	
}

void ServoGoTo(unsigned int uiPosition){

	sServo.uiDesiredPosition = uiPosition;
	
	while(sServo.uiCurrentPosition != sServo.uiDesiredPosition){}

}
