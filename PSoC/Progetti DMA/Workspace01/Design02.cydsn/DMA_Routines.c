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

#include "DMA_Routines.h"
#include "project.h"

void DMA_ADC_2_MEM_Config(void) {
    

    /* Variable declarations for DMA */
    /* Move these variable declarations to the top of the function */
    
    //handle the dma channel
    uint8 DMA_Chan;
    
    //handle to the dma to transaction descriptor
    uint8 DMA_TD[1];

    /* DMA Configuration for DMA */
    
    //initialize the dma channel
    DMA_Chan = DMA_DmaInitialize(DMA_BYTES_PER_BURST, DMA_REQUEST_PER_BURST, 
        HI16(DMA_SRC_BASE), HI16(DMA_DST_BASE));
    
    //allocation of TD
    DMA_TD[0] = CyDmaTdAllocate();
    
    //Configuration of transaction descriptor (TD)
    CyDmaTdSetConfiguration(DMA_TD[0], 2, DMA_TD[0], CY_DMA_TD_INC_DST_ADR);
    
    //specify the address (lower part)
    CyDmaTdSetAddress(DMA_TD[0], LO16((uint32)ADC_DelSig_DEC_SAMP_PTR), LO16((uint32)AdcBuffer));
    
    //association between dma channel with TD
    CyDmaChSetInitialTd(DMA_Chan, DMA_TD[0]);
    
    // start of dma
    CyDmaChEnable(DMA_Chan, 1);
    
}

/* [] END OF FILE */
