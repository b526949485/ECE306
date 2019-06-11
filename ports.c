/*SHUAI WANG 04/02/2016*/

//=========================================================================== 
// File Name : ports.c 
//
//  Description: This file contains the Initialization for all port pins
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 


#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"



void Init_Ports(){   

Init_Port1(); // This funciton will initialize all pins in port1
Init_Port2(); // This funciton will initialize all pins in port2
Init_Port3(); // This funciton will initialize all pins in port3
Init_Port4(); // This funciton will initialize all pins in port4
Init_PortJ();



}

void Init_Port1(void){
//------------------------------------------------------------------------------
//Configure Port 1
//------------------------------------------------------------------------------
  P1SEL0 = SET_ZERO;         // P1 Port Pins as I/O
  P1SEL1 = SET_ZERO;         // P1 Port Pins as I/O
  P1DIR = SET_ZERO;          // P1 Port Pins all set default to inputs

  
  
// Port P1.0
  P1SEL0 |= V_DETECT_R;       // V_DETECT_R selecte
  P1SEL1 |= V_DETECT_R;       // V_DETECT_R selecte
 

// Port P1.1
  P1SEL0 |= V_DETECT_L;       // V_DETECT_L selecte
  P1SEL1 |= V_DETECT_L;       // V_DETECT_L selecte


// Port P1.2
  P1SEL0 &= ~IR_LED;       // IR_LED GPI/O selected
  P1SEL1 &= ~IR_LED;       // IR_LED GPI/O selected
  P1OUT  &= ~IR_LED;        // P1 IR_LED Port Pin set low 
  P1DIR  |= IR_LED;        // Set P1 IR_LED direction to output

  
// Port P1.3
  P1SEL0 |= V_THUMB;       // V_THUMB selected
  P1SEL1 |= V_THUMB;       // V_THUMB selected


// Port P1.4
  P1SEL0 &= ~SPI_CS_LCD;       // SPI_CS_LCD GPI/O selected
  P1SEL1 &= ~SPI_CS_LCD;       // SPI_CS_LCD GPI/O selected
  P1OUT  |= SPI_CS_LCD;        // P1 SPI_CS_LCD Port Pin set high
  P1DIR  |= SPI_CS_LCD;        // Set RESET_LCD output direction

  
// Port P1.5
  P1SEL0 &= ~RESET_LCD;       // RESET_LCD GPI/O selected
  P1SEL1 &= ~RESET_LCD;       // RESET_LCD GPI/O selected
  P1OUT  &= ~RESET_LCD;        // RESET_LCD Port Pin set low 
  P1DIR  |= RESET_LCD;       // Set RESET_LCD output direction

  
// Port P1.6
  P1SEL0 &= ~SIMO_B;       //SIMO_B selected
  P1SEL1 |= SIMO_B;       // SIMO_B selected
  P1DIR  |= SIMO_B;        // SIMO_B set to Output

// Port P1.7
  P1SEL0 &= ~SOMI_B;       // SOMI_B is used on the LCD
  P1SEL1 |= SOMI_B;       // SOMI_B is used on the LCD
  P1DIR  &= ~SOMI_B;        // SOMI_B set to Input
  P1REN  |= SOMI_B;        // Enable pullup resistor

//------------------------------------------------------------------------------
}

void Init_Port2(void){
//------------------------------------------------------------------------------
//Configure Port 2
//------------------------------------------------------------------------------
  P2SEL0 = SET_ZERO;         // P2 Port Pins as I/O
  P2SEL1 = SET_ZERO;         // P2 Port Pins as I/O
  P2DIR = SET_ZERO;          // P2 Port Pins all set default to inputs
  
// Port P2.0
  P2SEL0 &= ~USB_TXD;       // USB_TXD selected
  P2SEL1 |= USB_TXD;       // USB_TXD selected
  P2OUT  &= ~USB_TXD;       //USB_TXD Port Pin set LOW
  P2DIR  |= USB_TXD;        // USB_TXD direction to output

// Port P2.1
  P2SEL0 &= ~USB_RXD;       // USB_RXD selected
  P2SEL1 |= USB_RXD;       // USB_RXD selected
  P2DIR  &= ~USB_RXD;        // USB_RXD direction to output

// Port P2.2
  P2SEL0 &= ~SPI_SCK;       // SPI_SCK selected
  P2SEL1 |= SPI_SCK;       // SPI_SCK selected
  P2OUT  |= SPI_SCK;        // SPI_SCK Port Pin set HIGH
  P2DIR |= SPI_SCK;
   
// Port P2.3
  P2SEL0 &= ~UNK3;       // UNK3 selected
  P2SEL1 &= ~UNK3;       // UNK3 selected
  P2DIR &= ~UNK3;
  P2OUT &= ~UNK3; 
  P2REN  &= ~UNK3;       //UNK3 Enable pulldown resistor
  
// Port P2.4
  P2SEL0 &= ~UNK4;       // UNK4 selected
  P2SEL1 &= ~UNK4;       // UNK4 selected
  P2DIR  &= ~UNK4;
  P2REN  &= ~UNK4;      // UNK4 Enable pulldown resistor
  
// Port P2.5
  P2SEL0 &= ~CPU_TXD;       // CPU_TXD selected
  P2SEL1 |= CPU_TXD;       // CPU_TXD selected
  P2DIR  |= CPU_TXD;        // CPU_TXD direction to output

// Port P2.6
  P2SEL0 &= ~CPU_RXD;       // CPU_RXD selected
  P2SEL1 |= CPU_RXD;       // CPU_RXD selected
  P2DIR  &= ~CPU_RXD;        // CPU_RXD direction to output

// Port P2.7
  P2SEL0 &= ~UNK7;       // UNK7 selected
  P2SEL1 &= ~UNK7;       // UNK7 selected
  P2DIR &= ~UNK7;
  P2REN  &= ~UNK7;       // UNK7 Enable pulldown resistor
//------------------------------------------------------------------------------
}


