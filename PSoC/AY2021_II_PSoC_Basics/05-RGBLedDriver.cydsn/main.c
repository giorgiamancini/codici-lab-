/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
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

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    RGBLed_Start();
    
    RGBLed_WriteColor(RED);
    CyDelay(1000);
    
    RGBLed_WriteColor(LIME);
    CyDelay(1000);
    
    RGBLed_WriteColor(MAGENTA);
    CyDelay(1000);
    
    RGBLed_WriteColor(GREEN);
    CyDelay(1000);
    
    RGBLed_WriteColor(PURPLE);
    CyDelay(1000);
    
    RGBLed_WriteColor(TEAL);
    CyDelay(1000);
    
    RGBLed_Stop(); //diventa bianco alla fine se ci metto stop
    
    for(;;)
    {
      
    }
}

/* [] END OF FILE */
