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

volatile uint8 PacketReadyFlag;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    Timer_Start();
    ADC_DelSig_Start();
    isr_ADC_StartEx(Custom_ISR_ADC);
    
    PacketReadyFlag = 0; //all'inizio non abbiamo nulla
    
    //UART_PutString("\f");
    ADC_DelSig_StartConvert(); // start to sample con conversione rate 3000 (settata sul top design)
    
    for(;;)
    {
        if (PacketReadyFlag == 1) {
            UART_PutString(DataBuffer);
            PacketReadyFlag = 0;
        }
    }
}

/* [] END OF FILE */
