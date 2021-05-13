/* ========================================
 brief main source file for 06-uart project
*/


/*
when the button is pressed, the LED is on
*/ 



#include "project.h"
#include "RGBLedDriver.h"
#include "colors.h"

#define LED_ON 1 //high digital state
#define LED_OFF 0 // low digital state
#define PUSHBUTTON_PRESSED 0 //perchè ho la resistenza di pullup


int main(void)
{
       
    // the clock is started by default 
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

   
    for(;;)
    {
      UART_PutString("Hello World\r\n"); //richiede sempre una stringa in ingresso
    //le funioni put mandano sempre dati al parte tx per poi leggerli su cooltermo
      CyDelay(1000); //la scritta viene stampata ogni 1 sec
    }
}

/* [] END OF FILE */
