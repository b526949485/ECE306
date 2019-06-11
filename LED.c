/*SHUAI WANG 04/02/2016*/


//=========================================================================== 
// File Name : LED.c 
//
//  Description: This file contains the Initialization for all LEDs.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;

void Init_LEDs(void){
//------------------------------------------------------------------------------
// LED Configurations
//------------------------------------------------------------------------------
// Turns on all 8 LEDs
  PJOUT &= ~IOT_WAKEUP;
  PJOUT &= ~IOT_FACTORY;
  PJOUT &= ~IOT_STA_MINIAP;
  PJOUT &= ~IOT_RESET;

//------------------------------------------------------------------------------
}

void Display_Process(void){
  ClrDisplay();
  lcd_out(display_1, LCD_HOME_L1, posL1);
  lcd_out(display_2, LCD_HOME_L2, posL2);
  lcd_out(display_3, LCD_HOME_L3, posL3);
  lcd_out(display_4, LCD_HOME_L4, posL4);
}
