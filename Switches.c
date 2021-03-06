#include "tm4c123gh6pm.h"
#include "stdint.h"
#include "Io.h"
#include "TM4C123.h"
#include "lcd.h"



void SW1_Init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20; //for all bits in port f
	  while((SYSCTL_PRGPIO_R &= 0x20)== 0){} //delay
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0x10; 
		GPIO_PORTF_AMSEL_R &=~ 0x10; 
		GPIO_PORTF_AFSEL_R &=~ 0x10;
		GPIO_PORTF_DIR_R &=~ 0x10;
		GPIO_PORTF_DEN_R |= 0x10;
		GPIO_PORTF_PCTL_R &=~0x000F0000;
		GPIO_PORTF_PUR_R |= 0x10; 
}
void SW2_Init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x20; //for all bits in port f
	  while((SYSCTL_PRGPIO_R &= 0x20)== 0){} //delay
		GPIO_PORTF_LOCK_R = 0x4C4F434B;
		GPIO_PORTF_CR_R |= 0x01; 
		GPIO_PORTF_AMSEL_R &=~ 0x01; 
		GPIO_PORTF_AFSEL_R &=~ 0x01;
		GPIO_PORTF_DIR_R &=~ 0x01;
		GPIO_PORTF_DEN_R |= 0x01;
		GPIO_PORTF_PCTL_R &=~0x0000000F;
		GPIO_PORTF_PUR_R |= 0x01; 
}

void SW3_Init(void)
{
    SYSCTL_RCGCGPIO_R |= 0x01; //for all bits in port A
	  while((SYSCTL_PRGPIO_R &= 0x01)== 0){} //delay
		GPIO_PORTA_LOCK_R = 0x4C4F434B;
		GPIO_PORTA_CR_R |= 0x08; 
		GPIO_PORTA_AMSEL_R &=~ 0x08; 
		GPIO_PORTA_AFSEL_R &=~ 0x08;
		GPIO_PORTA_DIR_R &=~ 0x08;
		GPIO_PORTA_DEN_R |= 0x08;
		GPIO_PORTA_PCTL_R &=~0x0000F000;
		GPIO_PORTA_PUR_R |= 0x08; 
}



unsigned sw_Input(void)
{
	return (GPIO_PORTF_DATA_R & 0x11);
}

unsigned sw3_Input(void)
{
	return ((GPIO_PORTA_DATA_R & (1<<3))>>3);
}


void Buzzer_VInit () {
SYSCTL_RCGCGPIO_R |= 0x01 ; 
while ((SYSCTL_RCGCGPIO_R & 0x01) ==0) ; 
GPIO_PORTA_LOCK_R = 0x4C4F434B ; 
GPIO_PORTA_CR_R |= 0x04 ; 
GPIO_PORTA_DEN_R |= 0x04 ; 
GPIO_PORTA_DIR_R |= 0x04 ; 
GPIO_PORTA_AFSEL_R &= ~0x04 ; 
GPIO_PORTA_PCTL_R &= ~0x00000F00 ; 
GPIO_PORTA_DATA_R &= ~0x04 ; 
}

void Buzzer_ON (){
GPIO_PORTA_DATA_R |= 0x04; 
}


void Buzzer_OFF (){
GPIO_PORTA_DATA_R &= ~0x04 ; 
}

void Buzzer_TOGGLE (){
GPIO_PORTA_DATA_R ^= 0x04 ; 
}