void Init_Port3(void){
//------------------------------------------------------------------------------
//Configure Port 3
//------------------------------------------------------------------------------
  P3SEL0 = SET_ZERO;         // P3 Port Pins as I/O
  P3SEL1 = SET_ZERO;         // P3 Port Pins as I/O
  P3DIR = SET_ZERO;          // P3 Port Pins all set default to inputs
  P3OUT = SET_ZERO;
  
// Port P3.0
  P3SEL0 &= ~X;       // X selected
  P3SEL1 &= ~X;       // X selected
  P3DIR &= ~X; // Set P3 Pin 0 direction to input
  P3REN &= ~X;
  P3OUT &= ~X;
  

// Port P3.1
  P3SEL0 &= ~Y;       // Y selected
  P3SEL1 &= ~Y;       // Y selected
  P3DIR &= ~Y;
  P3REN  &= ~Y;        // Y Enable pulldown resistor

// Port P3.2
  P3SEL0 &= ~Z1;       // Z1 selected
  P3SEL1 &= ~Z1;       // Z1 selected
  P3DIR  &= ~Z1;
  P3REN  &= ~Z1;        // Z1 Enable pulldwon resistor

// Port P3.3
  P3SEL0 &= ~LCD_BACKLITE;       // LCD_BACKLITE selected
  P3SEL1 &= ~LCD_BACKLITE;       // LCD_BACKLITE selected
  P3DIR  |= LCD_BACKLITE;        // LCD_BACKLITE direction to output

// Port P3.4
  P3SEL0 &= ~R_FORWARD;       // R_FORWARD selected
  P3SEL1 &= ~R_FORWARD;       // R_FORWARD selected
  P3OUT  &= ~R_FORWARD;        // R_FORWARD Port Pin set LOW
  P3DIR  |= R_FORWARD;        //R_FORWARD direction to output

// Port P3.5
  P3SEL0 &= ~R_REVERSE;       // R_REVERSE selected
  P3SEL1 &= ~R_REVERSE;       // R_REVERSE selected
  P3OUT  &= ~R_REVERSE;        // R_REVERSE Port Pin set LOW
  P3DIR  |= R_REVERSE;        // R_REVERSE direction to output

// Port P3.6
  P3SEL0 &= ~L_FORWARD;       // L_FORWARD selected
  P3SEL1 &= ~L_FORWARD;       // L_FORWARD selected
  P3OUT  &= ~L_FORWARD;        // L_FORWARD Port Pin set LOW
  P3DIR  |= L_FORWARD;        // L_FORWARD direction to output
  
// Port P3.7
  P3SEL0 &= ~L_REVERSE;       // L_REVERSE selected
  P3SEL1 &= ~L_REVERSE;       // L_REVERSE selected
  P3OUT  &= ~L_REVERSE;        // L_REVERSE Port Pin set LOW
  P3DIR  |= L_REVERSE;        // L_REVERSE direction to output


//------------------------------------------------------------------------------
}


