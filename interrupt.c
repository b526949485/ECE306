//******************************************************************************
//
//  Description: This file contains the interrupt of timer, switch, and ADC.
//
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************


#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

volatile int five_ms_count=SET_ZERO;
volatile int five_ms_blink=SET_ZERO;
volatile int time_count=SET_ZERO;
volatile int time_count_state=SET_ZERO;
volatile int IR_count=SET_ZERO;
extern unsigned int test_number;
volatile int sw1_state;
volatile int sw2_state;
volatile int sw1_count;
volatile int sw2_count;
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char big;
int switch_flag=SET_ZERO;
int sw1_roll=ONE_COUNT;
int sw2_roll=ONE_COUNT;
int reset_flag;
extern int state_flag;
int movement_count;
//******************************************************************************
// 
//  Description: This function contains the interrupt that count up time 
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals:
//      five_ms_count=SET_ZERO;
//      five_ms_blink=SET_ZERO;
//      time_count=SET_ZERO;
//      time_count_state=SET_ZERO;
//      sw1_state;
//      sw2_state;
//      sw1_count;
//      sw2_count;
//      movement_count;
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

// Enable the Timer Interrupt for the debounce.
#pragma vector = TIMER0_A0_VECTOR
__interrupt void Timer0_A0_ISR(void){
   five_ms_count++;
   five_ms_blink++;
   movement_count++;
   time_count++;
   sw1_count++;
   sw2_count++;
   
   
   
   
   
   if(sw1_count >=DEBOUNCE_COUNT_SW && sw1_state == FALSE){        
   
    P4IE |= SW1;
    sw1_state=TRUE;
    P4IFG &= ~SW1;
    
  }
  
   if(sw2_count >=DEBOUNCE_COUNT_SW && sw2_state == FALSE){        
   
    P4IE |= SW2;
    sw2_state=TRUE;
    P4IFG &= ~SW2;
    
  }
  
   
 
}

//******************************************************************************
//
//  Description: This function contains the interrupt of switch
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals:
//      five_ms_blink=SET_ZERO;
//      sw1_state;
//      sw2_state;
//      sw1_count;
//      sw2_count;
//      *display_1;
//      *display_2;
//      *display_3;
//      *display_4;
//      posL1;
//      posL2;
//      posL3;
//      posL4;
//      big;
//      switch_flag=SET_ZERO;
//      sw1_roll=ONE_COUNT;
//      sw2_roll=ONE_COUNT;
//      reset_flag;
//      state_flag;
//      movement_count;
//          
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************


//Create Interrupt Service Routine Function with ¡°__interrupt¡±
#pragma vector=PORT4_VECTOR
__interrupt void switch_interrupt(void){


//switch 1
  if (P4IFG & SW1){
    P4IE &= ~SW1;
    sw1_state=FALSE;
    sw1_count=SET_ZERO;
    P4IFG &= ~SW1;
    five_ms_blink=SET_ZERO;
    
    reset_flag=TRUE;


  }
  
  
//switch 2
    if (P4IFG & SW2){
    P4IE &= ~SW2;
    sw2_state=FALSE;
    sw2_count=SET_ZERO;
    P4IFG &= ~SW2;
    five_ms_blink=SET_ZERO;
          lcd_4line(); 


        switch(sw2_roll){
      case ONE_COUNT:
        display_1 = "   MAC";
        display_2 = "00:80:E1:";
        display_3 = "B7:DA:8E";
        display_4 = "  S Wang";
        Display_Process();
       sw2_roll=TWO_COUNT;
       break;

      case TWO_COUNT:
        state_flag=TRUE;
        sw2_roll=ONE_COUNT;
        break;
        
    default: break;
    }

    
    switch_flag=TRUE;
    
  

  }
}
//------------------------------------------------------------------------------
// ADC10 interrupt service routine
// ADC_Right_Detector; // A00 ADC10INCH_0 - P1.0
// ADC_Left_Detector; // A01 ADC10INCH_1 - P1.1
// ADC_Thumb; // A03 ADC10INCH_3 - P1.3
// ADC_Temp; // A10 ADC10INCH_10 ?Temperature REF module
// ADC_Bat; // A11 ADC10INCH_11 - Internal


volatile  unsigned int chanel=SET_ZERO;
volatile  unsigned int ADC_Right_Detector;
volatile  unsigned int ADC_Left_Detector;
volatile  unsigned int ADC_Thumb;

//******************************************************************************
//
//  Description: This function contains the interrupt of ADC
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals:
//      chanel;
//      ADC_Right_Detector;
//      ADC_Left_Detector;
//      ADC_Thumb;
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************


#pragma vector=ADC10_VECTOR
__interrupt void ADC10_ISR(void){
  switch(__even_in_range(ADC10IV,END_COUNT)) {
    case SET_ZERO: break; // No interrupt
    case TWO_COUNT: break; // conversion result overflow
    case FOUR_COUNT: break; // conversion time overflow
    case SIX_COUNT: break; // ADC10HI
    case EIGHT_COUNT: break; // ADC10LO
    case TEN_COUNT: break; // ADC10IN
    case END_COUNT:
//  ADC_Thumb = ADC10MEM0; // Channel A3
       ADC10CTL0 &= ~ADC10ENC; // Turn off the ENC bit of the ADC10CTL0 
       switch (chanel++){
       case SET_ZERO:
          ADC10MCTL0 = ADC10INCH_1;          // Next channel A1 
          ADC_Left_Detector = ADC10MEM0; // Current Channel result for A0 
          break;
       case ONE_COUNT:
          ADC10MCTL0 = ADC10INCH_3;          // Next channel A3 
          ADC_Right_Detector = ADC10MEM0; // Current Channel result for A1 
          break;
       case TWO_COUNT:
          ADC10MCTL0 = ADC10INCH_0;          // Next channel A0 
          ADC_Thumb = ADC10MEM0; // Current Channel result for A3 
          chanel = SET_ZERO;
           break;
       default:
           break;
       }
        ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
      break;
      //ADC10CTL0 |= ADC10ENC;                 // Turn on the ENC bit of the ADC10CTL0 
     //  ADC10CTL0 |= _______;                  // Start next sample. 
   
 }
  
}
//------------------------------------------------------------------------------





