#include "delays.h"
#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))
	
void SysTick_Init(void){ //intialize systick
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x00000005;

}	
void SysTick_hold(unsigned long delay){ //1 sec wait
 NVIC_ST_RELOAD_R = delay -1;
 NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;
 while((NVIC_ST_CTRL_R & 0X00010000)==0){};
}

/* delay n milliseconds (16 MHz CPU clock) */
void delayMs(unsigned long delay )
{
	unsigned long n;
for (n=0 ; n < delay; n++ )
	SysTick_hold(16000);
}
