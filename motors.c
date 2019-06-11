/*SHUAI WANG 02/14/2016*/

//=========================================================================== 
// File Name : motors.c 
//
//  Description: This file contains the function for turnning on and turnning off the wheels.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern int right_forward_rate;
extern int right_reverse_rate;
extern int left_forward_rate;
extern int left_reverse_rate;

//left_forward_on

void Left_Forward_On(void){
  if(!(P3IN & L_FORWARD)){
    Left_Reverse_Off();
    P3OUT |= L_FORWARD;
  }
}

//left_forward_off
void Left_Forward_Off(void){
  P3OUT &= ~L_FORWARD;
}

//left_reverse_on
void Left_Reverse_On(void){
  if(!(P3IN & L_REVERSE)){
    Left_Forward_Off();
    P3OUT |= L_REVERSE;
  }
}

//left_reverse_off
void Left_Reverse_Off(void){
  P3OUT &= ~L_REVERSE;
}

//right_forward_on
void Right_Forward_On(void){
  if(!(P3IN & R_FORWARD)){
    Right_Reverse_Off();
    P3OUT |= R_FORWARD;
  }
}

//right_forward_off
void Right_Forward_Off(void){
  P3OUT &= ~R_FORWARD;
}

//right_reverse_on
void Right_Reverse_On(void){
  if(!(P3IN & R_REVERSE)){
    Right_Forward_Off();
    P3OUT |= R_REVERSE;
  }
}

//right_reverse_off
void Right_Reverse_Off(void){
  P3OUT &= ~R_REVERSE;
}

//all wheel off
void Wheel_Off(void){
 P3OUT &= ~(L_FORWARD | L_REVERSE | R_FORWARD | R_REVERSE);
}

//PWM wheel off
void PWM_Wheel_Off(void){
 P3SEL0 &= ~(L_FORWARD | L_REVERSE | R_FORWARD | R_REVERSE);
}

//Wheel speed
void Wheel_Speed(int speed){
 right_forward_rate=speed;
 right_reverse_rate=speed;
 left_forward_rate=speed;
 left_reverse_rate=speed;
}


//PWM Wheel right
void dir_right(int dir){
  if(dir){
    P3SEL0 &= ~R_REVERSE;
    P3SEL0 |= R_FORWARD;
  }
  else{
    P3SEL0 &= ~R_FORWARD;
    P3SEL0 |= R_REVERSE; 
  }

}

//PWM wheel left
void dir_left(int dir){
  if(dir){
    P3SEL0 &= ~L_REVERSE;
    P3SEL0 |= L_FORWARD;
  }
  else{
    P3SEL0 &= ~L_FORWARD;
    P3SEL0 |= L_REVERSE; 
  }

}