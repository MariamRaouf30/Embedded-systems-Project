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
void beef_cooking(unsigned char weight){ 
		
		
		if(weight== 'A'||weight=='B'||weight=='C'||weight=='D'||weight=='*'||weight=='#'||weight=='0'){
		LCD_command(0x01);//clearing lcd
		LCD_String("Err");
		delayMs(2000);
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
		}
		else{
		// int x = (int)weight * 30000;
//			char w[] = {weight};
			int x = weight -48;
			x=x*30;
			minutes = x/60;
			seconds = x-(minutes *60);
      mystate=countdown( minutes,  seconds);
			
		 //mystate = print_time(x*30 );//printing countdown	
		}
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
		
      
	}

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
			LCD_String ("Beef");
			delayMs(2000);//delay 2 seconds
			LCD_command(0x01);//clearing lcd
	 		LCD_command(0x02);//returing cursor to its initial position
	 break;

	 case ('C'):
			LCD_String ("chicken");
			delayMs(2000);//delay 2 seconds
			LCD_command(0x01);//clearing lcd
	 		LCD_command(0x02);//returing cursor to its initial position
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

enum States countdown(int min, int sec){
	
while (min != -1){
				RGB_Output(0x0E);
	      LCD_Display(min,sec);//displays minutes and secondes on lcd
							delayMs(290);
                 sec--;
	         while(sw3_Input()==1){ Blink();}//While door open pause
			while(1){
				while(sw_Input()==0x01){//switch 1 pressed for 1st time and pause
					delayMs(3000);
					while(sw_Input()!=0x10){//switch 2 pressed after switch 1 (continue cooking)
						Blink();	
						if(sw_Input()==0x01){//switch 1 pressed for 2nd time clear lcd
						LCD_command(0x01);
						LCD_String("lcd clear!");
						delayMs(500);
						LCD_command(0x01);
						return idle;
						
						}
					}
				}	
				break;
			}
                 if(sec == -1){
                     min--;
                     sec = 59;
									 	
                 }
             }
return finish;
}
