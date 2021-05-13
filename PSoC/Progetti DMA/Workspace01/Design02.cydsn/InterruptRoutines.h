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

#ifndef __INTERRUPT_ROUTINES_H
    #define __INTERRUPT_ROUTINES_H
    
    #include "cytypes.h"
    #include "stdio.h"
    
    //data to send to the UART
    #define BYTE_TO_SEND 2
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1
    
    uint8 dataBuffer[TRANSMIT_BUFFER_SIZE]; //data
    uint8 Flag; //flag for sending data
    
    CY_ISR_PROTO(Custom_ISR_timer); //CALL isr function
    
#endif
/* [] END OF FILE */
