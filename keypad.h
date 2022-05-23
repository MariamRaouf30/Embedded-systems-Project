#include "tm4c123gh6pm.h"
#include "delays.h"

/* Defines the size of rows and columns of keypad */
#define  RowsSize  4
#define  ColsSize  4

																						
																								
void keypad_Init(void);

/* keypad_getkey() function returns the value of key pressed by the user by traversing columns
and rows respectivley */
unsigned char keypad_getkey(void);
