/*SHUAI WANG 04/28/2016*/

//=========================================================================== 
// File Name : Movement.c 
//
//  Description: This file contains the movement function.
//
//  Author: Shuai Wang
//  Date: Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern volatile  unsigned int ADC_Right_Detector;
extern volatile  unsigned int ADC_Left_Detector;
extern int blackline_flag;
extern int lastright_flag;
extern int lastleft_flag;
char time[FOUR_COUNT];
int time_s;
extern int movement_count;
extern int blackline_flag;
int back_on_flag;
int turn_model;

//=========================================================================== 
// Function name:  Black_Line
// 
// Description: This function contains the black line dectect and movement depends on the black line detect.
//              
//                
// Passed : no variables passed 
// Locals: no variables declared 
// Returned: no values returned 
// Globals: 
//      ADC_Right_Detector;
//      ADC_Left_Detector;
//      Blackline_flag;
//      lastright_flag;
//      lastleft_flag;
//     
// 
//  Author: SHUAI WANG
//  Date: Apr 2016
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

void Black_Line(void){
     //Right black, Left white, turn right
     if(ADC_Right_Detector>COUNT_500 && ADC_Left_Detector<COUNT_200){ 
      dir_right(SET_ZERO);
      dir_left(TRUE);
      TB1CCR2=COUNT_5000;
      TB2CCR1=COUNT_5000;
      lastright_flag=TRUE;
      lastleft_flag=FALSE;
     }     else 
     //Right white, Left black, turn left
    if(ADC_Right_Detector<COUNT_200 && ADC_Left_Detector>COUNT_500){
      dir_right(TRUE);
      dir_left(SET_ZERO);
      TB1CCR1=COUNT_5000;
      TB2CCR2=COUNT_5000;
      lastright_flag=FALSE;
      lastleft_flag=TRUE;
     }     else
     //Right white, Left white
     if(ADC_Right_Detector<COUNT_200 && ADC_Left_Detector<COUNT_200){
       //last right, turn back left
       if(lastright_flag){
        dir_right(TRUE);
        dir_left(SET_ZERO);
        TB1CCR1=COUNT_5000;
        TB2CCR2=COUNT_5000;
       }
       //last left, turn back right
       if(lastleft_flag){
        dir_right(SET_ZERO);
        dir_left(TRUE);
        TB1CCR2=COUNT_5000;
        TB2CCR1=COUNT_5000;
       }
     } 
       //go forward 
     else {
        dir_right(TRUE);
        dir_left(TRUE);
        TB1CCR1=COUNT_5000;
        TB2CCR1=COUNT_5000;
     }
}


//=========================================================================== 
// Function name:  movement
// 
// Description: This function contains the movement function depends on the wifi command
//              
//                
// Passed : no variables passed 
// Locals: i
// Returned: no values returned 
// Globals: 
//      time[FOUR_COUNT];
//      time_s;
//      movement_count;
//      blackline_flag;
//      back_on_flag;
//      turn_model;
//     
// 
//  Author: SHUAI WANG
//  Date: Apr 2016
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 
//simple command from project7 
void movement(char* string){
  Wheel_Off();
  if(string[FIVE_COUNT]=='F'){
    Left_Forward_On();
    Right_Forward_On();
  }
  else if(string[FIVE_COUNT]=='B'){
    Left_Reverse_On();
    Right_Reverse_On();
  }
  else if(string[FIVE_COUNT]=='R'){
    Left_Forward_On();
  } 
  else if(string[FIVE_COUNT]=='L'){
    Right_Forward_On();
  }

  time[ZERO_COUNT]=string[SIX_COUNT];
  time[ONE_COUNT]=string[SEVEN_COUNT];
  time[TWO_COUNT]=string[EIGHT_COUNT];
  time_s=BCDtoHEX(time);
  int i;
  i=COUNT_20*time_s;
  Five_msec_Delay(i);
  
  Wheel_Off();
  
  
}

//=========================================================================== 
// Function name:  movement_dota
// 
// Description: This function contains the movement function depends on the wifi controller command
//              
//                
// Passed : no variables passed 
// Locals: no variables declared 
// Returned: no values returned 
// Globals: 
//      time[FOUR_COUNT];
//      time_s;
//      movement_count;
//      blackline_flag;
//      back_on_flag;
//      turn_model;
//     
// 
//  Author: SHUAI WANG
//  Date: Apr 2016
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 
//controller command
void movement_dota(char* string){
   Wheel_Off();
   
   //move forward
  if(string[FIVE_COUNT]=='f'){
    Left_Forward_On();
    Right_Forward_On();
    movement_count=SET_ZERO;
  }
  //move backward
  else if(string[FIVE_COUNT]=='b'){
    Left_Reverse_On();
    Right_Reverse_On();
    movement_count=ZERO_COUNT;
  }
  //turn right
  else if(string[FIVE_COUNT]=='r'){
    Left_Forward_On();
    if(back_on_flag){
      Right_Reverse_On();
    }
    movement_count=COUNT_20;
  } 
  //turn left
  else if(string[FIVE_COUNT]=='l'){
    Right_Forward_On();
    if(back_on_flag){
      Left_Reverse_On();
    }
    movement_count=COUNT_20;
  } 
  //stop move
  else if(string[FIVE_COUNT]=='s'){
    movement_count=COUNT_50;
  }
  //go to black line ready      .dotar
  
  else if(string[FIVE_COUNT]=='g'){
    movement_count=COUNT_50;
    blackline_flag=TRUE;
  } 
  //end black line running
  else if(string[FIVE_COUNT]=='e'){
    movement_count=COUNT_50;
    PWM_Wheel_Off();
    blackline_flag=FALSE;
  }  
  //change turning model
  else if(string[FIVE_COUNT]=='c'){
    switch(turn_model){
    case ZERO_COUNT: 
      back_on_flag=TRUE;
      turn_model=ONE_COUNT;
      break;
        
    case ONE_COUNT:
      back_on_flag=FALSE;
      turn_model=ZERO_COUNT;
   
    }
  }
  
  
}

//=========================================================================== 
// Function name:  BCDtoHEX
// 
// Description: This function is to convert BCD value to HEX value.
//              
//                
// Passed : string[]
// Locals: n_100, n_10, n_1, hex
// Returned: no values returned 
// Globals: no globals
//     
// 
//  Author: SHUAI WANG
//  Date: Apr 2016
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//===========================================================================        
//function for BCD to HEX
int BCDtoHEX(char string[]){
  int n_100,n_10,n_1;
  int hex;
  n_100=COUNT_100*(string[ZERO_COUNT]-BCD_ZERO);
  n_10=TEN_COUNT*(string[ONE_COUNT]-BCD_ZERO);
  n_1=string[TWO_COUNT]-BCD_ZERO;
  hex=n_100+n_10+n_1;
  return hex;
}
 