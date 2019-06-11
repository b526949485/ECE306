// Function prototypes main
void main(void);
void Init_Conditions(void);
void Switches_Process(void);
void Init_Timers(void);
void Init_LEDs(void);
void Display_Process(void);
void Timer_code(void);
void Five_msec_Delay(int i);

// Function prototypes clocks
void Init_Clocks(void);

// Function prototypes systems
void enable_interrupts(void);

// Function prototypes
__interrupt void Timer2_B0_ISR(void);
__interrupt void TIMER2_B1_ISR(void);
void Init_Timer_A0(void);
void Init_Timer_B1(void);
void Init_Timer_B2(void);
void measure_delay(void);
void usleep10(unsigned int usec );

// Function prototypes ports
void Init_Ports(void);
void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Port4(void);
void Init_PortJ(void);

// LCD
void Init_LCD(void);
void WriteIns(char instruction);
void WriteData(char data);
void ClrDisplay(void);
void SetPostion(char pos);
void DisplayOnOff(char data);
void lcd_BIG_mid(void);
void lcd_4line(void);
void lcd_out(char *s, char line, char position);

void grab_a_character(void);
int wait_for_character(void);
void menu(void);

// SPI
void Init_SPI_B0(void);
void SPI_B0_write(char byte);

// Switches
void Init_Switches(void);
void switch_control(void);
void enable_switch_SW1(void);
void enable_switch_SW2(void);
void disable_switch_SW1(void);
void disable_switch_SW2(void);
void Switches_Process(void);

//Wheel Move
void Left_Forward_On(void);
void Left_Forward_Off(void);
void Left_Reverse_On(void);
void Left_Reverse_Off(void);
void Right_Forward_On(void);
void Right_Forward_Off(void);
void Right_Reverse_On(void);
void Right_Reverse_Off(void);
void Wheel_Off(void);
void F_R_Check(void);

//Project 3 
void Move_Circle(void);
void Move_Eight(void);
void Move_Trangle(void);
void First_Menu(void);
void Eight_Turn(void);
void Trangle_Straight(void);
void Trangle_Turn(void);

//Project 5
void Init_ADC(void);
__interrupt void ADC10_ISR(void);
void ADC_Process(void);
void HEXtoBCD(char string[],int hex_value);
void ADC_LCD_STATE(void);
void Movement(void);

void Wheel_Speed(int speed);

void dir_right(int dir);
void dir_left(int dir);

//Project 6
void transmit_A1(char i);
void transmit_A0(char i);
__interrupt void USCI_A1_ISR(void);
__interrupt void USCI_A0_ISR(void);
void Init_Serial_UCA1(void);
void Init_Serial_UCA0(void);

//Porject 7
void IOT_command(char* string);
void clear_string(char string[]);
void movement(char* string);
int BCDtoHEX(char string[]);

//project 8
void movement_dota(char* string);
void PWM_Wheel_Off(void);
void Black_Line(void);
