/*SHUAI WANG 04/02/2016*/


//=========================================================================== 
// File Name : init.c 
//
//  Description: This file contains the Initialization for init_Conditions.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 


#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


extern char display_line_1[ELEVEN];
extern char display_line_2[ELEVEN];
extern char display_line_3[ELEVEN];
extern char display_line_4[ELEVEN];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;

void Init_Conditions(void){
//------------------------------------------------------------------------------
// Initializations Configurations
//------------------------------------------------------------------------------
// Interrupts are disabled by default, enable them. 
  enable_interrupts();
  display_1 = &display_line_1[SET_ZERO];
  display_2 = &display_line_2[SET_ZERO];
  display_3 = &display_line_3[SET_ZERO];
  display_4 = &display_line_4[SET_ZERO];

//------------------------------------------------------------------------------
}