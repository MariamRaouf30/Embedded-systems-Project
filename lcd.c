#include "lcd.h"
#include "tm4c123gh6pm.h"
#include "delays.h"
#include "stdlib.h" 
#include "stdio.h"  
#include "switches.h"
#include "Io.h"


void LCD_command(unsigned char command){
	GPIO_PORTB_DATA_R=command;

	GPIO_PORTE_DATA_R=(LOW<<1)|(LOW<<2)|(HIGH<<3);
	delayMs(1);
	GPIO_PORTE_DATA_R=(LOW<<1)|(LOW<<2)|(LOW<<3);
	delayMs(50);
}

void LCD_Write_Char(unsigned char data){
		GPIO_PORTB_DATA_R=data;

	GPIO_PORTE_DATA_R=(HIGH<<1)|(LOW<<2)|(HIGH<<3);
	delayMs(1);
	GPIO_PORTE_DATA_R=(HIGH<<1)|(LOW<<2)|(LOW<<3);
	delayMs(50);

	return;
}

void PortB_Init()
{ // for LCD Data
	SYSCTL_RCGCGPIO_R |= 0x00000002;
  while ((SYSCTL_PRGPIO_R&0x02) == 0){};
	GPIO_PORTB_LOCK_R = 0x4C4F434B;
	GPIO_PORTB_CR_R |= 0xFF;
	GPIO_PORTB_DIR_R = 0xFF;
	GPIO_PORTB_DEN_R = 0xFF;
	GPIO_PORTB_AMSEL_R = 0x00;
	GPIO_PORTB_AFSEL_R = 0x00;
	GPIO_PORTB_PCTL_R = 0x00000000;
  GPIO_PORTB_PUR_R = 0x00;

}

void PortE_Init ()
{ // E1.E2.E3 for LCD control and E4,E5 for UART5
	SYSCTL_RCGCGPIO_R |= 0x00000010;
  while ((SYSCTL_PRGPIO_R&0x10) == 0){};
	GPIO_PORTE_LOCK_R = 0x4C4F434B;
	GPIO_PORTE_CR_R |= 0x0E;
	GPIO_PORTE_DIR_R |= 0x0E;
	GPIO_PORTE_DEN_R |= 0x0E;
	GPIO_PORTE_AMSEL_R = 0x00;
	GPIO_PORTE_AFSEL_R &= (~0x0E);
	GPIO_PORTE_PCTL_R = 0x00000000;
  GPIO_PORTE_PUR_R = 0x00;
}

void LCD_init(){
	PortB_Init();
	PortE_Init();
	LCD_command(Set8bitFunction);
	delayMs(1);

	LCD_command(EntryMode);
	delayMs(1);

	LCD_command(DisplayOn);
	delayMs(1);

	LCD_command(Clear);
	delayMs(2);

	LCD_command(Home);
	delayMs(2);

}

void LCD_String(char  *str)
{ // sends a string to display on the LCD
	int		i=0;
	while(str[i]!='\0')
	{
		LCD_Write_Char(str[i]);
		i++;
	}
	delayMs(100);
	
	return;
}
void LCD_SendString(char *data){
	while((*data)!='\0'){
		LCD_Write_Char((*data));
		data++;
	}
};