void Init_Port4(void){
//------------------------------------------------------------------------------
//Configure Port 4
//------------------------------------------------------------------------------
  P4SEL0 = SET_ZERO;         // P4 Port Pins as I/O
  P4SEL1 = SET_ZERO;         // P4 Port Pins as I/O
  P4DIR = SET_ZERO;          // P4 Port Pins all set default to inputs
  P4OUT = SET_ZERO;          // P4 Port Pins all set default to low
  
// Port P4.0
  P4SEL0 &= ~SW1;       // SW1 selected
  P4SEL1 &= ~SW1;       // SW1 selected
  P4DIR  &= ~SW1;
  P4OUT  |= SW1;        // SW1 Port Pin set HIGH
  P4REN  |= SW1;        // SW1 Enable pullup resistor
  P4IES  |= SW1;        // SW1 Hi/Lo edge interrupt 
  P4IFG  &= ~SW1;       // SW1 flg sw1 clear
  P4IE   |= SW1;        // SW1 interrupt Enabled 
// Port P4.1
  P4SEL0 &= ~SW2;       // SW2 selected
  P4SEL1 &= ~SW2;       // SW2 selected
  P4DIR  &= ~SW2;
  P4OUT  |= SW2;        // SW2 Port Pin set HIGH
  P4REN  |= SW2;        // SW2 Enable pullup resistor
  P4IES  |= SW2;        // SW2 Hi/Lo edge interrupt 
  P4IFG  &= ~SW2;       // SW2 flg  clear
  P4IE   |= SW2;        // SW2 interrupt Enabled 

  
//------------------------------------------------------------------------------
}

//------------------------------------------------------------------------------
//Init_PortJ
//Purpose: Initialize PortJ
//
//Various options for Pin 0 
// SEL0 SEL1 DIR
// 0    0    I:0 O:1   - *General-Purpose digital I/O with port interrupt and wake up from LPMx.5
// x    x    x         - TDO
// 1    0    0         - TB0OUTH
// 1    0    1         - SMCLK
// 1    1    x         - CD6

//Various options for Pin 1 
// SEL0 SEL1 DIR
// 0    0    I:0 O:1   - *General-Purpose digital I/O with port interrupt and wake up from LPMx.5
// x    x    x         - TDI
// 1    0    0         - TB1OUTH
// 1    0    1         - MCLK
// 1    1    x         - CD7

//Various options for Pin 2
// SEL0 SEL1 DIR
// 0    0    I:0 O:1   - *General-Purpose digital I/O with port interrupt and wake up from LPMx.5
// x    x    x         - TMS
// 1    0    0         - TB2OUTH
// 1    0    1         - ACLK
// 1    1    x         - CD8

//Various options for Pin 3 
// SEL0 SEL1 DIR
// 0    0    I:0 O:1   - *General-Purpose digital I/O with port interrupt and wake up from LPMx.5
// x    x    x         - TCK
// 1    1    x         - CD9
// 
//Passed : char clock_iot
//Locals : No local variables
//Returned : No values returned

//Author: Shuai Wang
//Date: Feb 2016
//Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1)
//version: 1.0
//------------------------------------------------------------------------------

void Init_PortJ(){
//------------------------------------------------------------------------------
//Configure Port J
//------------------------------------------------------------------------------
  PJSEL0 = SET_ZERO;         // PJ Port Pins as I/O
  PJSEL1 = SET_ZERO;         // PJ Port Pins as I/O
  PJDIR = SET_ZERO;          // PJ Port Pins all set default to inputs
  
// Port PJ.0
  
 
      PJSEL0 &= ~IOT_WAKEUP;       // IOT_WAKEUP selected
      PJSEL1 &= ~IOT_WAKEUP;       // IOT_WAKEUP selected
      PJOUT  &= ~IOT_WAKEUP;        // IOT_WAKEUP Port Pin set LOW
      PJDIR  |= IOT_WAKEUP;        // IOT_WAKEUP direction to output



// Port PJ.1
  PJSEL0 &= ~IOT_FACTORY;       // IOT_FACTORY selected
  PJSEL1 &= ~IOT_FACTORY;       // IOT_FACTORY selected
  PJOUT  &= ~IOT_FACTORY;        // IOT_FACTORY Port Pin set LOW
  PJDIR  |= IOT_FACTORY;        // IOT_FACTORY direction to output

// Port PJ.2
  PJSEL0 &= ~IOT_STA_MINIAP;       // IOT_STA_MINIAP selected
  PJSEL1 &= ~IOT_STA_MINIAP;       // IOT_STA_MINIAP selected
  PJOUT  |= IOT_STA_MINIAP;        // IOT_STA_MINIAP Port Pin set High
  PJDIR  |= IOT_STA_MINIAP;        // IOT_STA_MINIAP direction to output

// Port PJ.3
  PJSEL0 &= ~IOT_RESET;       // IOT_RESET selected
  PJSEL1 &= ~IOT_RESET;       // IOT_RESET selected
  PJOUT  &= ~IOT_RESET;        // IOT_RESET Port Pin set HIGH
  PJDIR  |= IOT_RESET;        // IOT_RESET direction to output


//------------------------------------------------------------------------------
}
