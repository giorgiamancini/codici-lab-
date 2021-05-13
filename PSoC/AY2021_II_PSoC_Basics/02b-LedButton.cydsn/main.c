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
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */

    for(;;)
    {
      uint8_t push_button_state = PushButton_Read();
      if (push_button_state == PUSHBUTTON_PRESSED) {
        // if the button is pressed, the led is on
        Blue_LED_Write(LED_ON);
      }
      else {
        // if the button is not pressed, the led is off
        Blue_LED_Write(LED_OFF);
      }
    }
}

/* [] END OF FILE */
