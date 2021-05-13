/* ========================================
 
*/

//this is the source file and we have to include the header files

#include "InterruptRoutines.h"

CY_ISR(Custom_LED_ISR) 
{
    //ISR code
    
    //read timer status registr
    Timer_LED_ReadStatusRegister(); //clears interrupt
    
    //toggle the LED
    GreenLed_Write(!GreenLed_Read());
}

/* [] END OF FILE */
