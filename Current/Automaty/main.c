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
	
	enum LedState {SHIFT_LEFT, STOP, SHIFT_RIGHT};
	enum LedState eLedState = STOP;
	
	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState) {
			
			case SHIFT_LEFT:
				LedStepLeft();
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = STOP;
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
				LedStepRight();
				if( BUTTON_1 == eKeyboardRead() ){
					eLedState = STOP;
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
				LedStepRight();
			  ucShiftCounter++;
				if(3 <= ucShiftCounter){
					eLedState = STOP;
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
				LedStepRight();
				if( BUTTON_0 == eKeyboardRead() ){
					eLedState = STOP;
				}
				break;
		}
		Delay(250);
	}	
  
}*/
