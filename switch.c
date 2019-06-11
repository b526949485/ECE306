/*SHUAI WANG 04/02/2016*/

//=========================================================================== 
// File Name : switch.c 
//
//  Description: This file contains the functions for switch.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern int SW_SET1;


/*void Switches_Process(void){
//------------------------------------------------------------------------------
if (!(P4IN & SW1))
 
if (!(P4IN & SW2)) 
  
//------------------------------------------------------------------------------
}*/