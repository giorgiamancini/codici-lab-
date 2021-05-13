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
    
   /* Defines for DMA_FM */
    #define DMA_FM_BYTES_PER_BURST 2
    #define DMA_FM_REQUEST_PER_BURST 1
    #define DMA_FM_SRC_BASE (CYDEV_PERIPH_BASE)
    #define DMA_FM_DST_BASE (CYDEV_SRAM_BASE)


    
    /* Defines for DMA_MF */
    #define DMA_MF_BYTES_PER_BURST 2
    #define DMA_MF_REQUEST_PER_BURST 1
    #define DMA_MF_SRC_BASE (CYDEV_SRAM_BASE)
    #define DMA_MF_DST_BASE (CYDEV_PERIPH_BASE)

    
    #define BYTE_IN_FILTER 2
    char FilterBuffer[BYTE_IN_FILTER];
    
    void DMA_FILTER_2_MEM_Config(void);
    void DMA_MEM_2_FILTER_Config(void);
    
    
#endif



/* [] END OF FILE */
