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
	
	LedInit();
	KeyboardInit();
	
	while(1){
	
		switch(eKeyboardRead()){
			
			case RELASED :
				break;
			
			case BUTTON_1 :
				LedStepRight();
				break;
			
			case BUTTON_2 :
				LedStepLeft();
			  break;
			
			case BUTTON_0 :
				break;
			
			case BUTTON_3 :
				break;
		}
    Delay(250);
	}	
  
}
