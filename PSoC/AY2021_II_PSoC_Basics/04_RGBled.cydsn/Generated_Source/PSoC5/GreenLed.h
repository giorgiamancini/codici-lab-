/*******************************************************************************
* File Name: GreenLed.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_GreenLed_H) /* Pins GreenLed_H */
#define CY_PINS_GreenLed_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "GreenLed_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 GreenLed__PORT == 15 && ((GreenLed__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    GreenLed_Write(uint8 value);
void    GreenLed_SetDriveMode(uint8 mode);
uint8   GreenLed_ReadDataReg(void);
uint8   GreenLed_Read(void);
void    GreenLed_SetInterruptMode(uint16 position, uint16 mode);
uint8   GreenLed_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the GreenLed_SetDriveMode() function.
     *  @{
     */
        #define GreenLed_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define GreenLed_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define GreenLed_DM_RES_UP          PIN_DM_RES_UP
        #define GreenLed_DM_RES_DWN         PIN_DM_RES_DWN
        #define GreenLed_DM_OD_LO           PIN_DM_OD_LO
        #define GreenLed_DM_OD_HI           PIN_DM_OD_HI
        #define GreenLed_DM_STRONG          PIN_DM_STRONG
        #define GreenLed_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define GreenLed_MASK               GreenLed__MASK
#define GreenLed_SHIFT              GreenLed__SHIFT
#define GreenLed_WIDTH              1u

/* Interrupt constants */
#if defined(GreenLed__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in GreenLed_SetInterruptMode() function.
     *  @{
     */
        #define GreenLed_INTR_NONE      (uint16)(0x0000u)
        #define GreenLed_INTR_RISING    (uint16)(0x0001u)
        #define GreenLed_INTR_FALLING   (uint16)(0x0002u)
        #define GreenLed_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define GreenLed_INTR_MASK      (0x01u) 
#endif /* (GreenLed__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define GreenLed_PS                     (* (reg8 *) GreenLed__PS)
/* Data Register */
#define GreenLed_DR                     (* (reg8 *) GreenLed__DR)
/* Port Number */
#define GreenLed_PRT_NUM                (* (reg8 *) GreenLed__PRT) 
/* Connect to Analog Globals */                                                  
#define GreenLed_AG                     (* (reg8 *) GreenLed__AG)                       
/* Analog MUX bux enable */
#define GreenLed_AMUX                   (* (reg8 *) GreenLed__AMUX) 
/* Bidirectional Enable */                                                        
#define GreenLed_BIE                    (* (reg8 *) GreenLed__BIE)
/* Bit-mask for Aliased Register Access */
#define GreenLed_BIT_MASK               (* (reg8 *) GreenLed__BIT_MASK)
/* Bypass Enable */
#define GreenLed_BYP                    (* (reg8 *) GreenLed__BYP)
/* Port wide control signals */                                                   
#define GreenLed_CTL                    (* (reg8 *) GreenLed__CTL)
/* Drive Modes */
#define GreenLed_DM0                    (* (reg8 *) GreenLed__DM0) 
#define GreenLed_DM1                    (* (reg8 *) GreenLed__DM1)
#define GreenLed_DM2                    (* (reg8 *) GreenLed__DM2) 
/* Input Buffer Disable Override */
#define GreenLed_INP_DIS                (* (reg8 *) GreenLed__INP_DIS)
/* LCD Common or Segment Drive */
#define GreenLed_LCD_COM_SEG            (* (reg8 *) GreenLed__LCD_COM_SEG)
/* Enable Segment LCD */
#define GreenLed_LCD_EN                 (* (reg8 *) GreenLed__LCD_EN)
/* Slew Rate Control */
#define GreenLed_SLW                    (* (reg8 *) GreenLed__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define GreenLed_PRTDSI__CAPS_SEL       (* (reg8 *) GreenLed__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define GreenLed_PRTDSI__DBL_SYNC_IN    (* (reg8 *) GreenLed__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define GreenLed_PRTDSI__OE_SEL0        (* (reg8 *) GreenLed__PRTDSI__OE_SEL0) 
#define GreenLed_PRTDSI__OE_SEL1        (* (reg8 *) GreenLed__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define GreenLed_PRTDSI__OUT_SEL0       (* (reg8 *) GreenLed__PRTDSI__OUT_SEL0) 
#define GreenLed_PRTDSI__OUT_SEL1       (* (reg8 *) GreenLed__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define GreenLed_PRTDSI__SYNC_OUT       (* (reg8 *) GreenLed__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(GreenLed__SIO_CFG)
    #define GreenLed_SIO_HYST_EN        (* (reg8 *) GreenLed__SIO_HYST_EN)
    #define GreenLed_SIO_REG_HIFREQ     (* (reg8 *) GreenLed__SIO_REG_HIFREQ)
    #define GreenLed_SIO_CFG            (* (reg8 *) GreenLed__SIO_CFG)
    #define GreenLed_SIO_DIFF           (* (reg8 *) GreenLed__SIO_DIFF)
#endif /* (GreenLed__SIO_CFG) */

/* Interrupt Registers */
#if defined(GreenLed__INTSTAT)
    #define GreenLed_INTSTAT            (* (reg8 *) GreenLed__INTSTAT)
    #define GreenLed_SNAP               (* (reg8 *) GreenLed__SNAP)
    
	#define GreenLed_0_INTTYPE_REG 		(* (reg8 *) GreenLed__0__INTTYPE)
#endif /* (GreenLed__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_GreenLed_H */


/* [] END OF FILE */
