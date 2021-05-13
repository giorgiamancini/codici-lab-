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

//variable to read digit data from 16-bit ADC

int32 value_digit;
int32 value_mv;

CY_ISR_PROTO(Custom_ISR_timer){
    
    Timer_ReadStatusRegister();
    
    ADC_DelSig_IsEndConversion(ADC_DelSig_WAIT_FOR_RESULT); //wait for conversion ending
    ADC_DelSig_StopConvert(); //stop conversion
    
    value_digit = ADC_DelSig_GetResult32();
    
    if (value_digit < 0) value_digit = 0;
    if (value_digit > 65535) value_digit = 65535;
    
    value_mv = ADC_DelSig_CountsTo_mVolts(value_digit);
    
    //dataBuffer[0] is iniziating the buffer
    //dataBuffer[3] is terminating the buffer
    
    //dataBuffer[1] 
    dataBuffer[1]= (value_mv >> 8) & 0xFF;
    
    //dataBuffer[2]
    dataBuffer[2]= value_mv & 0xFF;
    
    Flag = 1;
    
    ADC_DelSig_StartConvert(); //restart conversion
    
    
    
}

/* [] END OF FILE */
