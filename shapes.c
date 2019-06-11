/*SHUAI WANG 02/14/2016*/

//=========================================================================== 
// File Name : shapes.c 
//
//  Description: This file contains the function for shapes movement.
//
//  Author: Shuai Wang
//  Date: Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

extern volatile char one_time;
extern volatile unsigned int Time_Sequence;
extern int SW_SET1;
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char big;

//First_Menu
void First_Menu(){
  if(SW_SET1>=3)
    SW_SET1=0;
  switch(SW_SET1){
  case 0:
    
    display_1 = " PJ 3";
    posL1 = SW_THREE;
    display_2 = " >CIRCLE";
    posL2 = SW_ONE;
    display_3 = " EIGHT";
    posL3 = SW_TWO;
    display_4 = "  TRANGLE";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
    SW_SET1++;
    Time_Sequence=SET_ZERO;
    while(TRUE){
      if(Time_Sequence>20)
        break;
    }
    break;
  case 1:
    
    display_1 = " PJ 3";
    posL1 = SW_THREE;
    display_2 = "  CIRCLE";
    posL2 = SW_ONE;
    display_3 = ">EIGHT";
    posL3 = SW_TWO;
    display_4 = "  TRANGLE";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
    SW_SET1++;
    Time_Sequence=SET_ZERO;
    while(TRUE){
      if(Time_Sequence>20)
        break;
    }
    break;
  case 2:
    
    display_1 = " PJ 3";
    posL1 = SW_THREE;
    display_2 = "  CIRCLE";
    posL2 = SW_ONE;
    display_3 = " EIGHT";
    posL3 = SW_TWO;
    display_4 = " >TRANGLE";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
    SW_SET1++;
    Time_Sequence=SET_ZERO;
    while(TRUE){
      if(Time_Sequence>20)
        break;
    }
    break;
  default: break;
  }

}


//Circle function
void Move_Circle(void){
  
//Circle moving menu  
    display_1 = "PJ 3";
    posL1 = SW_THREE;
    display_2 = " CIRCLE";
    posL2 = SW_ONE;
    display_3 = "  IS";
    posL3 = SW_TWO;
    display_4 = " MOVING";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
    
//delay before moving    
  int delay=1;
  Time_Sequence=SET_ZERO;
  while(delay>0){
    if(Time_Sequence>DELAY)
      delay=0;
  }

//Circle move function
  Time_Sequence=0;
  int i_circle=0;
  while(i_circle<32){
    switch(Time_Sequence){
      case 10:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_circle++;
        }
        Time_Sequence = SET_ZERO;
      case 8:
        if(one_time){
          Right_Forward_On();
          one_time=SET_ZERO;
        }
      case 1:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>10){
      Time_Sequence = SET_ZERO;
    }
  }


}




//Eight Circle function
void Move_Eight(void){

//Eight moving menu
    display_1 = "PJ3";
    posL1 = SW_THREE;
    display_2 = " EIGHT";
    posL2 = SW_ONE;
    display_3 = " IS";
    posL3 = SW_TWO;
    display_4 = " MOVING";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
    
//delay before move    
  int delay=1;
  Time_Sequence=SET_ZERO;
  while(delay>0){
    if(Time_Sequence>DELAY)
      delay=0;
  }

  //Eight move:double single move.
  Eight_Turn();


}

//Eight single Turn Function
void Eight_Turn(){
 //CIRCLE 1
  int i_eight=0;
  while(i_eight<7){
    switch(Time_Sequence){
      case 15:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_eight++;
        }
        Time_Sequence = SET_ZERO;
      case 13:
        if(one_time){
          Right_Forward_On();
          one_time=SET_ZERO;
        }
      case 1:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>15){
      Time_Sequence = SET_ZERO;
    }
  }
  i_eight=0;
  while(i_eight<8){
    switch(Time_Sequence){
      case 15:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_eight++;
        }
        Time_Sequence = SET_ZERO;
      case 12:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      case 1:
        if(one_time){
          Right_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>15){
      Time_Sequence = SET_ZERO;
    }
  }
  //CIRCLE 2
   i_eight=0;
  while(i_eight<9){
    switch(Time_Sequence){
      case 15:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_eight++;
        }
        Time_Sequence = SET_ZERO;
      case 13:
        if(one_time){
          Right_Forward_On();
          one_time=SET_ZERO;
        }
      case 1:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>15){
      Time_Sequence = SET_ZERO;
    }
  }
  i_eight=0;
  while(i_eight<8){
    switch(Time_Sequence){
      case 15:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_eight++;
        }
        Time_Sequence = SET_ZERO;
      case 12:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      case 1:
        if(one_time){
          Right_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>15){
      Time_Sequence = SET_ZERO;
    }
  }
}



//Trangle function
void Move_Trangle(void){
  
//Trangle moving menu
    display_1 = " PJ3";
    posL1 = SW_THREE;
    display_2 = " TRANGLE";
    posL2 = SW_ONE;
    display_3 = "  IS";
    posL3 = SW_TWO;
    display_4 = " MOVING";
    posL4 = SW_ONE;
    big = SET_ZERO;
    Display_Process();
 
//delay befoe move    
  int delay=1;
  Time_Sequence=SET_ZERO;
  while(delay>0){
    if(Time_Sequence>DELAY)
      delay=0;
  }
  
//Trangle circle 1
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
  
//Trangle circle 2
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
  Trangle_Straight();
  Trangle_Turn();
  Trangle_Straight();
}


//Trangle Straight Function
void Trangle_Straight(void){

  int i_trangle_s=0;
  while(i_trangle_s<3){
    switch(Time_Sequence){
      case 5:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_trangle_s++;
        }
        Time_Sequence = SET_ZERO;
      case 1:
        if(one_time){
          Right_Forward_On();
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>5){
      Time_Sequence = SET_ZERO;
    }
  }

}

//Trangle Turnning function
void Trangle_Turn(void){

  int i_trangle_t=0;
  while(i_trangle_t<16){
    switch(Time_Sequence){
      case 3:
        if(one_time){
          Wheel_Off();
          one_time=SET_ZERO;
          i_trangle_t++;
        }
        Time_Sequence = SET_ZERO;
    
      case 1:
        if(one_time){
          Left_Forward_On();
          one_time=SET_ZERO;
        }
      break;
    default: break;
    }
    if(Time_Sequence>3){
      Time_Sequence = SET_ZERO;
    }
  }
 
}