/* ========================================
 
*/


#include "RGBLedDriver.h"

static void RGBLed_WriteRed(uint8_t red);
static void RGBLed_WriteGreen(uint8_t green);
static void RGBLed_WriteBlu(uint8_t blu);

void RGBLed_Start()
{
    PWM_RG_Start();
    PWM_B_Start();
}

void RGBLed_Stop()
{
    PWM_RG_Stop();
    PWM_B_Stop();
}

void RGBLed_WriteColor(Color c)
{
    PWM_RG_WriteCompare1(c.red);
    PWM_RG_WriteCompare2(c.green);
    PWM_B_WriteCompare(c.blu);
}

static void REGLed_WriteGreen(uint8_t green)
{
    PWM_RG_WriteCompare2(green);
}

static void REGLed_WriteRed(uint8_t red)
{
    PWM_RG_WriteCompare2(red);
}

static void REGLed_WriteBlu(uint8_t blu)
{
    PWM_B_WriteCompare(blu);
}


/* [] END OF FILE */
