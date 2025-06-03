#include <LPC21xx.H>
#include "timer.h"

#define COUNTER_ENABLE_bm (1 << 0)
#define COUNTER_RESET_bm (1 << 1)

#define T0MCR_RESET_ON_MR0_bm (1 << 1)
#define T0MCR_INTERRUPT_ON_MR0_bm (1 << 0)
#define T0IR_MR0_INTERRUPT_bm (1 << 0)

void InitTimer0(void){
	
	T0TCR = COUNTER_ENABLE_bm;
	
}

void WaitOnTimer0(unsigned int uiTime){
	
	T0TCR = (T0TCR | COUNTER_RESET_bm);
	T0TCR = (T0TCR & (~COUNTER_RESET_bm));

	while (T0TC != (uiTime * 15)){}
 //bezpieczniej uzyc znaku < poniewaz wartosc T0TC zmienia sie bardzo szybko i jest szansa ze odczyt stanu timera minie sie z porownywana wartoscia  T0TC != (uiTime * 15)
	
}

void InitTimer0Match0(unsigned int iDelayTime){
	
	T0MR0 = (iDelayTime * 15);
	T0MCR = (T0MCR | (T0MCR_RESET_ON_MR0_bm | T0MCR_INTERRUPT_ON_MR0_bm));
	
	T0TCR = (T0TCR | COUNTER_RESET_bm);
	T0TCR = (T0TCR & (~COUNTER_RESET_bm));
	T0TCR = COUNTER_ENABLE_bm;
	
}

void WaitOnTimer0Match0(void){
	
	while((T0IR & T0IR_MR0_INTERRUPT_bm) == 0){}
	
	T0IR = T0IR_MR0_INTERRUPT_bm;
			
}
