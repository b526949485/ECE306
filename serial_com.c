//******************************************************************************
//
//  Description: This file contains the serial commuication that transfor the information 
//
//
//  Shuai Wang
//  March 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************



#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"


// global variables
volatile unsigned int usb_rx_ring_wr;
volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
volatile unsigned int usb_rx_ring_rd;
volatile char USB_Char_Tx[SMALL_RING_SIZE];
volatile unsigned int usb_tx_ring_wr;
volatile unsigned int usb_tx_ring_rd;


volatile unsigned int iot_rx_ring_wr;
volatile unsigned int check_index;
volatile char IOT_Char_Rx[SMALL_RING_SIZE] ;
volatile unsigned int iot_rx_ring_rd;
volatile char IOT_Char_Tx[SMALL_RING_SIZE];
volatile unsigned int iot_tx_ring_wr;
volatile unsigned int iot_tx_ring_rd;
unsigned int test_number;
volatile char display_number[TWO_COUNT];
char bcd_number[TEN_COUNT];
extern char *display_1;
extern int READY;
unsigned int iot_Rxtemp;
unsigned int usb_Rxtemp;
int PC_start_command_flag;
int PC_end_command_flag;
int command_ready_flag;
extern char pc_command[ELEVEN];
int command_index;

extern int IOT_command_ready_flag;
char ip_address[COUNT_20];
char ssid_str[TEN_COUNT];
extern int ssid_flag;
int A1_index;
int ssid_start_flag=SET_ZERO;

int wifi_start_command_flag;
int wifi_end_command_flag;
int wifi_command_ready_flag;
extern char wifi_command[COUNT_20];
int wifi_command_index;
extern int reset;

int reset_start_command_flag;
int reset_end_command_flag;
int reset_command_ready_flag;
extern char reset_command[COUNT_13];
int reset_command_index;

extern int ipadd_flag;
int ipadd_count=SET_ZERO;
char ipadd_str[COUNT_30];
int ipadd_index=SET_ZERO;
int ipadd_ready_flag;

char reset_str[TEN_COUNT];
int reset_index;
int reset_count;
int disconnect_flag;

//Init A0
//----------------------------------------------------------------------------

//******************************************************************************
//
//  Description: This function contain the initialation of UCA0
//  Passed: no varibales passed
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: 
//           usb_rx_ring_wr = SET_ZERO;
//           usb_rx_ring_rd = SET_ZERO;
//           usb_tx_ring_wr = SET_ZERO;
//           usb_tx_ring_rd = SET_ZERO;
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

void Init_Serial_UCA0(void){
 int i;
 for(i=SET_ZERO; i<SMALL_RING_SIZE; i++){
   USB_Char_Rx[i] = SET_ZERO;// USB Character
   }
 usb_rx_ring_wr = SET_ZERO;
 usb_rx_ring_rd = SET_ZERO;

 for(i=zero; i<LARGE_RING_SIZE; i++){
   USB_Char_Tx[i] = SET_ZERO;// USB Character
   }
 usb_tx_ring_wr = SET_ZERO;
 usb_tx_ring_rd = SET_ZERO;
 // Configure UART 0
 UCA0CTLW0 = SET_ZERO; // Use word register
 UCA0CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA0CTLW0 |= UCSWRST; // Set Software reset enable
 UCA0BRW = baud_9600_BRW ; // 9,600 baud
 UCA0MCTLW = baud_9600_MCTLW ;
 UCA0CTL1 &= ~UCSWRST; // Release from reset
 UCA0IE |= UCRXIE; // Enable RX interrupt
}

//init A1

