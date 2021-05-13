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
#include "project.h"

#define LED_DELAY 1000

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
        // toggle the LED
        //write the NOT value of the pin
        // reading the pin value with Blue_LED_Read, invert it (!), write the value with Blue_LED_Write
        
        uint8 led_value= Blue_LED_Read();
        led_value = !led_value;
        Blue_LED_Write(led_value);
        
        // wait for a certain amount of time (otherwise the blink is too fast)
        CyDelay(LED_DELAY);
    }
}

/* [] END OF FILE */
