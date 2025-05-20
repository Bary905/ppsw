#include <LPC21xx.H>

#include "led.h"

#define S0_bm 0x00000010
#define S1_bm 0x00000040
#define S2_bm 0x00000020
#define S3_bm 0x00000080

void Delay(unsigned int uiTime){
	
	unsigned int uiIterations;
	unsigned int uiCounter;
	unsigned int uimSecond = 12200;
	uiIterations = uiTime * uimSecond;
	
	for(uiCounter = 0; uiCounter < uiIterations; uiCounter ++){};
		
}

enum KeyboardState {RELASED, BUTTON_0, BUTTON_1, BUTTON_2, BUTTON_3};
enum KeyboardState eKeyboardRead(){
	
	if((IO0PIN & S0_bm)==0){
		return BUTTON_0;
	}
	
	else if((IO0PIN & S1_bm)==0){ 
		return BUTTON_1;
	}
	
	else if((IO0PIN & S2_bm)==0){ 
		return BUTTON_2;
	}
	
	else if((IO0PIN & S3_bm)==0){
		return BUTTON_3;
	}
	
	else{
	return RELASED;
	}

}
void KeyboardInit(){
	
	IO0DIR = (IO0DIR)&(~(S0_bm | S1_bm | S2_bm | S3_bm));
	
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
			  Delay(250);
				break;
			
			case BUTTON_2 :
				LedStepLeft();
				Delay(250);
			  break;
			
			case BUTTON_0 :
				break;
			
			case BUTTON_3 :
				break;
		}	
	}	

	}
