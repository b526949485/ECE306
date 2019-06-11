/*SHUAI WANG 02/25/2016*/


//=========================================================================== 
// File Name : timers.c 
//
//  Description: This file contains the Initialization for all timers.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern volatile char one_time;
extern volatile int five_ms_count;
extern volatile unsigned int Time_Sequence;
void Init_Timers(void){
//------------------------------------------------------------------------------
// Timer Configurations
//------------------------------------------------------------------------------
  Init_Timer_A0(); //
//  Init_Timer_A1(); // 
//  Init_Timer_B0(); // 
  Init_Timer_B1(); // 
  Init_Timer_B2();   //  Required for provided compiled code to work
//------------------------------------------------------------------------------
}


void Five_msec_Delay(int i){
    five_ms_count=SET_ZERO;
    while(five_ms_count<=i){};     }



void Timer_code(void){
//------------------------------------------------------------------------------
// Timer A0 interrupt code
//------------------------------------------------------------------------------
  Time_Sequence++;
  one_time = TRUE;
  if (five_ms_count < FIVE_S_COUNT_1000){
    five_ms_count++;
  }
//------------------------------------------------------------------------------
}