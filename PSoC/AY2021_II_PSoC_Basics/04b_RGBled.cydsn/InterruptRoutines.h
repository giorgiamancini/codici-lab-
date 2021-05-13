/* ========================================
 Interrupt Routines header file.

 Declaration of ISR functions.
*/

// header files can be included by both header and source files, but if we include
//the same files multiple times we can have an error. the ifndef can prevent this 
// error. guardiamo se la cosa non è già stata definita allora la definiamo

#ifndef __INTERRUPT_ROUTINES_H__
    #define __INTERRUPT_ROUTINES_H__
    
    // questo include tutti gli header files che ci servono
    #include "project.h" 
    
    //ISR declaration
    CY_ISR_PROTO(Custom_LED_ISR); //void Custom_LED_ISR(void) non ritorna e non chiede valori
    
    //non possiamo dichiarare una funzione senza prima definirla
#endif 

    
/* [] END OF FILE */
