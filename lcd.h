#define Home             		 0x02          
#define EntryMode            0x06          
#define DisplayOff           0x08 
#define shiftDisplayRight    0x1C
#define shiftDisplayLeft     0x18
#define DisplayOn            0x0F 
#define cursorOff            0x0C
#define cursorOn             0x0E
#define Reset                0x30          
#define Set8bitFunction      0x38          
#define FirstRow             0x80                   
#define SecondRow            0xC0  

void LCD_command(unsigned char command);
void LCD_Write_Char(unsigned char data);
void PortB_Init(void);
void PortE_Init (void);
void LCD_init(void);
void LCD_String(char  *str);
void LCD_SendString(char *data);
void LCD_setcursorRowCol(unsigned int row, unsigned int col);
void LCD_Display(int minutes, int seconds);
enum States countdown(int min, int sec);
void LCD_Clear_screen(void);
void LCD_goto_position(unsigned char  row,unsigned char col);
