#include "timer_interrupts.h"
#include "led.h"
#include "keyboard.h"

void Automat(){
	
	enum LedState {SHIFT_LEFT, STOP, SHIFT_RIGHT};
	static enum LedState seLedState = STOP;

	switch(seLedState) {
				
				case SHIFT_LEFT:
					if( BUTTON_1 == eKeyboardRead() ){
						seLedState = STOP;
					}
					else{
						LedStepLeft();
					}
					break;
				
				case STOP:
					if( BUTTON_0 == eKeyboardRead() ){
						seLedState = SHIFT_LEFT;
					}
					else if( BUTTON_2 == eKeyboardRead() ){
						seLedState = SHIFT_RIGHT;
					}
					break;
				
				case SHIFT_RIGHT:
					if( BUTTON_1 == eKeyboardRead() ){
						seLedState = STOP;
					}
					else{
						LedStepRight();
					}
					break;
	}
	
}

int main (){
	unsigned int uiMainLoopCtr;
	Timer0Interrupts_Init(20000, &Automat);
	LedInit();
	KeyboardInit();

	while(1){
	 	uiMainLoopCtr++;
	}
}
