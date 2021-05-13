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


void DMA_FILTER_2_MEM_Config(void) {


    
    /* Variable declarations for DMA_FM */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_FM_Chan;
    uint8 DMA_FM_TD[1];

    /* DMA Configuration for DMA_FM */
    DMA_FM_Chan = DMA_FM_DmaInitialize(DMA_FM_BYTES_PER_BURST, DMA_FM_REQUEST_PER_BURST, 
        HI16(DMA_FM_SRC_BASE), HI16(DMA_FM_DST_BASE));
    DMA_FM_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_FM_TD[0], 2, DMA_FM_TD[0], CY_DMA_TD_INC_DST_ADR);
    CyDmaTdSetAddress(DMA_FM_TD[0], LO16((uint32)Filter_1_HOLDA_PTR), LO16((uint32)FilterBuffer));
    CyDmaChSetInitialTd(DMA_FM_Chan, DMA_FM_TD[0]);
    CyDmaChEnable(DMA_FM_Chan, 1);
    
    
}


void DMA_MEM_2_FILTER_Config(void){

    
    /* Variable declarations for DMA_MF */
    /* Move these variable declarations to the top of the function */
    uint8 DMA_MF_Chan;
    uint8 DMA_MF_TD[1];

    /* DMA Configuration for DMA_MF */
    DMA_MF_Chan = DMA_MF_DmaInitialize(DMA_MF_BYTES_PER_BURST, DMA_MF_REQUEST_PER_BURST, 
        HI16(DMA_MF_SRC_BASE), HI16(DMA_MF_DST_BASE));
    DMA_MF_TD[0] = CyDmaTdAllocate();
    CyDmaTdSetConfiguration(DMA_MF_TD[0], 2, DMA_MF_TD[0], CY_DMA_TD_INC_SRC_ADR);
    CyDmaTdSetAddress(DMA_MF_TD[0], LO16((uint32)AdcBuffer), LO16((uint32)Filter_1_STAGEA_PTR));
    CyDmaChSetInitialTd(DMA_MF_Chan, DMA_MF_TD[0]);
    CyDmaChEnable(DMA_MF_Chan, 1);
    
}
/* [] END OF FILE */
