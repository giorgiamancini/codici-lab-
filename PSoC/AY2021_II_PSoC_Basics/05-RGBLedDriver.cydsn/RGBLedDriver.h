/* ========================================
header file for the RGB Led interface
*/




#ifndef __RGB_LED_DRIVER_H__
    #define __RGB_LED_DRIVER_H__
    
    #include "project.h"
    
    /*
    voglio creare i tre colori quindi definisco una structure che mi permette di contenere
    questa informazione (Struct holding color data)
    */
    
    typedef struct {
        //possiamo controllare il pwm cambiando il compare value e controllando 
        //la luminosità
        //led on su rosso --> 155 sul red 
        // vedi rgb color codes chart
        uint8_t red; //red value 0-255
        uint8_t green; //green value 0-255
        uint8_t blu; //blu value 0-255
    } Color;
    
    // per iniziare e stoppare il driver
    void RGBLed_Start(void);
    
    void RGBLed_Stop(void);
    
    //per cambiare colore quindi come argomento ha il tipo che costruito prima "color"
    void RGBLed_WriteColor(Color c);
    
    
#endif


/* [] END OF FILE */

    
