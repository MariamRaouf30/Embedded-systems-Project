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
void SysTick_Init(void);
void SysTick_wait1s(void);
enum States {idle, prep, cooking, finish} mystate;
enum States print_time(uint8_t time);
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


//calling functions that we used 

void SW3_Init(void);
unsigned sw3_Input(void);


int8_t i;
