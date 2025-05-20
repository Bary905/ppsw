#include <LPC21xx.H>

#define LED0_bm 0x00010000
#define LED1_bm 0x00020000
#define LED2_bm 0x00040000
#define LED3_bm 0x00080000

#define S0_bm 0x00000010
#define S1_bm 0x00000040
#define S2_bm 0x00000020
#define S3_bm 0x00000080

void Delay(unsigned int uiTime){
	
	unsigned int uiIterations;
	unsigned int uiCounter;
	uiIterations = uiTime * 12200;
	
	for(uiCounter = 0; uiCounter < uiIterations; uiCounter ++){};
		
}

void LedInit(){
	
	IO1DIR = IO1DIR | (LED0_bm | LED1_bm | LED2_bm | LED3_bm);
	IO1SET = LED0_bm;
	
}

void LedOn(unsigned char ucLedIndeks){
	
	int iLedMask[] = {LED0_bm, LED1_bm, LED2_bm, LED3_bm};
	
	IO1CLR = LED0_bm | LED1_bm | LED2_bm | LED3_bm;
	IO1SET = iLedMask[ucLedIndeks];

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
	
	IO0DIR = IO0DIR & (~(S0_bm | S1_bm | S2_bm | S3_bm));
	
}

enum eDirection{LEFT, RIGHT};
void LedStep(enum eDirection(eStepDirection)){
	
	static unsigned int suiLedCounter=0;
	
	switch(eStepDirection){
	
	  case LEFT:
			suiLedCounter++;
		  break;
		
		case RIGHT:
			suiLedCounter--;
		  break;
  }
	LedOn(suiLedCounter%4);
}

void LedStepLeft(void){
	
	LedStep(LEFT);
	
}

void LedStepRight(void){
	
	LedStep(RIGHT);
	
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
