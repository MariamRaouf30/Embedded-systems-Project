//Displays character pressed on keypad on LCD
#include "TM4C123.h"
#include "stdio.h"
#include "Io.h"
#include "delays.h"
#include "keypad.h"
#include "lcd.h"
#include "switches.h"
#include "operations.h"




//calling functions that we used 
void print_time(uint8_t time);
void SW3_Init();
unsigned sw3_Input();

	



int start_operation(void)
{
	unsigned char button_in;
	unsigned char door_button;
unsigned char key;
unsigned char weight; 	
	button_in = sw_Input();
	door_button = sw3_Input();
	
		SW1_Init();
		SW2_Init();
	  SW3_Init();
		
	keypad_init();
	LCD_init();

			



LCD_command(0x80); /* LCD cursor location */
	

 
key = keypad_getkey(); /* read the keypad */

if (key != 0)

{ /* if a key is pressed */
switch (key)
{
  case 'A':

	popcorn: if(door_button!=0x02){
	while(1){
			LCD_String("Popcorn");
			if(button_in == 0x10 ) break;
			}
		 }
		 else{
			 LCD_String("Close Door");
			 goto popcorn;
		 }
		 
		 

		 
		delayMs(2000);//delay 2 seconds
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
	 while(button_in != (button_in & 0x10) ){LCD_String("SW2 to start");}
		 print_time(60);//printing countdown
		
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
      break;
	 
	 case 'B'://miffro -->case B
			LCD_String ("Beef");
			delayMs(2000);//delay 2 seconds
			LCD_command(0x01);//clearing lcd
	 		LCD_command(0x02);//returing cursor to its initial position
	 LCD_String("Beef weight:");
			
			weight = key; /* read the keypad */
		if(weight== 'A'||weight=='B'||weight=='C'||weight=='D'||weight=='*'||weight=='#'){
		LCD_String("Err");
		delayMs(2000);
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
		}
		else{
		// int x = (int)weight * 30000;
		print_time((int)weight*30);//printing countdown	
		}
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
      break;
		case 'C':
			LCD_String ("Chicken");
		delayMs(2000);//delay 2 seconds
		LCD_command(0x01);//clearing lcd
				LCD_command(0x02);//returing cursor to its initial position
		LCD_String("Chicken weight:");
		
			weight = key; /* read the keypad */
		if(weight== 'A'||weight== 'B'||weight== 'C'||weight== 'D'||weight== '*'||weight== '#'){
		LCD_String("Err");
		delayMs(2000);
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
		}
		else{
		// int x = (int) weight * 12000;
		print_time((int)weight*12);//printing countdown	
		}
		LCD_command(0x01);//clearing lcd
		LCD_command(0x02);//returing cursor to its initial position
      break;

//liliane --> case C

}

}
else
LCD_data(' ');

			
delayMs(20); /* wait for a while */

}

 

 

/*----------------------------------------------------------------------------*/



void SysTick_Init(void){ //intialize systick
	NVIC_ST_CTRL_R = 0;
	NVIC_ST_RELOAD_R = 0x00FFFFFF;
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x00000005;

}	

void SysTick_wait1s(){ //1 sec wait
 NVIC_ST_RELOAD_R = 16000000 -1;
 NVIC_ST_CURRENT_R = 0;
 while((NVIC_ST_CTRL_R & 0X0001000)==0){};
}

//void delay(uint32_t time){ // multiples of 1 sec
//uint32_t i;
//	for(i=0; i<time; i++){
//	SysTick_wait1s();
//	}
//}
void SysTick_wait1ms(){ //1m sec wait
 NVIC_ST_RELOAD_R = 16000 -1;
 NVIC_ST_CURRENT_R = 0;
 while((NVIC_ST_CTRL_R & 0X0001000)==0){};
}

void print_time_1ms(uint8_t time){ //interfacing systick with lcd 
	int8_t i;
	for(i = time-1;i>=0;i--){
		LCD_Write_Char((char) i);
		SysTick_wait1ms();
	}
	 LCD_String ("Done");//print done after cooking
}

void print_time(uint8_t time){ //interfacing systick with lcd 
	int8_t i;
	for(i = time-1;i>=0;i--){
		LCD_Write_Char((char) i);
		SysTick_wait1s();
	}
	 LCD_String ("Done");//print done after cooking
}
