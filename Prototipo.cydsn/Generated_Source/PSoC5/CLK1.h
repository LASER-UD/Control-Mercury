/*******************************************************************************
* File Name: CLK1.h
* Version 2.20
*
*  Description:
*   Provides the function and constant definitions for the clock component.
*
*  Note:
*
********************************************************************************
* Copyright 2008-2012, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_CLOCK_CLK1_H)
#define CY_CLOCK_CLK1_H

#include <cytypes.h>
#include <cyfitter.h>


/***************************************
* Conditional Compilation Parameters
***************************************/

/* Check to see if required defines such as CY_PSOC5LP are available */
/* They are defined starting with cy_boot v3.0 */
#if !defined (CY_PSOC5LP)
    #error Component cy_clock_v2_20 requires cy_boot v3.0 or later
#endif /* (CY_PSOC5LP) */


/***************************************
*        Function Prototypes
***************************************/

void CLK1_Start(void) ;
void CLK1_Stop(void) ;

#if(CY_PSOC3 || CY_PSOC5LP)
void CLK1_StopBlock(void) ;
#endif /* (CY_PSOC3 || CY_PSOC5LP) */

void CLK1_StandbyPower(uint8 state) ;
void CLK1_SetDividerRegister(uint16 clkDivider, uint8 restart) 
                                ;
uint16 CLK1_GetDividerRegister(void) ;
void CLK1_SetModeRegister(uint8 modeBitMask) ;
void CLK1_ClearModeRegister(uint8 modeBitMask) ;
uint8 CLK1_GetModeRegister(void) ;
void CLK1_SetSourceRegister(uint8 clkSource) ;
uint8 CLK1_GetSourceRegister(void) ;
#if defined(CLK1__CFG3)
void CLK1_SetPhaseRegister(uint8 clkPhase) ;
uint8 CLK1_GetPhaseRegister(void) ;
#endif /* defined(CLK1__CFG3) */

#define CLK1_Enable()                       CLK1_Start()
#define CLK1_Disable()                      CLK1_Stop()
#define CLK1_SetDivider(clkDivider)         CLK1_SetDividerRegister(clkDivider, 1u)
#define CLK1_SetDividerValue(clkDivider)    CLK1_SetDividerRegister((clkDivider) - 1u, 1u)
#define CLK1_SetMode(clkMode)               CLK1_SetModeRegister(clkMode)
#define CLK1_SetSource(clkSource)           CLK1_SetSourceRegister(clkSource)
#if defined(CLK1__CFG3)
#define CLK1_SetPhase(clkPhase)             CLK1_SetPhaseRegister(clkPhase)
#define CLK1_SetPhaseValue(clkPhase)        CLK1_SetPhaseRegister((clkPhase) + 1u)
#endif /* defined(CLK1__CFG3) */


/***************************************
*             Registers
***************************************/

/* Register to enable or disable the clock */
#define CLK1_CLKEN              (* (reg8 *) CLK1__PM_ACT_CFG)
#define CLK1_CLKEN_PTR          ((reg8 *) CLK1__PM_ACT_CFG)

/* Register to enable or disable the clock */
#define CLK1_CLKSTBY            (* (reg8 *) CLK1__PM_STBY_CFG)
#define CLK1_CLKSTBY_PTR        ((reg8 *) CLK1__PM_STBY_CFG)

/* Clock LSB divider configuration register. */
#define CLK1_DIV_LSB            (* (reg8 *) CLK1__CFG0)
#define CLK1_DIV_LSB_PTR        ((reg8 *) CLK1__CFG0)
#define CLK1_DIV_PTR            ((reg16 *) CLK1__CFG0)

/* Clock MSB divider configuration register. */
#define CLK1_DIV_MSB            (* (reg8 *) CLK1__CFG1)
#define CLK1_DIV_MSB_PTR        ((reg8 *) CLK1__CFG1)

/* Mode and source configuration register */
#define CLK1_MOD_SRC            (* (reg8 *) CLK1__CFG2)
#define CLK1_MOD_SRC_PTR        ((reg8 *) CLK1__CFG2)

#if defined(CLK1__CFG3)
/* Analog clock phase configuration register */
#define CLK1_PHASE              (* (reg8 *) CLK1__CFG3)
#define CLK1_PHASE_PTR          ((reg8 *) CLK1__CFG3)
#endif /* defined(CLK1__CFG3) */


/**************************************
*       Register Constants
**************************************/

/* Power manager register masks */
#define CLK1_CLKEN_MASK         CLK1__PM_ACT_MSK
#define CLK1_CLKSTBY_MASK       CLK1__PM_STBY_MSK

/* CFG2 field masks */
#define CLK1_SRC_SEL_MSK        CLK1__CFG2_SRC_SEL_MASK
#define CLK1_MODE_MASK          (~(CLK1_SRC_SEL_MSK))

#if defined(CLK1__CFG3)
/* CFG3 phase mask */
#define CLK1_PHASE_MASK         CLK1__CFG3_PHASE_DLY_MASK
#endif /* defined(CLK1__CFG3) */

#endif /* CY_CLOCK_CLK1_H */


/* [] END OF FILE */
