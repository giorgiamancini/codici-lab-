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
       
    // the clock is started by default 
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    UART_Start();
    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    isr_UART_StartEx(Custom_UART_RX_ISR);
    
   
    for(;;)
    {
    
    }
}

/* [] END OF FILE */
