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
#include "InterruptRoutines.h"
#include "DMA_Routines.h"

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    WaveDAC8_Start();
    ADC_DelSig_Start();
    Timer_Start();
    UART_Start();
    ADC_DelSig_StartConvert();
    
    //START THE FILTER
    Filter_1_Start();
    Filter_1_SetCoherency(Filter_1_CHANNEL_A, Filter_1_KEY_MID);
    
    //trigger the end of conversion
    ADC_DelSig_IRQ_Start(); // start the internal interrupt
    
    dataBuffer[0] = 0xA0;
    dataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    
    Flag = 0;
    
    isr_TIMER_StartEx(Custom_ISR_timer);
    
    //run the dma configuration function 
    DMA_ADC_2_MEM_Config(); //the dma is mapping the output of adc on adcbuffer
    DMA_FILTER_2_MEM_Config();
    DMA_MEM_2_FILTER_Config();

    for(;;)
    {
        if (Flag == 1){
        
            UART_PutArray(dataBuffer, TRANSMIT_BUFFER_SIZE);
            Flag = 0;
        }
    }
}

/* [] END OF FILE */
