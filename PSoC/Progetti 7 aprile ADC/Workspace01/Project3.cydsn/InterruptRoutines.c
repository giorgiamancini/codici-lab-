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
#include "project.h"

int32 value_digit;
int32 value_mv; 
extern volatile uint8 PacketReadyFlag;
extern volatile uint8 SendBytesFlag;
uint8 ch_received;


CY_ISR(Custom_ISR_ADC)
{
    Timer_ReadStatusRegister(); //se non la metto il codice esegue una sola interrupt e si ferma  
    if (SendBytesFlag == 1) {
        value_digit= ADC_DelSig_Read32(); //perchè usiamo qui 32 se abbiamo settato l'adc a 16 bit? leggo su datasheet
        
        if (value_digit < 0)     value_digit = 0;
        if (value_digit > 65535) value_digit = 65535; //setto valori minimo e massimo che noi leggiamo in digit
        
        value_mv = ADC_DelSig_CountsTo_mVolts(value_digit); // trasformo i dati da digit a millivolts ma non è necessario
        
        sprintf(DataBuffer, "Sample: %ld mV\r\n", value_mv); 
        
        PacketReadyFlag = 1;
    }


}

CY_ISR(Custom_ISR_RX)
{
    ch_received = UART_GetChar(); // per ricevere il carattere dall'uart
    
    switch(ch_received)
    {
        case 'A':
        case 'a':
            SendBytesFlag = 1;
            Pin_LED_Write(1);
            Timer_Start();
            break;
        
        case 'B':
        case 'b':
            SendBytesFlag = 0;
            Pin_LED_Write(0);
            Timer_Stop();
            break;
        default:
            break;
    
    }
    
}





/* [] END OF FILE */
