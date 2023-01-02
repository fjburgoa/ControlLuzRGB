#include "c8051F300.h"
#include <stdio.h>    
#include <float.h>

/*************************  DEFINICION DE TIUPOS  *********************************************/
 typedef unsigned long ulong;  
 typedef unsigned int  uint;
 typedef unsigned char  uchar;
/**********************************************************************************************/



#define MAX_STEPS 11
#define MAX_COLOR 3

sbit LED_G     = P0^2;
sbit LED_R     = P0^0;
sbit LED_B     = P0^1;



int contador = 0;

unsigned char powerR[MAX_STEPS] = {0,1,2,3,4,5,6,7,8,9,10};
unsigned char powerG[MAX_STEPS] = {0,1,2,3,4,5,6,7,8,9,10};
unsigned char powerB[MAX_STEPS] = {0,1,2,3,4,5,6,7,8,9,10};

unsigned int cnt       = 0;
unsigned int cntR      = 0;
unsigned int cntG      = 0;
unsigned int cntB      = 0;


unsigned char flag_int    = 0;


extern void Init_Device();
 


//--------------------------------------------------------------------------------------------
//TRATAMIENTO DE LAS INTERRUPCIONES
//--------------------------------------------------------------------------------------------

void ADC0_Init () interrupt 8
{
    static uchar loc_counter =0;


    AD0INT  = 0;

    cnt = (10*ADC0);
    cnt = cnt/255;

	if (loc_counter==0)
	{    cntB   = cnt;
		 AMX0SL = 0x84; 	 		 //R - channel P0.4
	}
	if (loc_counter==1)
	{
		 cntG   = cnt;
		 AMX0SL = 0x85; 	 		 //R - channel P0.6 
	}
	if (loc_counter==2)
	{
		 cntR   = cnt;
		 AMX0SL = 0x86; 	 		 //R - channel P0.5
	}


    loc_counter++;
	if (loc_counter > 2)
	   loc_counter = 0;

}


//----------------------------------------------------------------------------------------------------
void int_timer0() interrupt 1   
{
   //actualizamos en pasos de 10.
   contador++;
   if (contador>9)
   {
      contador = 0;
	        
   }
   flag_int = 1; //cada interrupción , activa flag
} 
 	
//----------------------------------------------------------------------------------------------------
void main (void) {

    Init_Device();


    LED_G = 0;
    LED_B = 0;
    LED_R = 0;

    AD0EN = 1;

    AD0BUSY = 1;

	while(1)
	{
	   
	   if (flag_int)
	   {	      
		 if (contador<powerR[cntR])
		    LED_R = 0;
		 else
		    LED_R = 1;
		  
         
		 if (contador<powerG[cntG])
		    LED_G = 0;
		 else
		    LED_G = 1;

		 if (contador<powerB[cntB])
		    LED_B = 0;
		 else
		    LED_B = 1;
         
    	 flag_int = 0;
	   }
	};


}//fin main


