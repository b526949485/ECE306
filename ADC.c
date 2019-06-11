//******************************************************************************
//
//  Description: This file contains the ADC init function and ADC display function.
//
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

char string[SIX_COUNT];
char Thumb[TEN_COUNT];
char ADC_RIGHT[TEN_COUNT];
char ADC_LEFT [TEN_COUNT];
extern volatile int five_ms_count;
extern volatile int five_ms_blink;
extern char adc_char[FIVE_COUNT];
extern volatile  unsigned int ADC_Thumb;
extern volatile  unsigned int ADC_Right_Detector;
extern volatile  unsigned int ADC_Left_Detector;
extern char big;
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
extern char posL1;
extern char posL2;
extern char posL3;
extern char posL4;
extern char big;


//******************************************************************************
//
//  Description: This function contains the initialation of ADC
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals: no variables globals
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************
// Configure ADC10_B
void Init_ADC(void){
 ADC10CTL0 = SET_ZERO; // Clear ADC10CTL0
 ADC10CTL0 |= ADC10SHT_2; // 16 ADC clocks
 ADC10CTL0 &= ~ADC10MSC; // Single Sequence
 ADC10CTL0 |= ADC10ON; // ADC ON - Core Enabled
 
 ADC10CTL1 = SET_ZERO; // Clear ADC10CTL1
 ADC10CTL1 |= ADC10SHS_0; // ADC10SC bit
 ADC10CTL1 |= ADC10SHP; // SAMPCON signal sourced from sampling timer
 ADC10CTL1 &= ~ADC10ISSH; // The sample-input signal is not inverted.
 ADC10CTL1 |= ADC10DIV_0; // ADC10_B clock divider ?Divide by 1.
 ADC10CTL1 |= ADC10SSEL_0; // MODCLK
 ADC10CTL1 |= ADC10CONSEQ_0; // Single-channel, single-conversion
 
 ADC10CTL2 = SET_ZERO; // Clear ADC10CTL2
 ADC10CTL2 |= ADC10DIV_0; // Pre-divide by 1
 ADC10CTL2 |= ADC10RES; // 10-bit resolution
 ADC10CTL2 &= ~ADC10DF; // Binary unsigned
 ADC10CTL2 &= ~ADC10SR; // supports up to approximately 200 ksps
 
 ADC10MCTL0 = SET_ZERO; // Clear ADC10MCTL0
 ADC10MCTL0 |= ADC10SREF_0; // V(R+) = AVCC and V(R-) = AVSS
 ADC10MCTL0 |= ADC10INCH_3; // Channel A3 Thumb Wheel
 ADC10IE |= ADC10IE0; // Enable ADC conversion complete interrupt

}

//------------------------------------------------------------------------------ 
//****************************************************************************** 
// Hex to BCD Conversion
// Convert a Hex number to a BCD for display on an LCD or monitor
//------------------------------------------------------------------------------ 

//******************************************************************************
//
//  Description: This function is to convert the HEX value to BCD value
//  
//  Passed: string[], hex_value
//  Locals: value
//  Returned: no variables returned.
//  Globals: no variables global
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************
void HEXtoBCD(char string[], int hex_value){ 

  int value; 
  string[ZERO_COUNT] = '0'; 
  string[ONE_COUNT] = '0'; 
  string[TWO_COUNT] = '0'; 
  string[THREE_COUNT] = '0'; 
  
  value = SET_ZERO;
  while (hex_value > COUNT_999){ 
    hex_value = hex_value - COUNT_1000;
    value = value + ONE_COUNT;
    string[ZERO_COUNT] = ASCII_0 + value;
  }  
  
 value = SET_ZERO;
  while (hex_value > COUNT_99){ 
    hex_value = hex_value - COUNT_100;
    value = value + ONE_COUNT;
    string[ONE_COUNT] = ASCII_0 + value;
  }  
 
  
  
 value = SET_ZERO;  
 while (hex_value > NINE_COUNT){
   hex_value = hex_value -  TEN_COUNT;
   value = value + ONE_COUNT;
   string[TWO_COUNT] = ASCII_0 + value;
 }  
  string[THREE_COUNT] = ASCII_0 + hex_value;
 
  string[FOUR_COUNT] ='\0';
}  


//******************************************************************************
//
//  Description: This function contains the display of ADC values, and turn on/off IR led
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals:
//      string[SIX_COUNT];
//      Thumb[TEN_COUNT];
//      ADC_RIGHT[TEN_COUNT];
//      ADC_LEFT [TEN_COUNT];
//      five_ms_count;
//      five_ms_blink;
//      adc_char[FIVE_COUNT];
//      ADC_Thumb;
//      ADC_Right_Detector;
//      ADC_Left_Detector;
//      big;
//      *display_1;
//      *display_2;
//      *display_3;
//      *display_4;
//      posL1;
//      posL2;
//      posL3;
//      posL4;
//      big;
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

//ADC LCD display state function

void ADC_LCD_STATE(void){
      if(five_ms_count > COUNT_20){
      P1OUT |= IR_LED;
    //  ADC_Process();
      
      if(five_ms_count > COUNT_20 + TEN_COUNT){
        five_ms_count=SET_ZERO;
      }
    }
   
    if(five_ms_blink > QUARTER_SEC){
      
//        HEXtoBCD(Thumb,ADC_Thumb);
        HEXtoBCD(ADC_RIGHT,ADC_Right_Detector);
        HEXtoBCD(ADC_LEFT,ADC_Left_Detector);
      
       display_1 = Thumb;
       posL1 = SW_ONE;
       display_2 = ADC_RIGHT;
       posL2 = SW_ONE;
       display_3 = ADC_LEFT;
       posL3 = SW_ONE;
       display_4 = " S Wang";
       posL4 = SW_ONE;
       big = SET_ZERO;
       Display_Process();
       
       five_ms_blink = SET_ZERO;
    }
}



 //****************************************************************************** 
 //------------------------------------------------------------------------------ 
//******************************************************************************
//
//  Description: This function is to active the ADC
//  
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals: no varibales globals.
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************
//-------------------------------------------------------------------
void ADC_Process(void){
  while (ADC10CTL1 & BUSY);   //wait if ADC10 core is active
  ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
}





