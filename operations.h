#include "TM4C123.h"
#include "stdio.h"
#include "Io.h"
#include "delays.h"
#include "keypad.h"
#include "lcd.h"
#include "switches.h"
#include "stdlib.h"

#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

void start_reading(unsigned char key);
void beef_cooking(unsigned char weight);
void chicken_cooking(unsigned char weight);


enum States {idle, prep, cooking, finish} mystate;
void RGB_Init(void);
void RGB_Output(unsigned char data);
void Blink (void);
enum States countdown(int min, int sec);
enum States cooking_time(void);
unsigned char button_in;
unsigned char door_button;
unsigned char key;
unsigned char weight;
int seconds;
int minutes;
char c;
int min;
int  sec;

void SW3_Init(void);
unsigned sw3_Input(void);


int8_t i;
void start_reading(unsigned char key)
{
		
LCD_command(0x80); /* LCD cursor location */
switch (key)
{
  case ('A'):

			LCD_command(0x01);//clearing lcd
			LCD_String("Popcorn"); 
		delayMs(2000);//delay 2 seconds
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
	 	break; 
	 
	 case ('B')://miffro -->case B
			
	 break;

	 case ('C'):
			
			break;
	 
	 case('D'):
				LCD_String("Cooking Time?");
				delayMs(2000);
				LCD_command(0xC0);
				mystate =cooking;
				break;
}
return;
}
