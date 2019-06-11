//******************************************************************************
//
//  Description: This file contains the IOT command move function that make the movement
//  Shuai Wang
//  March 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"
#include  <string.h>


//******************************************************************************
//
//  Description: This function is to convert and transmit the string command to IOT.
//  Passed: string[]
//  Locals: i
//  Returned: no variables returned.
//  Globals: no variables globals.
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************


void IOT_command(char* string){
  int i=SET_ZERO;
//display the command  
  while(string[i]!='\0'){
     transmit_A0(string[i]);
     i++;
        }
  transmit_A0(LINEFEED);
  i=SET_ZERO;
//response from IOT  
  while(string[i]!='\0'){
     transmit_A1(string[i]);
     i++;
        }
  //   slow_baudrate_iot_command[j]=ENTER;
  transmit_A1(ENTER);
}



