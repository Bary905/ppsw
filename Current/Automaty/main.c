#include "led.h"
#include "keyboard.h"

void Delay(unsigned int uiTime){
	
	unsigned int uiIterations;
	unsigned int uiCounter;
	unsigned int uimSecond = 5500;
	uiIterations = uiTime * uimSecond;
	
	for(uiCounter = 0; uiCounter < uiIterations; uiCounter ++){};
		
}

int main(){
	
	enum LedState {SHIFT_LEFT, STOP, SHIFT_RIGHT, WIPER, WAIT_FOR_BUTTON};
	enum LedState eLedState = STOP;
	unsigned char ucWiperCycles;

	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case SHIFT_LEFT:
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = STOP;
				}
				else if( BUTTON_3 == eKeyboardRead() ){
					ucWiperCycles = 0;
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
				if(ucWiperCycles == 5){
					eLedState = WAIT_FOR_BUTTON;
				}
				else{
					if((ucWiperCycles%2)==0){
						LedStepLeft();
						ucWiperCycles++;
					}
					else if((ucWiperCycles%2)==1){
						LedStepRight();
						ucWiperCycles++;
					}
				}
				break;
				
				case WAIT_FOR_BUTTON:
				if( BUTTON_2 == eKeyboardRead() ){
					eLedState = SHIFT_RIGHT;
				}
				else{
					eLedState = WAIT_FOR_BUTTON;
				}
				break;
		}
		Delay(100);
	}	
  
}


//ZADANIE 3
/*
int main(){
	
	enum LedState {STATE_LEFT, STATE_RIGHT};
	enum LedState eLedState = STATE_LEFT;

	unsigned char ucShiftCounter = 0;
	
	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case STATE_LEFT:
				LedStepLeft();
			  ucShiftCounter++;
				if(3 <= ucShiftCounter){
					eLedState = STATE_RIGHT;
				}
				break;
			
			case STATE_RIGHT:
				LedStepRight();
				ucShiftCounter--;
				if(0 >= ucShiftCounter){
					eLedState = STATE_LEFT;
				}
				break;
			
		}
		Delay(250);
	}	
  
}*/

//ZADANIE 4
/*
int main(){
	
	enum LedState {STOP, SHIFT_RIGHT};
	enum LedState eLedState = STOP;

	unsigned char ucShiftCounter;
	
	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case STOP:
				if( BUTTON_0 == eKeyboardRead() ){
					eLedState = SHIFT_RIGHT;
					ucShiftCounter = 0;
				}
				break;
			
			case SHIFT_RIGHT:
				if(3 <= ucShiftCounter){
					eLedState = STOP;
				}
				else{
					LedStepRight();
					ucShiftCounter++;
				}
				break;
		}
		Delay(250);
	}	
  
}*/

//ZADANIE_5
/*
int main(){
	
	enum LedState {STOP, SHIFT_RIGHT};
	enum LedState eLedState = SHIFT_RIGHT;
	
	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case STOP:
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = SHIFT_RIGHT;
				}
				break;
			
			case SHIFT_RIGHT:
				if( BUTTON_0 == eKeyboardRead() ){
					eLedState = STOP;
				}
				else{
					LedStepRight();
			  }
				break;
		}
		Delay(250);
	}	
  
}*/
