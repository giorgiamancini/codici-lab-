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
// se uso il valore in mv sull'asse x poi vedrò i valori in mv

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
        
        //databuffer ha 4 byte (2 sono del dato e 1 start e 1 stop)
        // i byte di start e stop rimangono costanti e vado a cambiare i byte del dato 
        DataBuffer[1] = value_digit >> 8; // per mettere il bit più significativo alla posizione 1 e per saltare il byte di start
        DataBuffer[2] = value_digit & 0xFF; //per mettere il meno significativo alla posizione 2
        //sprintf(DataBuffer, "Sample: %ld mV\r\n", value_mv); 
        
        PacketReadyFlag = 1;
    }


}

CY_ISR(Custom_ISR_RX)
{
    ch_received = UART_GetChar();
    
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
