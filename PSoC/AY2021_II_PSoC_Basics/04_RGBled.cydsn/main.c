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

#define LED_ON 1 //high digital state
#define LED_OFF 0 // low digital state
#define PUSHBUTTON_PRESSED 0 //perchè ho la resistenza di pullup


int main(void)
{
    Timer_LED_Start();
    Timer_LED_ISR_Start();
    // the clock is started by default 
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
      
    }
}

/* [] END OF FILE */
