/*SHUAI WANG 02/25/2016*/

//=========================================================================== 
// File Name : main.c 
//
//  Description: This file contains the main function.
//
//  Author: Shuai Wang
//  Date: May 2016 
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

//------------------------------------------------------------------------------
#include  "msp430.h"
#include  "functions.h"
#include  "macros.h"
#include  <string.h>



// Global Variables
volatile unsigned char control_state[CNTL_STATE_INDEX];
volatile unsigned int Time_Sequence;
char led_smclk;
volatile char one_time;
volatile unsigned int five_msec_count;
extern char display_line_1[LENGTH_ELEVEN];
extern char display_line_2[LENGTH_ELEVEN];
extern char display_line_3[LENGTH_ELEVEN];
extern char display_line_4[LENGTH_ELEVEN];
extern char *display_1;
extern char *display_2;
extern char *display_3;
extern char *display_4;
char posL1;
char posL2;
char posL3;
char posL4;
char size_count;
char big;
int SW_SET1;
extern volatile int time_count;
extern volatile unsigned int iot_rx_ring_wr;
extern volatile unsigned int check_index;
extern int PC_start_command_flag;
extern int command_ready_flag;
char pc_command[ELEVEN];
char imhere_str[ELEVEN]="I'm here";
char fast_baudrate_str[ELEVEN]="115200";
char slow_baudrate_str[ELEVEN]="9600";
int IOT_command_ready_flag;
int ssid_flag=SET_ZERO;
int state_flag=SET_ZERO;
extern char ssid_str[TEN_COUNT];
extern int wifi_start_command_flag;
extern int wifi_end_command_flag;
extern int wifi_command_ready_flag;
char wifi_command[COUNT_20];
extern int wifi_command_index;
extern int reset_flag;
extern int reset_start_command_flag;
extern int reset_end_command_flag;
extern int reset_command_ready_flag;
char reset_command[COUNT_13];
extern int reset_command_index;
char wifi_2nd_str[TEN_COUNT];
int ipadd_flag;
extern int ipadd_ready_flag;
char ipadd_1st_str [TEN_COUNT];
char ipadd_2nd_str [TEN_COUNT];
extern char ipadd_str[COUNT_30];
extern char reset_str[TEN_COUNT];
extern int movement_count;
int blackline_flag;
int lastright_flag;
int lastleft_flag;


//=========================================================================== 
// Function name:  main
// 
// Description:  This is the main routine for the program. Execution of code starts here.
//               The operating system is Back Ground Fore Ground
// 
//                
// Passed : no variables passed 
// Locals: no variables declared 
// Returned: no values returned 
// Globals: 
//      volatile unsigned char control_state[CNTL_STATE_INDEX];
//      volatile unsigned int Time_Sequence;
//      char led_smclk;
//      volatile char one_time;
//      volatile unsigned int five_msec_count;
//      extern char display_line_1[LENGTH_ELEVEN];
//      extern char display_line_2[LENGTH_ELEVEN];
//      extern char display_line_3[LENGTH_ELEVEN];
//      extern char display_line_4[LENGTH_ELEVEN];
//      extern char *display_1;
//      extern char *display_2;
//      extern char *display_3;
//      extern char *display_4;
//      char posL1;
//      char posL2;
//      char posL3;
//      char posL4;
//      char size_count;
//      char big;
//      int SW_SET1;
//      extern volatile int time_count;
//      extern volatile unsigned int iot_rx_ring_wr;
//      extern volatile unsigned int check_index;
//      extern int PC_start_command_flag;
//      extern int command_ready_flag;
//      char pc_command[ELEVEN];
//      char imhere_str[ELEVEN]="I'm here";
//      char fast_baudrate_str[ELEVEN]="115200";
//      char slow_baudrate_str[ELEVEN]="9600";
//      int IOT_command_ready_flag;
//      int ssid_flag=SET_ZERO;
//      int state_flag=SET_ZERO;
//      extern char ssid_str[TEN_COUNT];
//      extern int wifi_start_command_flag;
//      extern int wifi_end_command_flag;
//      extern int wifi_command_ready_flag;
//      char wifi_command[COUNT_20];
//      extern int wifi_command_index;
//      extern int reset_flag;
//      extern int reset_start_command_flag;
//      extern int reset_end_command_flag;
//      extern int reset_command_ready_flag;
//      char reset_command[COUNT_13];
//      extern int reset_command_index;
//      char wifi_2nd_str[TEN_COUNT];
//      int ipadd_flag;
//      extern int ipadd_ready_flag;
//      char ipadd_1st_str [TEN_COUNT];
//      char ipadd_2nd_str [TEN_COUNT];
//      extern char ipadd_str[COUNT_30];
//      extern char reset_str[TEN_COUNT];
//      extern int movement_count;
//      int blackline_flag;
//      int lastright_flag;
//      int lastleft_flag;
//     
// 
//  Author: SHUAI WANG
//  Date: Apr 2016
//  Compiler: Built with IAR Embedded Workbench Version: V4.10A/W32 (5.40.1) 
//=========================================================================== 

