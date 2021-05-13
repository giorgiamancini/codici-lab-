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
volatile uint8 SendBytesFlag;

int main(void)
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    UART_Start();
    
    ADC_DelSig_Start();
    isr_ADC_StartEx(Custom_ISR_ADC);
    isr_RX_StartEx(Custom_ISR_RX);
    
    DataBuffer[0] = 0xA0; // è il byte header messo alla posizione 0
    DataBuffer[TRANSMIT_BUFFER_SIZE-1] = 0xC0; // il tail lo metto alla penultima posizione
    
    PacketReadyFlag = 0; //all'inizio non abbiamo nulla
    
    //UART_PutString("\f");
    ADC_DelSig_StartConvert(); // start to sample con conversione rate 3000 (settata sul top design)
    
    for(;;)
    {
        if (PacketReadyFlag == 1) {
            UART_PutArray(DataBuffer, TRANSMIT_BUFFER_SIZE); //ha bisogno di una stringa e di quanti byte voglio trasmettere
            PacketReadyFlag = 0;
        }
    }
}

/* [] END OF FILE */
