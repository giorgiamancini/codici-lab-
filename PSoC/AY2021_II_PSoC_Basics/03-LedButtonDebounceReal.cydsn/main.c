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

#define LED_ON  1   // High digital state
#define LED_OFF 0   // Low digital state

#define PUSHBUTTON_PRESSED 0    // Pushbutton is pressed -> resistive pull - up -> 0
#define DEBOUNCE_DELAY 100000

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    // Last reading of push button
    uint8_t pushButtonLastState = !PUSHBUTTON_PRESSED;  
    // Current reading of push button
    uint8_t pushButtonReading = !PUSHBUTTON_PRESSED;
    // Counter to count time
    long int pushButtonCounter = 0;
    
    for(;;)
    {
        // Update state and reading
        pushButtonLastState = pushButtonReading;
        pushButtonReading = PushButton_Read();
        // Increment counter
        pushButtonCounter ++;
        if (pushButtonReading != pushButtonLastState)
        {
            // Reset counter if something changed
            pushButtonCounter = 0;
        }
        
        // If we've waited enough time
        if (pushButtonCounter == DEBOUNCE_DELAY)
        {
            // If push button was pressed
            if (pushButtonReading == PUSHBUTTON_PRESSED)
            {
                // Toggle LED
                Pin_LED_Write(!Pin_LED_Read());
            }
        }
        
    }
}
/* [] END OF FILE */