//******************************************************************************
//
//  Description: This function contain the initialation of UCA1
//  Passed: no varibales passed
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: 
//           iot_rx_ring_wr = SET_ZERO;
//           iot_rx_ring_rd = SET_ZERO;
//           iot_tx_ring_wr = SET_ZERO;
//           iot_tx_ring_rd = SET_ZERO;
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************
void Init_Serial_UCA1(void){
 int i;
 for(i=SET_ZERO; i<SMALL_RING_SIZE; i++){
   IOT_Char_Rx[i] = SET_ZERO;// IOT Character
   }
 iot_rx_ring_wr = SET_ZERO;
 iot_rx_ring_rd = SET_ZERO;

 for(i=zero; i<LARGE_RING_SIZE; i++){
   IOT_Char_Tx[i] = SET_ZERO;// IOT Character
   }
 iot_tx_ring_wr = SET_ZERO;
 iot_tx_ring_rd = SET_ZERO;
 // Configure UART 0
 UCA1CTLW0 = SET_ZERO; // IOT word register
 UCA1CTLW0 |= UCSSEL__SMCLK; // Set SMCLK as fBRCLK
 UCA1CTLW0 |= UCSWRST; // Set Software reset enable
 UCA1BRW = baud_9600_BRW ; // 9,600 baud
 UCA1MCTLW = baud_9600_MCTLW ;
// UCA1BRW = baud_115200_BRW ; // 115200 baud
// UCA1MCTLW = baud_115200_MCTLW;
 UCA1CTL1 &= ~UCSWRST; // Release from reset
 UCA1IE |= UCRXIE; // Enable RX interrupt
}


//******************************************************************************
//
//  Description: This function is the interrupt of A0 USB port. And set up some flags to work on the command.
//  Passed: no varibales passed
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: 
//      volatile unsigned int usb_rx_ring_wr;
//      volatile char USB_Char_Rx[SMALL_RING_SIZE] ;
//      volatile unsigned int usb_rx_ring_rd;
//      volatile char USB_Char_Tx[SMALL_RING_SIZE];
//      volatile unsigned int usb_tx_ring_wr;
//      volatile unsigned int usb_tx_ring_rd;
//      volatile unsigned int check_index;
//      unsigned int test_number;
//      volatile char display_number[TWO_COUNT];
//      char bcd_number[TEN_COUNT];
//      extern char *display_1;
//      extern int READY;
//      unsigned int iot_Rxtemp;
//      unsigned int usb_Rxtemp;
//      int PC_start_command_flag;
//      int PC_end_command_flag;
//      int command_ready_flag;
//      extern char pc_command[ELEVEN];
//      int command_index;
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void){
 switch(__even_in_range(UCA0IV,IOT_RESET)){ //RESET = 0x08
  case SET_ZERO: // Vector 0 - no interrupt
   break;
  case Vector_2: // Vector 2 - RXIFG
   usb_Rxtemp = usb_rx_ring_wr;
   UCA0TXBUF=UCA0RXBUF;
   USB_Char_Rx[usb_Rxtemp] = UCA0RXBUF; // RX -> USB_Char_Rx character
   if (USB_Char_Rx[usb_Rxtemp]=='.' && !(PC_start_command_flag)){
     PC_start_command_flag=TRUE;
     command_index=SET_ZERO;
   }
   
   if (USB_Char_Rx[usb_Rxtemp]==ENTER && PC_start_command_flag){
     PC_start_command_flag=FALSE;
     command_ready_flag=TRUE;
   } 
     
  
   if(PC_start_command_flag){
      pc_command[command_index]=USB_Char_Rx[usb_Rxtemp];
      command_index++;
   }
     
   if (++usb_rx_ring_wr >= (SMALL_RING_SIZE)){
     usb_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
   }
   break;
  case Vector_4: // Vector 4 ? TXIFG
    
    
   break;
 default: break;
 }
}


