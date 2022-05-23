#include "TM4C123.h"
#include "stdio.h"
#include "Io.h"
#include "delays.h"
#include "keypad.h"
#include "lcd.h"
#include "switches.h"
#include "operations.h"

#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

void start_reading(unsigned char key);
void beefchicken_cooking(unsigned char weight);
void SysTick_Init(void);
void SysTick_wait1s(void);


unsigned char button_in;
unsigned char door_button;
unsigned char key;
unsigned char weight;


#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))



 


void init(void){};
int f;

int main(void)
{		
	
	
	init();
	SysTick_Init();
	RGB_Init();
	Buzzer_VInit ();
	SW1_Init();
	SW2_Init();
	SW3_Init();
	keypad_Init();
	LCD_init();
	
	mystate =idle;
	
	
while(1){

	 switch(mystate){
		case (idle):
			LCD_Clear_screen();
		LCD_String("Start!");
		while (keypad_getkey() == 0xFF){};
			LCD_Clear_screen();
			key = keypad_getkey();             // read the keypad 
					if(key=='A' || key=='B'||key=='C'||key=='D'){
						mystate = prep;}
							break;
		
						
	case (prep):
					start_reading(key);
					mystate = cooking;
		break;
					
		case (cooking):
				switch(key){
					case ('A'):
						while (sw_Input() != 0x10 || sw3_Input()==1){};           // wait until sw2 on
						mystate=countdown(1, 0);//printing countdown
						LCD_command(0x01);//clearing lcd
						LCD_command(0x02);					//returing cursor to its initial position
					break;
					
					
					case('B'):
						LCD_String("Beef weight:");
					while (keypad_getkey() == 0xFF){};
					weight = keypad_getkey(); // read the keypad 
						LCD_Write_Char(weight);
						while (sw_Input() != 0x10 || sw3_Input()==1){}; 
						beef_cooking(weight);
						break;
					
		
					case('C'):
						LCD_String("chicken weight:");
					while (keypad_getkey() == 0xFF){};
					weight = keypad_getkey();// read the keypad 
								 LCD_Write_Char(weight);
					while (sw_Input() != 0x10 || sw3_Input()==1){}; 
						chicken_cooking(weight);
							break;
					
					case('D'):
						while (sw3_Input()==1){};
						mystate=cooking_time();
        break;
						
		
	}
				break;
					
					
				
			
						
			
					case (finish):	
					
						LCD_String("done");
				for( f=0 ; f<3 ; f++){
		Buzzer_ON ();
		Blink();	
		}
			mystate = idle;	
		break;
}
	
}}
