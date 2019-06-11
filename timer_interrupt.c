//******************************************************************************
//
//  Description: This file initialise A0, B1 timer
//
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************



#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"

//******************************************************************************
//
//  Description: This function initialise A0 timer
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals: no variables globals.
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

int right_forward_rate;
int right_reverse_rate;
int left_forward_rate;
int left_reverse_rate;

void Init_Timer_A0(void) {
 TA0CTL = TASSEL__SMCLK; // SMCLK source
 TA0CTL |= TACLR; // Resets TA0R, clock divider, count direction
 TA0CTL |= MC__UP; // Continuous up
 TA0CTL |= ID__2; // Divide clock by 2
 TA0CTL &= ~TAIE; // Disable Overflow Interrupt
 TA0CTL &= ~TAIFG; // Clear Overflow Interrupt flag

 TA0EX0 = TAIDEX_7; // Divide clock by an additional 8

//enable_interrupts();
 TA0CCR0 = TA0CCR0_INTERVAL; // CCR0
 TA0CCTL0 |= CCIE; // CCR0 enable interrupt
// TA0CCR1 = TA0CCR1_INTERVAL; // CCR1
// TA0CCTL1 |= CCIE; // CCR1 enable interrupt
// TA0CCR2 = TA0CCR2_INTERVAL; // CCR2
// TA0CCTL2 |= CCIE; // CCR2 enable interrupt
}
//------------------------------------------------------------------------------
//******************************************************************************

//******************************************************************************
//
//  Description: This function initialise B1 timer
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals: no variables globals.
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

void Init_Timer_B1(void) {
  TB1CTL = TBSSEL__SMCLK;              // SMCLK 
  TB1CTL |= MC_1;                      // Up Mode
  TB1CTL |= TBCLR;                     // Clear TAR
  
   right_forward_rate = SET_ZERO;            // Set Right Forward Off
   right_reverse_rate = SET_ZERO;            // Set Right Reverse Off 
   
   TB1CCR0 = WHEEL_PERIOD;              // PWM Period
   TB1CCTL1 = OUTMOD_7;                 // CCR1 reset/set
   TB1CCR1 = right_forward_rate;        // P3.4 Right Forward PWM duty cycle
   TB1CCTL2 = OUTMOD_7;                 // CCR2 reset/set
   TB1CCR2 = right_reverse_rate;
        // P3.5 Right Reverse PWM duty cycle 
}

//******************************************************************************
//
//  Description: This function initialise B2 timer
//  Passed: no variables passed
//  Locals: no variables local.
//  Returned: no variables returned.
//  Globals: no variables globals.
//
//  Shuai Wang
//  Feb 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

void Init_Timer_B2(void) {
  TB2CTL = TBSSEL__SMCLK;              // SMCLK 
  TB2CTL |= MC_1;                      // Up Mode
  TB2CTL |= TBCLR;                     // Clear TAR
  
   left_forward_rate = SET_ZERO;            // Set left Forward Off
   left_reverse_rate = SET_ZERO;            // Set left Reverse Off 
   
   TB2CCR0 = WHEEL_PERIOD;              // PWM Period
   TB2CCTL1 = OUTMOD_7;                 // CCR1 reset/set
   TB2CCR1 = left_forward_rate;        // P3.4 left Forward PWM duty cycle
   TB2CCTL2 = OUTMOD_7;                 // CCR2 reset/set
   TB2CCR2 = left_reverse_rate;
        // P3.5 Right Reverse PWM duty cycle 
}



