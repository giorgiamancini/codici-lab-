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
#include "InterruptRoutines.h"


int main(void)
{
    Timer_LED_Start(); // serve sempre attivarlo altrimenti non va il programma
    Timer_LED_ISR_StartEx(Custom_LED_ISR);
   
    // the clock is started by default 
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
      
    }
}

/* [] END OF FILE */
