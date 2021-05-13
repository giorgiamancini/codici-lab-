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

#include "InterruptRoutines.h"
#include "stdio.h"

static char message [20] = {'\0'}; //inizializzo la stringa a valore nullo

CY_ISR(Custom_UART_RX_ISR)
{
  //we read the received data and echo it back
    //there are two ways: one we do everything in the interrupt, in the other
    // we use a flag in a source file
    if (UART_ReadRxStatus() == UART_RX_STS_FIFO_NOTEMPTY)
    // WE HAVE some fata in the receiving buffer that need to be read 
    //dobbiamo quindi verificare che ci siano dati e che non sia vuoto
    {
        uint8_t received= UART_ReadRxData(); // leggiamo rx data
        //if we have some data in the FIFO
        sprintf(message, "Received: %c\r\n", received); // formattiamo quello che abbiamo letto
            //la prima è la stringa che volgiamo scrivere su questo messaggio
        
       UART_PutString(message); // lo mandiamo 
            
    }
}



/* [] END OF FILE */
