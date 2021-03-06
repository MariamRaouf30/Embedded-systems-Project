#define NVIC_ST_CTRL_R          (*((volatile unsigned long *)0xE000E010))
#define NVIC_ST_RELOAD_R        (*((volatile unsigned long *)0xE000E014))
#define NVIC_ST_CURRENT_R       (*((volatile unsigned long *)0xE000E018))

void start_reading(unsigned char key);
void beefchicken_cooking(unsigned char weight);
void SysTick_Init(void);
void SysTick_wait1s(void);
enum States {idle, prep, cooking, paused, finish} mystate;
enum States print_time(uint8_t time);
unsigned char button_in;
unsigned char door_button;
unsigned char key;
unsigned char weight;

