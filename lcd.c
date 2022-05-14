#include "TM4C123.h"
#include "Io.h"
#include "delays.h"
#include "lcd.h"


void LCD_command(unsigned char command)
{
LCD_CTRL->DATA = 0; /* RS = 0, R/W = 0 */
LCD_DATA->DATA = command;


LCD_CTRL->DATA = EN; /* pulse E */
delayUs(0);
LCD_CTRL->DATA = 0;
if (command < 4) delayMs(2); /* command 1 and 2 needs up to 1.64ms */ else delayUs(40); /* all others 40 us */ }

void LCD_data(unsigned char data) { LCD_CTRL->DATA = RS; /* RS = 1, R/W = 0 */
LCD_DATA->DATA = data;
LCD_CTRL->DATA = EN | RS; /* pulse E */
delayUs(0);
LCD_CTRL->DATA = 0;
delayUs(40);
}


void LCD_init(void)
{
SYSCTL->RCGCGPIO |= 0x01; /* enable clock to GPIOA */
SYSCTL->RCGCGPIO |= 0x02; /* enable clock to GPIOB */
 
LCD_CTRL->DIR |= 0xE0; /* set PORTA pin 7-5 as output for control */
LCD_CTRL->DEN |= 0xE0; /* set PORTA pin 7-5 as digital pins */
LCD_DATA->DIR = 0xFF; /* set all PORTB pins as output for data */
LCD_DATA->DEN = 0xFF; /* set all PORTB pins as digital pins */
 
delayMs(20); /* initialization sequence */
LCD_command(0x30);
delayMs(5);
LCD_command(0x30);
delayUs(100);
LCD_command(0x30);
 
LCD_command(0x38); /* set 8-bit data, 2-line, 5x7 font */
LCD_command(0x06); /* move cursor right */
LCD_command(0x01); /* clear screen, move cursor to home */
LCD_command(0x0F); /* turn on display, cursor blinking */
}
 

void LCD_Write_Nibble(unsigned char data, unsigned char control)
{

    data &= 0xF0;       /* Extract upper nibble for data */
    control &= 0x0F;    /* Extract lower nibble for control */
    LCD_DATA->DATA = data | control;       /* Set RS and R/W to zero for write operation */
    LCD_DATA->DATA = data | control | EN;  /* Provide Pulse to Enable pin to perform wite operation */
    delayUs(0);
    LCD_DATA->DATA = data; /*Send data */
    LCD_DATA->DATA = 0; /* stop writing data to LCD */
}
 void LCD_Write_Char(unsigned char data)
{
    LCD_Write_Nibble(data & 0xF0, RS);    /* Write upper nibble to LCD and RS = 1 to write data */
    LCD_Write_Nibble(data << 4, RS);      /* Write lower nibble to LCD and RS = 1 to write data */
    delayUs(40);
}
void LCD_String (char *str)	/* Send string to LCD function */
{
	int i;
	for(i=0;str[i]!=0;i++)  /* Send each char of string till the NULL */
	{
		LCD_Write_Char(str[i]);  /* Call LCD data write */
	}
}


void LCD_setcursorRowCol(unsigned int row, unsigned int col){
  int command = 0x00;
  if( row == 0)
  {
    command = 0x80;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
    if( row == 1)
  {
    command = 0xC0;
    while(col <=  0x0F && col >= 0x00)
    {
      LCD_command(command + col);
      break;
    }
  }
}

 void LCD_Display(int minutes, int seconds){
    LCD_setcursorRowCol(1,0);
    LCD_Write_Char(minutes);
    LCD_setcursorRowCol(1,2);
    LCD_String(":");
    LCD_setcursorRowCol(1,3);
    LCD_Write_Char (seconds);
 }
 //countdown function
void countdown(int min, int sec){
while (min != -1){
                 LCD_Display(min,sec);
                 sec--;
                 if(sec == -1){
                     min--;
                     sec = 59;
                 }
             }
}
//function below to set cursor to write in 16x2 lcd

