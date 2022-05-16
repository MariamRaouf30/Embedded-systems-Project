#define KEYPAD_ROW GPIOE
#define KEYPAD_COL GPIOC
void keypad_init(void);
unsigned char keypad_getkey(void);
unsigned char keypad_kbhit(void);
