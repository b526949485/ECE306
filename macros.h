/*SHUAI WANG 04/02/2016*/

#ifndef MACROS
#define MACROS

#define SET_ZERO (0x00)

#define PIN0 (0x01)
#define PIN1 (0x02)
#define PIN2 (0x04)
#define PIN3 (0x08)
#define PIN4 (0x10)
#define PIN5 (0x20)
#define PIN6 (0x40)
#define PIN7 (0x80)




// Port 1 pins
#define V_DETECT_R (PIN0)
#define V_DETECT_L (PIN1)
#define IR_LED (PIN2)
#define V_THUMB (PIN3)
#define SPI_CS_LCD (PIN4)
#define RESET_LCD (PIN5)
#define SIMO_B (PIN6)
#define SOMI_B (PIN7)

//Port 2 pins
#define USB_TXD (PIN0)
#define USB_RXD (PIN1)
#define SPI_SCK (PIN2)
#define UNK3 (PIN3)
#define UNK4 (PIN4)
#define CPU_TXD (PIN5)
#define CPU_RXD (PIN6)
#define UNK7 (PIN7)

//Port 3 pins
#define X (PIN0)
#define Y (PIN1)
#define Z1 (PIN2)
#define LCD_BACKLITE (PIN3)
#define R_FORWARD (PIN4)
#define R_REVERSE (PIN5)
#define L_FORWARD (PIN6)
#define L_REVERSE (PIN7)


//Port J pins
#define IOT_WAKEUP (PIN0)
#define IOT_FACTORY (PIN1)
#define IOT_STA_MINIAP (PIN2)
#define IOT_RESET (PIN3)





// Required defines
// In the event the universe no longer exists, this bit will reset
#define ALWAYS                  (1)
#define CNTL_STATE_INDEX        (3) // Control States
#define SW1                  (0x01) // Switch 1
#define SW2                  (0x02) // Switch 2
#define CNTL_STATE_INDEX        (3)
// LCD
#define LCD_HOME_L1	          0x80
#define LCD_HOME_L2         	0xA0
#define LCD_HOME_L3         	0xC0
#define LCD_HOME_L4         	0xE0

#define TRUE (1)
#define FALSE (0)
#define COUNT_600 (600)
#define COUNT_550 (550)
#define COUNT_500 (500)
#define COUNT_400 (400)
#define COUNT_250 (250)
#define COUNT_300 (300)
#define COUNT_200 (200)
#define COUNT_150 (150)
#define COUNT_100 (100)
#define COUNT_50 (50)
#define COUNT_40 (40)
#define COUNT_20 (20)
#define COUNT_30 (30)
#define COUNT_13 (13)
#define COUNT_15 (15)
#define COUNT_1000 (1000)
#define COUNT_1500 (1500)
#define COUNT_1800 (1800)
#define COUNT_2000 (2000)
#define COUNT_3000 (3000)
#define COUNT_4000 (4000)
#define COUNT_6000 (6000)
#define COUNT_5000 (5000)
#define COUNT_8000 (8000)
#define COUNT_10000 (10000)
#define COUNT_9999 (9999)
#define COUNT_999 (999)
#define COUNT_99 (99)
#define SIZECOUNT (5)
#define SW_ZERO (0)
#define SW_ONE (1)
#define SW_TWO (2)
#define SW_THREE (3)
#define THE_ONE (1)
#define FIVE_S_COUNT_1000 (1000)
#define LENGTH_ELEVEN (11)
#define DELAY (100)
#define ELEVEN (11)
#define NEG_ONE (-1)


//Homework_06
#define TA0CCR0_INTERVAL      (2500) //(2500) // 8,000,000 / 8 / 2 / 25000 = 200Hz => 5msec
#define TA0CCR1_INTERVAL       (25000)
#define TA0CCR2_INTERVAL       (2500)
extern volatile int five_ms_count;
extern volatile int five_ms_blink;
#define DEBOUNCE_COUNT_TIME (200)
#define DEBOUNCE_COUNT_SW (105)

//Project 4
#define ZERO_COUNT (0)
#define ONE_COUNT (1)
#define TWO_COUNT (2)
#define THREE_COUNT (3)
#define FOUR_COUNT (4)
#define FIVE_COUNT (5)
#define SIX_COUNT (6)
#define SEVEN_COUNT (7)
#define EIGHT_COUNT (8)
#define NINE_COUNT (9)
#define TEN_COUNT (10)
#define ELEVEN_COUNT (11)
#define END_COUNT (12)


//Project 5
#define QUARTER_SEC (50)
#define ASCII_0 (0x30)
#define FORWARD (1)
#define REVERSE (-1)

//PWM
#define WHEEL_PERIOD (8000)


//serial communication
#define baud_9600_BRW   (52)
#define baud_9600_MCTLW  (0x4911)
#define baud_115200_BRW  (4)
#define baud_115200_MCTLW (0x5551)
#define BEGINNING (0)
#define SMALL_RING_SIZE (8)
#define LARGE_RING_SIZE  (32)
#define Vector_0    (0)
#define Vector_2    (2)
#define Vector_4    (4)
#define zero        (0)
#define NUMBER_RING_SIZE (6)

#define ENTER (0x0D)
#define LINEFEED (0x0A)
#define BCD_ZERO (0x30)

#define IPADD_START (22)
#define IPADD_END (23)


#endif