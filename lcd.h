#define LCD_DATA GPIOB
#define LCD_CTRL GPIOA
#define RS 0x20 /* PORTA BIT5 mask */
#define RW 0x40 /* PORTA BIT6 mask */
#define EN 0x80 /* PORTA BIT7 mask */
void LCD_command(unsigned char command);
void LCD_data(unsigned char data);
void LCD_init(void);
void LCD_Write_Nibble(unsigned char data, unsigned char control);
void LCD_Write_Char(unsigned char data);
void LCD_String (char *str);
void LCD_setcursorRowCol(unsigned int row, unsigned int col);
void LCD_Display(int minutes, int seconds);
void countdown(int min, int sec);