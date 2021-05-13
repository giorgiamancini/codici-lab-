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

    #define BYTE_TO_SEND 2 // perchè voglio mandare 16 bit
    #define TRANSMIT_BUFFER_SIZE 1+BYTE_TO_SEND+1 //metto 2 byte in più che sono l'inizio e la fine 
    
    // se abbiamo 3 sensori i BYTE TO SEND sono 6
    
    CY_ISR_PROTO(Custom_ISR_ADC);
    CY_ISR_PROTO(Custom_ISR_RX);
    
    uint8 DataBuffer[TRANSMIT_BUFFER_SIZE];
    
    
    
#endif 

/* [] END OF FILE */
