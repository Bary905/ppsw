#include "led.h"
#include "keyboard.h"

#define WIPER_CYCLES 3

void Delay(unsigned int uiTime){
	
	unsigned int uiIterations;
	unsigned int uiCounter;
	unsigned int uimSecond = 5500;
	uiIterations = uiTime * uimSecond;
	
	for(uiCounter = 0; uiCounter < uiIterations; uiCounter ++){};
		
}

int main(){
	
	enum LedState {SHIFT_LEFT, STOP, SHIFT_RIGHT, WIPER};
	enum LedState eLedState = STOP;
	unsigned char ucStepCounter = 0;
	unsigned char ucCyclesCounter = 0;

	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case SHIFT_LEFT:
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = STOP;
				}
				else if( BUTTON_3 == eKeyboardRead() ){
					LedOn(0);
					uiLedCounter = 0;
					eLedState = WIPER;
					
				}
				else{
					LedStepLeft();
				}
				break;
			
			case STOP:
				if( BUTTON_0 == eKeyboardRead() ){
					eLedState = SHIFT_LEFT;
				}
				else if( BUTTON_2 == eKeyboardRead() ){
					eLedState = SHIFT_RIGHT;
				}
				break;
			
			case SHIFT_RIGHT:
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = STOP;
				}
				else{
					LedStepRight();
				}
				break;
				
			case WIPER:
				if(BUTTON_1 == eKeyboardRead()){
					eLedState = STOP;
				}
				else if(ucCyclesCounter < WIPER_CYCLES){
					if(3 > ucStepCounter){
						LedStepLeft();
						ucStepCounter++;
					}
					else if(6 > ucStepCounter && 3 <= ucStepCounter){
						LedStepRight();
						ucStepCounter++;
					}
					else if(6 == ucStepCounter){
						ucCyclesCounter++;
						ucStepCounter = 0;
					}
				}
				else if(ucCyclesCounter == WIPER_CYCLES){
					eLedState = SHIFT_RIGHT;
					ucCyclesCounter = 0; 
				}
		}
		Delay(100);
	}	
  
}
