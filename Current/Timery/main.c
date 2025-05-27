#include "led.h"
#include "timer.h"

int main(){
	
	LedInit();
	InitTimer0Match0(500000);	
	
	while(1){
		
	LedStepLeft();
	WaitOnTimer0Match0();
	
	}		
}


//Cwiczenie 1
/*
int main(){
	
	LedInit();
	InitTimer0();
	
	while(1){
		
	LedStepLeft();
	WaitOnTimer0(250000);
	
	}		
}*/