//******************************************************************************
//
//  Description: This function is the interrupt of A1 IOT port. And set up some flags to work on the command.
//  Passed: no varibales passed
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: 
//      volatile unsigned int iot_rx_ring_wr;
//      volatile unsigned int iot_tx_ring_wr;
//      volatile unsigned int iot_tx_ring_rd;
//      volatile char IOT_Char_Rx[SMALL_RING_SIZE] ;
//      volatile unsigned int iot_rx_ring_rd;
//      volatile char IOT_Char_Tx[SMALL_RING_SIZE];
//      extern int IOT_command_ready_flag;
//      char ip_address[COUNT_20];
//      char ssid_str[TEN_COUNT];
//      extern int ssid_flag;
//      int A1_index;
//      int ssid_start_flag=SET_ZERO;
//      int wifi_start_command_flag;
//      int wifi_end_command_flag;
//      int wifi_command_ready_flag;
//      extern char wifi_command[COUNT_20];
//      int wifi_command_index;
//      extern int reset;
//      int reset_start_command_flag;
//      int reset_end_command_flag;
//      int reset_command_ready_flag;
//      extern char reset_command[COUNT_13];
//      int reset_command_index;
//      extern int ipadd_flag;
//      int ipadd_count=SET_ZERO;
//      char ipadd_str[COUNT_30];
//      int ipadd_index=SET_ZERO;
//      int ipadd_ready_flag;
//      char reset_str[TEN_COUNT];
//      int reset_index;
//      int reset_count;
//      int disconnect_flag;   
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

//------------------------------------------------------------------------------
#pragma vector=USCI_A1_VECTOR
__interrupt void USCI_A1_ISR(void){
  
 switch(__even_in_range(UCA1IV,IOT_RESET)){ //RESET = 0x08
  case SET_ZERO: // Vector 0 - no interrupt
   break;
  case Vector_2: // Vector 2 - RXIFG
   iot_Rxtemp = iot_rx_ring_wr;
   IOT_Char_Rx[iot_Rxtemp] = UCA1RXBUF; // RX -> IOT_Char_Rx character
 
   //check reset
   
   if(IOT_Char_Rx[iot_Rxtemp]=='+'){
     reset_index=SET_ZERO;
     reset_count=SET_ZERO;
     disconnect_flag=TRUE;
   }
   if(disconnect_flag){
    reset_str[reset_index]=IOT_Char_Rx[iot_Rxtemp];
    reset_index++;
    reset_count++;
    if(reset_count==TEN_COUNT) {disconnect_flag=FALSE;}
   }
   
   
   
   //check ipadd
   if(ipadd_flag){
     if(IOT_Char_Rx[iot_Rxtemp]=='#'){
       ipadd_count++;
     }
     
     if(ipadd_count==IPADD_START){
       ipadd_str[ipadd_index]=IOT_Char_Rx[iot_Rxtemp];
       ipadd_index++;
     }
     
     if(ipadd_count==IPADD_END){
       ipadd_flag=FALSE;
       ipadd_ready_flag=TRUE;
       ipadd_count=SET_ZERO;
       ipadd_index=SET_ZERO;
     }
   }
   //check wifi command
   if (IOT_Char_Rx[iot_Rxtemp]=='.' && !(wifi_start_command_flag)){
     wifi_start_command_flag=TRUE;
     wifi_command_index=SET_ZERO;
   }
   
   if (IOT_Char_Rx[iot_Rxtemp]==ENTER && wifi_start_command_flag){
     wifi_start_command_flag=FALSE;
     wifi_command_ready_flag=TRUE;
   } 
     
  
   if(wifi_start_command_flag){
      wifi_command[wifi_command_index]=IOT_Char_Rx[iot_Rxtemp];
      wifi_command_index++;
   }
   
   if (++iot_rx_ring_wr >= (SMALL_RING_SIZE)){
      iot_rx_ring_wr = BEGINNING; // Circular buffer back to beginning
   }

    
    UCA0TXBUF= UCA1RXBUF;
   break;
  case Vector_4: // Vector 4 ? TXIFG
    
    
   break;
 default: break;
 }
}

//******************************************************************************
//
//  Description: This function is to transmit date from A0
//  
//  Passed: data
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: no variables global
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************

void transmit_A0(char data){
  while(!(UCTXIFG&UCA0IFG));
  UCA0TXBUF=data;
  }


//******************************************************************************
//
//  Description: This function is to transmit date from A1
//  
//  Passed: data
//  Locals: no varibales local
//  Returned: no variables returned.
//  Globals: no variables global
//          
//
//  Shuai Wang
//  Apri 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//******************************************************************************
void transmit_A1(char data){
  while(!(UCTXIFG&UCA1IFG));
  UCA1TXBUF=data;
}
