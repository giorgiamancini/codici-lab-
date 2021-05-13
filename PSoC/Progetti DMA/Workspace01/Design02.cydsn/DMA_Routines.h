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

#ifndef __DMA_ROUTINES_H
    #define __DMA_ROUTINES_H


    /* Defines for DMA */
    #define DMA_BYTES_PER_BURST 2
    #define DMA_REQUEST_PER_BURST 1
    #define DMA_SRC_BASE (CYDEV_PERIPH_BASE)
    #define DMA_DST_BASE (CYDEV_SRAM_BASE)
    
    #include "cytypes.h"
    #include "stdio.h"
    
    #define BYTE_IN_ADC 2
    char AdcBuffer[BYTE_IN_ADC];
    
    void DMA_ADC_2_MEM_Config(void); //set all the features of dma data transfer and configuration
    
#endif



/* [] END OF FILE */