void main(void){

  //call init functions, and set up starting statement
  Init_Ports();                             // Initialize Ports
  Init_Clocks();                            // Initialize Clock System 
  Init_Conditions();
  Init_Serial_UCA0();
  Init_Serial_UCA1(); 
    
  Init_ADC();

  
  Time_Sequence = SET_ZERO;                        // 
  Init_Timers();                            // Initialize Timers
  Init_LCD();                               // Initialize LCD
  time_count=SET_ZERO;
  five_ms_blink = SET_ZERO;
  Five_msec_Delay(COUNT_50);
  PJOUT  |= IOT_RESET; 
 
  

  
//             Starting display
  display_1 = "   NCSU";
  posL1 = SW_ZERO;
  display_2 = " WOLFPACK";
  posL2 = SW_ZERO;
  display_3 = "  ECE306";
  posL3 = SW_ZERO;
  display_4 = "  S Wang";
  posL4 = SW_ZERO;
  big = SET_ZERO;
  Display_Process();
  
//initial flags  
  IOT_command_ready_flag=FALSE;
  PC_start_command_flag=FALSE;
  ipadd_flag=FALSE;
  ipadd_ready_flag=FALSE;
  blackline_flag=FALSE;
  
  iot_rx_ring_wr=SET_ZERO;
  check_index=SET_ZERO;
 // Five_msec_Delay(COUNT_200);
 // move_count=ONE_COUNT;
 
  ADC10CTL0 |= ADC10ENC + ADC10SC; // Sampling and conversion start
//------------------------------------------------------------------------------
// Begining of the "While" Operating System
//------------------------------------------------------------------------------
  while(ALWAYS) {
   
//blackline code
    if(blackline_flag){
     ADC_LCD_STATE();
     Black_Line();
    }
    
//check step move
     if(movement_count>COUNT_50){
        Wheel_Off();
     }
     
//check reset state
    if(strncmp("+WIND:41:", reset_str, NINE_COUNT)==SET_ZERO){
      reset_flag=TRUE;
      //clear the reset_str
       for(int m=SET_ZERO;m<TEN_COUNT;m++){
           reset_str[m] = SET_ZERO;
        }
    }
      
    
    
//switch ipadd display
    if(state_flag){
      ipadd_flag=TRUE;
      IOT_command("AT+S.STS");        
      state_flag=SET_ZERO;
    }
    
    
//ipadd display
    
    if(ipadd_ready_flag){
        
        int o,p;
        p=COUNT_15;
        for(o=SET_ZERO;o<SIX_COUNT;o++){
          ipadd_1st_str[o]=ipadd_str[p];
          p++;
        }
        for(o=SET_ZERO;o<SEVEN_COUNT;o++){
          ipadd_2nd_str[o]=ipadd_str[p];
          p++;
        }
      
      
        display_1 = "   ncsu";
        posL1 = SW_ZERO;
        display_2 = "  ipaddr";
        posL2 = SW_ZERO;
        display_3 = ipadd_1st_str;
        posL3 = SW_ZERO;
        display_4 = ipadd_2nd_str;
        posL4 = SW_ZERO;
        big = SET_ZERO;
        Display_Process();
        
        for(int m=SET_ZERO;m<COUNT_30;m++){
           ipadd_str[m] = SET_ZERO;
        }
        ipadd_ready_flag=FALSE;
    
    }
//RESET CHECK
    if(reset_flag){
        PJOUT  &= ~IOT_RESET;          
        IOT_command("AT+CFUN=1");
        Five_msec_Delay(COUNT_20);
        PJOUT  |= IOT_RESET;  
        reset_flag=FALSE;
    }
    
//-------------------------------------------------------------------------------        
//pc command
//-------------------------------------------------------------------------------    
    if(command_ready_flag){
      lcd_4line(); 
      int i=SET_ZERO;
  //i'm here command
      if(strcmp("..", pc_command)==SET_ZERO){
         i=SET_ZERO;
        while(imhere_str[i]!='\0'){
          transmit_A0(imhere_str[i]);
          i++;
        }
      }
  //115200 baudrate command
      if(strcmp(".F", pc_command)==SET_ZERO){
        i=SET_ZERO;
        UCA1BRW = baud_115200_BRW ; // 115200 baud
        UCA1MCTLW = baud_115200_MCTLW;

        while(fast_baudrate_str[i]!='\0'){
          transmit_A0(fast_baudrate_str[i]);
          i++;
        }
      }
  //9600 baudrate command    
      if(strcmp(".S", pc_command)==SET_ZERO){
        i=SET_ZERO;
      //response to PC  
        while(slow_baudrate_str[i]!='\0'){
          transmit_A0(slow_baudrate_str[i]);
          i++;
        }
       UCA1BRW = baud_9600_BRW ; // 9,600 baud
       UCA1MCTLW = baud_9600_MCTLW ;
      }
      
  //IOT baudrate to 9600
      if(strcmp(".is", pc_command)==SET_ZERO){
        IOT_command("AT+S.SCFG=console1_speed,9600");
      }
  //IOT SAVE
      if(strcmp(".save", pc_command)==SET_ZERO){
        IOT_command("AT&W");
      }
  //RESET MODULE
      if(strcmp(".reset", pc_command)==SET_ZERO){
        PJOUT  &= ~IOT_RESET;          
        IOT_command("AT+CFUN=1");
        Five_msec_Delay(COUNT_20);
        PJOUT  |= IOT_RESET;  
      }  
   
  //MAC ADDRESS // "00:80:E1:B7:DA:8E"
      if(strcmp(".mac", pc_command)==SET_ZERO){
        IOT_command("AT+S.GCFG=nv_wifi_macaddr");
        
        display_1 = "   MAC";
        posL1 = SW_ZERO;
        display_2 = "00:80:E1:";
        posL2 = SW_ZERO;
        display_3 = "B7:DA:8E";
        posL3 = SW_ZERO;
        display_4 = "  S Wang";
        posL4 = SW_ZERO;
        big = SET_ZERO;
        Display_Process();
      }      
      
  //Set the SSID      
      if(strcmp(".setssid", pc_command)==SET_ZERO){
        IOT_command("AT+S.SSIDTXT=ncsu");
      }  
        
  //Get the SSID      
      if(strcmp(".getssid", pc_command)==SET_ZERO){
        ssid_flag=TRUE;
        IOT_command("AT+S.SSIDTXT");
      }  
      
  //Set the host name    
      if(strcmp(".sethost", pc_command)==SET_ZERO){
        IOT_command("AT+S.SCFG=ip_hostname,ECE-306_15_D");
      }  
      
  //get the host name    
      if(strcmp(".gethost", pc_command)==SET_ZERO){
        IOT_command("AT+S.GCFG=ip_hostname");
      }  
    
  //Set network privacy mode
      if(strcmp(".setnet0", pc_command)==SET_ZERO){
        IOT_command("AT+S.SCFG=wifi_priv_mode,0");
      }  
 
  //get network privacy mode    
      if(strcmp(".getnet0", pc_command)==SET_ZERO){
        IOT_command("AT+S.GCFG=wifi_priv_mode");
      }  

  //set network mode 1=STA
      if(strcmp(".setnet1", pc_command)==SET_ZERO){
        IOT_command("AT+S.SCFG=wifi_mode,1");
      }  
      
  //get network mode 1=STA
      if(strcmp(".getnet1", pc_command)==SET_ZERO){
        IOT_command("AT+S.GCFG=wifi_mode");
      }  
   
  //check state //ipadd "10.139.68.87"
      if(strcmp(".state", pc_command)==SET_ZERO){
        ipadd_flag=TRUE;
        IOT_command("AT+S.STS");

        
      }  
            
  //clear pc command string      
      for(int n=SET_ZERO;n<ELEVEN_COUNT;n++){
        pc_command[n] = SET_ZERO;
      }
      command_ready_flag=FALSE;

    }//end of pc command loop
    
//-------------------------------------------------------------------------------    
// wifi command
//-------------------------------------------------------------------------------    

    if(wifi_command_ready_flag){
      //check if commond is from controller
      if(strncmp(".dota",wifi_command,FIVE_COUNT)==SET_ZERO){
        movement_dota(wifi_command);
      }
      
        //check if commond passwork is correct
      if(strncmp(".0905", wifi_command,FIVE_COUNT)==SET_ZERO){
        //display command if the command is correct command
        lcd_BIG_mid(); 
        display_1 = "";
        posL1 = SW_ZERO;
        display_2 =wifi_command;
        posL2 = SW_ZERO;
        display_3 = "";
        posL3 = SW_ZERO;
        big = SET_ZERO;
        Display_Process(); 
        movement(wifi_command);
        
        //check if there are two command
        if(wifi_command[TEN_COUNT]=='.'){
          int g,h;
          h=TEN_COUNT;
          for(g=SET_ZERO;g<TEN_COUNT;g++){
            wifi_2nd_str[g]=wifi_command[h];
            h++;
          }
          if(strncmp(".0905", wifi_2nd_str,FIVE_COUNT)==SET_ZERO){
            lcd_BIG_mid(); 
            display_1 = "";
            posL1 = SW_ZERO;
            display_2 =wifi_2nd_str;
            posL2 = SW_ZERO;
            display_3 = "";
            posL3 = SW_ZERO;
            big = SET_ZERO;
            Display_Process(); 
            movement(wifi_2nd_str);
          } 
         for(int m=SET_ZERO;m<COUNT_20;m++){ 
            wifi_2nd_str[m] = SET_ZERO;
         }
        }
      }
    
    //clear wifi command string      
      for(int m=SET_ZERO;m<COUNT_20;m++){
        wifi_command[m] = SET_ZERO;
      }
      wifi_command_ready_flag=FALSE;
    }//end of wifi command loop
    
 }// while always end

}//main end 





