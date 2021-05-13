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

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */
    
    WaveDAC8_Start();
    ADC_DelSig_Start();
    Timer_Start();
    UART_Start();
    ADC_DelSig_StartConvert();
    
    dataBuffer[0] = 0xA0;
    dataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0;
    
    Flag = 0;
    
    isr_TIMER_StartEx(Custom_ISR_timer);


    for(;;)
    {
        if (Flag == 1){
        
            UART_PutArray(dataBuffer, TRANSMIT_BUFFER_SIZE);
            Flag = 0;
        }
    }
}

/* [] END OF FILE */
