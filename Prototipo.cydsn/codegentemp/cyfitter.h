/*******************************************************************************
* File Name: cyfitter.h
* 
* PSoC Creator  4.2
*
* Description:
* 
* This file is automatically generated by PSoC Creator.
*
********************************************************************************
* Copyright (c) 2007-2018 Cypress Semiconductor.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
********************************************************************************/

#ifndef INCLUDED_CYFITTER_H
#define INCLUDED_CYFITTER_H
#include "cydevice.h"
#include "cydevice_trm.h"

/* ADC */
#define ADC_ADC_SAR__CLK CYREG_SAR0_CLK
#define ADC_ADC_SAR__CSR0 CYREG_SAR0_CSR0
#define ADC_ADC_SAR__CSR1 CYREG_SAR0_CSR1
#define ADC_ADC_SAR__CSR2 CYREG_SAR0_CSR2
#define ADC_ADC_SAR__CSR3 CYREG_SAR0_CSR3
#define ADC_ADC_SAR__CSR4 CYREG_SAR0_CSR4
#define ADC_ADC_SAR__CSR5 CYREG_SAR0_CSR5
#define ADC_ADC_SAR__CSR6 CYREG_SAR0_CSR6
#define ADC_ADC_SAR__PM_ACT_CFG CYREG_PM_ACT_CFG11
#define ADC_ADC_SAR__PM_ACT_MSK 0x01u
#define ADC_ADC_SAR__PM_STBY_CFG CYREG_PM_STBY_CFG11
#define ADC_ADC_SAR__PM_STBY_MSK 0x01u
#define ADC_ADC_SAR__SW0 CYREG_SAR0_SW0
#define ADC_ADC_SAR__SW2 CYREG_SAR0_SW2
#define ADC_ADC_SAR__SW3 CYREG_SAR0_SW3
#define ADC_ADC_SAR__SW4 CYREG_SAR0_SW4
#define ADC_ADC_SAR__SW6 CYREG_SAR0_SW6
#define ADC_ADC_SAR__TR0 CYREG_SAR0_TR0
#define ADC_ADC_SAR__WRK0 CYREG_SAR0_WRK0
#define ADC_ADC_SAR__WRK1 CYREG_SAR0_WRK1
#define ADC_IRQ__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define ADC_IRQ__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define ADC_IRQ__INTC_MASK 0x02u
#define ADC_IRQ__INTC_NUMBER 1u
#define ADC_IRQ__INTC_PRIOR_NUM 7u
#define ADC_IRQ__INTC_PRIOR_REG CYREG_NVIC_PRI_1
#define ADC_IRQ__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define ADC_IRQ__INTC_SET_PD_REG CYREG_NVIC_SETPEND0
#define ADC_theACLK__CFG0 CYREG_CLKDIST_ACFG0_CFG0
#define ADC_theACLK__CFG1 CYREG_CLKDIST_ACFG0_CFG1
#define ADC_theACLK__CFG2 CYREG_CLKDIST_ACFG0_CFG2
#define ADC_theACLK__CFG2_SRC_SEL_MASK 0x07u
#define ADC_theACLK__CFG3 CYREG_CLKDIST_ACFG0_CFG3
#define ADC_theACLK__CFG3_PHASE_DLY_MASK 0x0Fu
#define ADC_theACLK__INDEX 0x00u
#define ADC_theACLK__PM_ACT_CFG CYREG_PM_ACT_CFG1
#define ADC_theACLK__PM_ACT_MSK 0x01u
#define ADC_theACLK__PM_STBY_CFG CYREG_PM_STBY_CFG1
#define ADC_theACLK__PM_STBY_MSK 0x01u

/* CLK */
#define CLK__CFG0 CYREG_CLKDIST_DCFG1_CFG0
#define CLK__CFG1 CYREG_CLKDIST_DCFG1_CFG1
#define CLK__CFG2 CYREG_CLKDIST_DCFG1_CFG2
#define CLK__CFG2_SRC_SEL_MASK 0x07u
#define CLK__INDEX 0x01u
#define CLK__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define CLK__PM_ACT_MSK 0x02u
#define CLK__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define CLK__PM_STBY_MSK 0x02u

/* LED */
#define LED__0__INTTYPE CYREG_PICU2_INTTYPE1
#define LED__0__MASK 0x02u
#define LED__0__PC CYREG_PRT2_PC1
#define LED__0__PORT 2u
#define LED__0__SHIFT 1u
#define LED__AG CYREG_PRT2_AG
#define LED__AMUX CYREG_PRT2_AMUX
#define LED__BIE CYREG_PRT2_BIE
#define LED__BIT_MASK CYREG_PRT2_BIT_MASK
#define LED__BYP CYREG_PRT2_BYP
#define LED__CTL CYREG_PRT2_CTL
#define LED__DM0 CYREG_PRT2_DM0
#define LED__DM1 CYREG_PRT2_DM1
#define LED__DM2 CYREG_PRT2_DM2
#define LED__DR CYREG_PRT2_DR
#define LED__INP_DIS CYREG_PRT2_INP_DIS
#define LED__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define LED__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define LED__LCD_EN CYREG_PRT2_LCD_EN
#define LED__MASK 0x02u
#define LED__PORT 2u
#define LED__PRT CYREG_PRT2_PRT
#define LED__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define LED__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define LED__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define LED__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define LED__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define LED__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define LED__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define LED__PS CYREG_PRT2_PS
#define LED__SHIFT 1u
#define LED__SLW CYREG_PRT2_SLW

/* PWM */
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB04_05_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB04_05_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_COUNT_COUNT_REG CYREG_B0_UDB04_05_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_MASK_REG CYREG_B0_UDB04_05_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_MASK_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_MASK_REG CYREG_B0_UDB04_05_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB04_05_MSK
#define PWM_PWMUDB_genblk1_ctrlreg__7__MASK 0x80u
#define PWM_PWMUDB_genblk1_ctrlreg__7__POS 7
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_REG CYREG_B0_UDB04_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__CONTROL_ST_REG CYREG_B0_UDB04_ST_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__COUNT_REG CYREG_B0_UDB04_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__COUNT_ST_REG CYREG_B0_UDB04_ST_CTL
#define PWM_PWMUDB_genblk1_ctrlreg__MASK 0x80u
#define PWM_PWMUDB_genblk1_ctrlreg__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__PER_CTL_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define PWM_PWMUDB_genblk1_ctrlreg__PERIOD_REG CYREG_B0_UDB04_MSK
#define PWM_PWMUDB_genblk8_stsreg__0__MASK 0x01u
#define PWM_PWMUDB_genblk8_stsreg__0__POS 0
#define PWM_PWMUDB_genblk8_stsreg__1__MASK 0x02u
#define PWM_PWMUDB_genblk8_stsreg__1__POS 1
#define PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define PWM_PWMUDB_genblk8_stsreg__16BIT_STATUS_REG CYREG_B0_UDB05_06_ST
#define PWM_PWMUDB_genblk8_stsreg__2__MASK 0x04u
#define PWM_PWMUDB_genblk8_stsreg__2__POS 2
#define PWM_PWMUDB_genblk8_stsreg__3__MASK 0x08u
#define PWM_PWMUDB_genblk8_stsreg__3__POS 3
#define PWM_PWMUDB_genblk8_stsreg__MASK 0x0Fu
#define PWM_PWMUDB_genblk8_stsreg__MASK_REG CYREG_B0_UDB05_MSK
#define PWM_PWMUDB_genblk8_stsreg__STATUS_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define PWM_PWMUDB_genblk8_stsreg__STATUS_REG CYREG_B0_UDB05_ST
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A0_REG CYREG_B0_UDB05_06_A0
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_A1_REG CYREG_B0_UDB05_06_A1
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D0_REG CYREG_B0_UDB05_06_D0
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_D1_REG CYREG_B0_UDB05_06_D1
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB05_06_ACTL
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F0_REG CYREG_B0_UDB05_06_F0
#define PWM_PWMUDB_sP8_pwmdp_u0__16BIT_F1_REG CYREG_B0_UDB05_06_F1
#define PWM_PWMUDB_sP8_pwmdp_u0__A0_A1_REG CYREG_B0_UDB05_A0_A1
#define PWM_PWMUDB_sP8_pwmdp_u0__A0_REG CYREG_B0_UDB05_A0
#define PWM_PWMUDB_sP8_pwmdp_u0__A1_REG CYREG_B0_UDB05_A1
#define PWM_PWMUDB_sP8_pwmdp_u0__D0_D1_REG CYREG_B0_UDB05_D0_D1
#define PWM_PWMUDB_sP8_pwmdp_u0__D0_REG CYREG_B0_UDB05_D0
#define PWM_PWMUDB_sP8_pwmdp_u0__D1_REG CYREG_B0_UDB05_D1
#define PWM_PWMUDB_sP8_pwmdp_u0__DP_AUX_CTL_REG CYREG_B0_UDB05_ACTL
#define PWM_PWMUDB_sP8_pwmdp_u0__F0_F1_REG CYREG_B0_UDB05_F0_F1
#define PWM_PWMUDB_sP8_pwmdp_u0__F0_REG CYREG_B0_UDB05_F0
#define PWM_PWMUDB_sP8_pwmdp_u0__F1_REG CYREG_B0_UDB05_F1

/* Rx_1 */
#define Rx_1__0__INTTYPE CYREG_PICU3_INTTYPE0
#define Rx_1__0__MASK 0x01u
#define Rx_1__0__PC CYREG_PRT3_PC0
#define Rx_1__0__PORT 3u
#define Rx_1__0__SHIFT 0u
#define Rx_1__AG CYREG_PRT3_AG
#define Rx_1__AMUX CYREG_PRT3_AMUX
#define Rx_1__BIE CYREG_PRT3_BIE
#define Rx_1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Rx_1__BYP CYREG_PRT3_BYP
#define Rx_1__CTL CYREG_PRT3_CTL
#define Rx_1__DM0 CYREG_PRT3_DM0
#define Rx_1__DM1 CYREG_PRT3_DM1
#define Rx_1__DM2 CYREG_PRT3_DM2
#define Rx_1__DR CYREG_PRT3_DR
#define Rx_1__INP_DIS CYREG_PRT3_INP_DIS
#define Rx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Rx_1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Rx_1__LCD_EN CYREG_PRT3_LCD_EN
#define Rx_1__MASK 0x01u
#define Rx_1__PORT 3u
#define Rx_1__PRT CYREG_PRT3_PRT
#define Rx_1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Rx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Rx_1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Rx_1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Rx_1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Rx_1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Rx_1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Rx_1__PS CYREG_PRT3_PS
#define Rx_1__SHIFT 0u
#define Rx_1__SLW CYREG_PRT3_SLW

/* Tx_1 */
#define Tx_1__0__INTTYPE CYREG_PICU3_INTTYPE1
#define Tx_1__0__MASK 0x02u
#define Tx_1__0__PC CYREG_PRT3_PC1
#define Tx_1__0__PORT 3u
#define Tx_1__0__SHIFT 1u
#define Tx_1__AG CYREG_PRT3_AG
#define Tx_1__AMUX CYREG_PRT3_AMUX
#define Tx_1__BIE CYREG_PRT3_BIE
#define Tx_1__BIT_MASK CYREG_PRT3_BIT_MASK
#define Tx_1__BYP CYREG_PRT3_BYP
#define Tx_1__CTL CYREG_PRT3_CTL
#define Tx_1__DM0 CYREG_PRT3_DM0
#define Tx_1__DM1 CYREG_PRT3_DM1
#define Tx_1__DM2 CYREG_PRT3_DM2
#define Tx_1__DR CYREG_PRT3_DR
#define Tx_1__INP_DIS CYREG_PRT3_INP_DIS
#define Tx_1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU3_BASE
#define Tx_1__LCD_COM_SEG CYREG_PRT3_LCD_COM_SEG
#define Tx_1__LCD_EN CYREG_PRT3_LCD_EN
#define Tx_1__MASK 0x02u
#define Tx_1__PORT 3u
#define Tx_1__PRT CYREG_PRT3_PRT
#define Tx_1__PRTDSI__CAPS_SEL CYREG_PRT3_CAPS_SEL
#define Tx_1__PRTDSI__DBL_SYNC_IN CYREG_PRT3_DBL_SYNC_IN
#define Tx_1__PRTDSI__OE_SEL0 CYREG_PRT3_OE_SEL0
#define Tx_1__PRTDSI__OE_SEL1 CYREG_PRT3_OE_SEL1
#define Tx_1__PRTDSI__OUT_SEL0 CYREG_PRT3_OUT_SEL0
#define Tx_1__PRTDSI__OUT_SEL1 CYREG_PRT3_OUT_SEL1
#define Tx_1__PRTDSI__SYNC_OUT CYREG_PRT3_SYNC_OUT
#define Tx_1__PS CYREG_PRT3_PS
#define Tx_1__SHIFT 1u
#define Tx_1__SLW CYREG_PRT3_SLW

/* UART */
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_CONTROL_COUNT_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_CONTROL_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_COUNT_COUNT_REG CYREG_B0_UDB06_07_CTL
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_MASK_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_MASK_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_MASK_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__16BIT_PERIOD_PERIOD_REG CYREG_B0_UDB06_07_MSK
#define UART_BUART_sRX_RxBitCounter__CONTROL_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_REG CYREG_B0_UDB06_CTL
#define UART_BUART_sRX_RxBitCounter__CONTROL_ST_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_REG CYREG_B0_UDB06_CTL
#define UART_BUART_sRX_RxBitCounter__COUNT_ST_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter__MASK_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PER_CTL_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter__PERIOD_REG CYREG_B0_UDB06_MSK
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_AUX_CTL_REG CYREG_B0_UDB06_07_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__16BIT_STATUS_REG CYREG_B0_UDB06_07_ST
#define UART_BUART_sRX_RxBitCounter_ST__MASK_REG CYREG_B0_UDB06_MSK
#define UART_BUART_sRX_RxBitCounter_ST__MASK_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__PER_ST_AUX_CTL_REG CYREG_B0_UDB06_MSK_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_AUX_CTL_REG CYREG_B0_UDB06_ACTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CNT_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_CONTROL_REG CYREG_B0_UDB06_ST_CTL
#define UART_BUART_sRX_RxBitCounter_ST__STATUS_REG CYREG_B0_UDB06_ST
#define UART_BUART_sRX_RxShifter_u0__16BIT_A0_REG CYREG_B1_UDB06_07_A0
#define UART_BUART_sRX_RxShifter_u0__16BIT_A1_REG CYREG_B1_UDB06_07_A1
#define UART_BUART_sRX_RxShifter_u0__16BIT_D0_REG CYREG_B1_UDB06_07_D0
#define UART_BUART_sRX_RxShifter_u0__16BIT_D1_REG CYREG_B1_UDB06_07_D1
#define UART_BUART_sRX_RxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define UART_BUART_sRX_RxShifter_u0__16BIT_F0_REG CYREG_B1_UDB06_07_F0
#define UART_BUART_sRX_RxShifter_u0__16BIT_F1_REG CYREG_B1_UDB06_07_F1
#define UART_BUART_sRX_RxShifter_u0__A0_A1_REG CYREG_B1_UDB06_A0_A1
#define UART_BUART_sRX_RxShifter_u0__A0_REG CYREG_B1_UDB06_A0
#define UART_BUART_sRX_RxShifter_u0__A1_REG CYREG_B1_UDB06_A1
#define UART_BUART_sRX_RxShifter_u0__D0_D1_REG CYREG_B1_UDB06_D0_D1
#define UART_BUART_sRX_RxShifter_u0__D0_REG CYREG_B1_UDB06_D0
#define UART_BUART_sRX_RxShifter_u0__D1_REG CYREG_B1_UDB06_D1
#define UART_BUART_sRX_RxShifter_u0__DP_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define UART_BUART_sRX_RxShifter_u0__F0_F1_REG CYREG_B1_UDB06_F0_F1
#define UART_BUART_sRX_RxShifter_u0__F0_REG CYREG_B1_UDB06_F0
#define UART_BUART_sRX_RxShifter_u0__F1_REG CYREG_B1_UDB06_F1
#define UART_BUART_sRX_RxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB06_07_ACTL
#define UART_BUART_sRX_RxSts__16BIT_STATUS_REG CYREG_B1_UDB06_07_ST
#define UART_BUART_sRX_RxSts__3__MASK 0x08u
#define UART_BUART_sRX_RxSts__3__POS 3
#define UART_BUART_sRX_RxSts__4__MASK 0x10u
#define UART_BUART_sRX_RxSts__4__POS 4
#define UART_BUART_sRX_RxSts__5__MASK 0x20u
#define UART_BUART_sRX_RxSts__5__POS 5
#define UART_BUART_sRX_RxSts__MASK 0x38u
#define UART_BUART_sRX_RxSts__MASK_REG CYREG_B1_UDB06_MSK
#define UART_BUART_sRX_RxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB06_ACTL
#define UART_BUART_sRX_RxSts__STATUS_REG CYREG_B1_UDB06_ST
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A0_REG CYREG_B0_UDB04_05_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_A1_REG CYREG_B0_UDB04_05_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D0_REG CYREG_B0_UDB04_05_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_D1_REG CYREG_B0_UDB04_05_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_DP_AUX_CTL_REG CYREG_B0_UDB04_05_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F0_REG CYREG_B0_UDB04_05_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__16BIT_F1_REG CYREG_B0_UDB04_05_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_A1_REG CYREG_B0_UDB04_A0_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A0_REG CYREG_B0_UDB04_A0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__A1_REG CYREG_B0_UDB04_A1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_D1_REG CYREG_B0_UDB04_D0_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D0_REG CYREG_B0_UDB04_D0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__D1_REG CYREG_B0_UDB04_D1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__DP_AUX_CTL_REG CYREG_B0_UDB04_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_F1_REG CYREG_B0_UDB04_F0_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F0_REG CYREG_B0_UDB04_F0
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__F1_REG CYREG_B0_UDB04_F1
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__MSK_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UART_BUART_sTX_sCLOCK_TxBitClkGen__PER_DP_AUX_CTL_REG CYREG_B0_UDB04_MSK_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_A0_REG CYREG_B1_UDB04_05_A0
#define UART_BUART_sTX_TxShifter_u0__16BIT_A1_REG CYREG_B1_UDB04_05_A1
#define UART_BUART_sTX_TxShifter_u0__16BIT_D0_REG CYREG_B1_UDB04_05_D0
#define UART_BUART_sTX_TxShifter_u0__16BIT_D1_REG CYREG_B1_UDB04_05_D1
#define UART_BUART_sTX_TxShifter_u0__16BIT_DP_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define UART_BUART_sTX_TxShifter_u0__16BIT_F0_REG CYREG_B1_UDB04_05_F0
#define UART_BUART_sTX_TxShifter_u0__16BIT_F1_REG CYREG_B1_UDB04_05_F1
#define UART_BUART_sTX_TxShifter_u0__A0_A1_REG CYREG_B1_UDB04_A0_A1
#define UART_BUART_sTX_TxShifter_u0__A0_REG CYREG_B1_UDB04_A0
#define UART_BUART_sTX_TxShifter_u0__A1_REG CYREG_B1_UDB04_A1
#define UART_BUART_sTX_TxShifter_u0__D0_D1_REG CYREG_B1_UDB04_D0_D1
#define UART_BUART_sTX_TxShifter_u0__D0_REG CYREG_B1_UDB04_D0
#define UART_BUART_sTX_TxShifter_u0__D1_REG CYREG_B1_UDB04_D1
#define UART_BUART_sTX_TxShifter_u0__DP_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define UART_BUART_sTX_TxShifter_u0__F0_F1_REG CYREG_B1_UDB04_F0_F1
#define UART_BUART_sTX_TxShifter_u0__F0_REG CYREG_B1_UDB04_F0
#define UART_BUART_sTX_TxShifter_u0__F1_REG CYREG_B1_UDB04_F1
#define UART_BUART_sTX_TxSts__0__MASK 0x01u
#define UART_BUART_sTX_TxSts__0__POS 0
#define UART_BUART_sTX_TxSts__1__MASK 0x02u
#define UART_BUART_sTX_TxSts__1__POS 1
#define UART_BUART_sTX_TxSts__16BIT_STATUS_AUX_CTL_REG CYREG_B1_UDB04_05_ACTL
#define UART_BUART_sTX_TxSts__16BIT_STATUS_REG CYREG_B1_UDB04_05_ST
#define UART_BUART_sTX_TxSts__2__MASK 0x04u
#define UART_BUART_sTX_TxSts__2__POS 2
#define UART_BUART_sTX_TxSts__3__MASK 0x08u
#define UART_BUART_sTX_TxSts__3__POS 3
#define UART_BUART_sTX_TxSts__MASK 0x0Fu
#define UART_BUART_sTX_TxSts__MASK_REG CYREG_B1_UDB04_MSK
#define UART_BUART_sTX_TxSts__STATUS_AUX_CTL_REG CYREG_B1_UDB04_ACTL
#define UART_BUART_sTX_TxSts__STATUS_REG CYREG_B1_UDB04_ST
#define UART_IntClock__CFG0 CYREG_CLKDIST_DCFG0_CFG0
#define UART_IntClock__CFG1 CYREG_CLKDIST_DCFG0_CFG1
#define UART_IntClock__CFG2 CYREG_CLKDIST_DCFG0_CFG2
#define UART_IntClock__CFG2_SRC_SEL_MASK 0x07u
#define UART_IntClock__INDEX 0x00u
#define UART_IntClock__PM_ACT_CFG CYREG_PM_ACT_CFG2
#define UART_IntClock__PM_ACT_MSK 0x01u
#define UART_IntClock__PM_STBY_CFG CYREG_PM_STBY_CFG2
#define UART_IntClock__PM_STBY_MSK 0x01u

/* IRQRX */
#define IRQRX__INTC_CLR_EN_REG CYREG_NVIC_CLRENA0
#define IRQRX__INTC_CLR_PD_REG CYREG_NVIC_CLRPEND0
#define IRQRX__INTC_MASK 0x01u
#define IRQRX__INTC_NUMBER 0u
#define IRQRX__INTC_PRIOR_NUM 7u
#define IRQRX__INTC_PRIOR_REG CYREG_NVIC_PRI_0
#define IRQRX__INTC_SET_EN_REG CYREG_NVIC_SETENA0
#define IRQRX__INTC_SET_PD_REG CYREG_NVIC_SETPEND0

/* Motor1 */
#define Motor1__0__INTTYPE CYREG_PICU2_INTTYPE2
#define Motor1__0__MASK 0x04u
#define Motor1__0__PC CYREG_PRT2_PC2
#define Motor1__0__PORT 2u
#define Motor1__0__SHIFT 2u
#define Motor1__AG CYREG_PRT2_AG
#define Motor1__AMUX CYREG_PRT2_AMUX
#define Motor1__BIE CYREG_PRT2_BIE
#define Motor1__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor1__BYP CYREG_PRT2_BYP
#define Motor1__CTL CYREG_PRT2_CTL
#define Motor1__DM0 CYREG_PRT2_DM0
#define Motor1__DM1 CYREG_PRT2_DM1
#define Motor1__DM2 CYREG_PRT2_DM2
#define Motor1__DR CYREG_PRT2_DR
#define Motor1__INP_DIS CYREG_PRT2_INP_DIS
#define Motor1__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor1__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor1__LCD_EN CYREG_PRT2_LCD_EN
#define Motor1__MASK 0x04u
#define Motor1__PORT 2u
#define Motor1__PRT CYREG_PRT2_PRT
#define Motor1__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor1__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor1__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor1__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor1__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor1__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor1__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor1__PS CYREG_PRT2_PS
#define Motor1__SHIFT 2u
#define Motor1__SLW CYREG_PRT2_SLW

/* Motor2 */
#define Motor2__0__INTTYPE CYREG_PICU2_INTTYPE3
#define Motor2__0__MASK 0x08u
#define Motor2__0__PC CYREG_PRT2_PC3
#define Motor2__0__PORT 2u
#define Motor2__0__SHIFT 3u
#define Motor2__AG CYREG_PRT2_AG
#define Motor2__AMUX CYREG_PRT2_AMUX
#define Motor2__BIE CYREG_PRT2_BIE
#define Motor2__BIT_MASK CYREG_PRT2_BIT_MASK
#define Motor2__BYP CYREG_PRT2_BYP
#define Motor2__CTL CYREG_PRT2_CTL
#define Motor2__DM0 CYREG_PRT2_DM0
#define Motor2__DM1 CYREG_PRT2_DM1
#define Motor2__DM2 CYREG_PRT2_DM2
#define Motor2__DR CYREG_PRT2_DR
#define Motor2__INP_DIS CYREG_PRT2_INP_DIS
#define Motor2__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Motor2__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Motor2__LCD_EN CYREG_PRT2_LCD_EN
#define Motor2__MASK 0x08u
#define Motor2__PORT 2u
#define Motor2__PRT CYREG_PRT2_PRT
#define Motor2__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Motor2__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Motor2__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Motor2__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Motor2__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Motor2__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Motor2__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Motor2__PS CYREG_PRT2_PS
#define Motor2__SHIFT 3u
#define Motor2__SLW CYREG_PRT2_SLW

/* Pin_ADC */
#define Pin_ADC__0__INTTYPE CYREG_PICU2_INTTYPE7
#define Pin_ADC__0__MASK 0x80u
#define Pin_ADC__0__PC CYREG_PRT2_PC7
#define Pin_ADC__0__PORT 2u
#define Pin_ADC__0__SHIFT 7u
#define Pin_ADC__AG CYREG_PRT2_AG
#define Pin_ADC__AMUX CYREG_PRT2_AMUX
#define Pin_ADC__BIE CYREG_PRT2_BIE
#define Pin_ADC__BIT_MASK CYREG_PRT2_BIT_MASK
#define Pin_ADC__BYP CYREG_PRT2_BYP
#define Pin_ADC__CTL CYREG_PRT2_CTL
#define Pin_ADC__DM0 CYREG_PRT2_DM0
#define Pin_ADC__DM1 CYREG_PRT2_DM1
#define Pin_ADC__DM2 CYREG_PRT2_DM2
#define Pin_ADC__DR CYREG_PRT2_DR
#define Pin_ADC__INP_DIS CYREG_PRT2_INP_DIS
#define Pin_ADC__INTTYPE_BASE CYDEV_PICU_INTTYPE_PICU2_BASE
#define Pin_ADC__LCD_COM_SEG CYREG_PRT2_LCD_COM_SEG
#define Pin_ADC__LCD_EN CYREG_PRT2_LCD_EN
#define Pin_ADC__MASK 0x80u
#define Pin_ADC__PORT 2u
#define Pin_ADC__PRT CYREG_PRT2_PRT
#define Pin_ADC__PRTDSI__CAPS_SEL CYREG_PRT2_CAPS_SEL
#define Pin_ADC__PRTDSI__DBL_SYNC_IN CYREG_PRT2_DBL_SYNC_IN
#define Pin_ADC__PRTDSI__OE_SEL0 CYREG_PRT2_OE_SEL0
#define Pin_ADC__PRTDSI__OE_SEL1 CYREG_PRT2_OE_SEL1
#define Pin_ADC__PRTDSI__OUT_SEL0 CYREG_PRT2_OUT_SEL0
#define Pin_ADC__PRTDSI__OUT_SEL1 CYREG_PRT2_OUT_SEL1
#define Pin_ADC__PRTDSI__SYNC_OUT CYREG_PRT2_SYNC_OUT
#define Pin_ADC__PS CYREG_PRT2_PS
#define Pin_ADC__SHIFT 7u
#define Pin_ADC__SLW CYREG_PRT2_SLW

/* Miscellaneous */
#define BCLK__BUS_CLK__HZ 24000000U
#define BCLK__BUS_CLK__KHZ 24000U
#define BCLK__BUS_CLK__MHZ 24U
#define CY_PROJECT_NAME "Prototipo"
#define CY_VERSION "PSoC Creator  4.2"
#define CYDEV_CHIP_DIE_LEOPARD 1u
#define CYDEV_CHIP_DIE_PSOC4A 18u
#define CYDEV_CHIP_DIE_PSOC5LP 2u
#define CYDEV_CHIP_DIE_PSOC5TM 3u
#define CYDEV_CHIP_DIE_TMA4 4u
#define CYDEV_CHIP_DIE_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_FM0P 5u
#define CYDEV_CHIP_FAMILY_FM3 6u
#define CYDEV_CHIP_FAMILY_FM4 7u
#define CYDEV_CHIP_FAMILY_PSOC3 1u
#define CYDEV_CHIP_FAMILY_PSOC4 2u
#define CYDEV_CHIP_FAMILY_PSOC5 3u
#define CYDEV_CHIP_FAMILY_PSOC6 4u
#define CYDEV_CHIP_FAMILY_UNKNOWN 0u
#define CYDEV_CHIP_FAMILY_USED CYDEV_CHIP_FAMILY_PSOC5
#define CYDEV_CHIP_JTAG_ID 0x2E161069u
#define CYDEV_CHIP_MEMBER_3A 1u
#define CYDEV_CHIP_MEMBER_4A 18u
#define CYDEV_CHIP_MEMBER_4D 13u
#define CYDEV_CHIP_MEMBER_4E 6u
#define CYDEV_CHIP_MEMBER_4F 19u
#define CYDEV_CHIP_MEMBER_4G 4u
#define CYDEV_CHIP_MEMBER_4H 17u
#define CYDEV_CHIP_MEMBER_4I 23u
#define CYDEV_CHIP_MEMBER_4J 14u
#define CYDEV_CHIP_MEMBER_4K 15u
#define CYDEV_CHIP_MEMBER_4L 22u
#define CYDEV_CHIP_MEMBER_4M 21u
#define CYDEV_CHIP_MEMBER_4N 10u
#define CYDEV_CHIP_MEMBER_4O 7u
#define CYDEV_CHIP_MEMBER_4P 20u
#define CYDEV_CHIP_MEMBER_4Q 12u
#define CYDEV_CHIP_MEMBER_4R 8u
#define CYDEV_CHIP_MEMBER_4S 11u
#define CYDEV_CHIP_MEMBER_4T 9u
#define CYDEV_CHIP_MEMBER_4U 5u
#define CYDEV_CHIP_MEMBER_4V 16u
#define CYDEV_CHIP_MEMBER_5A 3u
#define CYDEV_CHIP_MEMBER_5B 2u
#define CYDEV_CHIP_MEMBER_6A 24u
#define CYDEV_CHIP_MEMBER_FM3 28u
#define CYDEV_CHIP_MEMBER_FM4 29u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE1 25u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE2 26u
#define CYDEV_CHIP_MEMBER_PDL_FM0P_TYPE3 27u
#define CYDEV_CHIP_MEMBER_UNKNOWN 0u
#define CYDEV_CHIP_MEMBER_USED CYDEV_CHIP_MEMBER_5B
#define CYDEV_CHIP_DIE_EXPECT CYDEV_CHIP_MEMBER_USED
#define CYDEV_CHIP_DIE_ACTUAL CYDEV_CHIP_DIE_EXPECT
#define CYDEV_CHIP_REV_LEOPARD_ES1 0u
#define CYDEV_CHIP_REV_LEOPARD_ES2 1u
#define CYDEV_CHIP_REV_LEOPARD_ES3 3u
#define CYDEV_CHIP_REV_LEOPARD_PRODUCTION 3u
#define CYDEV_CHIP_REV_PSOC4A_ES0 17u
#define CYDEV_CHIP_REV_PSOC4A_PRODUCTION 17u
#define CYDEV_CHIP_REV_PSOC5LP_ES0 0u
#define CYDEV_CHIP_REV_PSOC5LP_PRODUCTION 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES0 0u
#define CYDEV_CHIP_REV_PSOC5TM_ES1 1u
#define CYDEV_CHIP_REV_PSOC5TM_PRODUCTION 1u
#define CYDEV_CHIP_REV_TMA4_ES 17u
#define CYDEV_CHIP_REV_TMA4_ES2 33u
#define CYDEV_CHIP_REV_TMA4_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_3A_ES1 0u
#define CYDEV_CHIP_REVISION_3A_ES2 1u
#define CYDEV_CHIP_REVISION_3A_ES3 3u
#define CYDEV_CHIP_REVISION_3A_PRODUCTION 3u
#define CYDEV_CHIP_REVISION_4A_ES0 17u
#define CYDEV_CHIP_REVISION_4A_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4D_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4E_CCG2_NO_USBPD 0u
#define CYDEV_CHIP_REVISION_4E_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256DMA 0u
#define CYDEV_CHIP_REVISION_4F_PRODUCTION_256K 0u
#define CYDEV_CHIP_REVISION_4G_ES 17u
#define CYDEV_CHIP_REVISION_4G_ES2 33u
#define CYDEV_CHIP_REVISION_4G_PRODUCTION 17u
#define CYDEV_CHIP_REVISION_4H_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4I_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4J_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4K_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4L_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4M_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4N_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4O_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4P_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4Q_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4R_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4S_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4T_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4U_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_4V_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_5A_ES0 0u
#define CYDEV_CHIP_REVISION_5A_ES1 1u
#define CYDEV_CHIP_REVISION_5A_PRODUCTION 1u
#define CYDEV_CHIP_REVISION_5B_ES0 0u
#define CYDEV_CHIP_REVISION_5B_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_6A_ES 17u
#define CYDEV_CHIP_REVISION_6A_NO_UDB 33u
#define CYDEV_CHIP_REVISION_6A_PRODUCTION 33u
#define CYDEV_CHIP_REVISION_FM3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_FM4_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE1_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE2_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_PDL_FM0P_TYPE3_PRODUCTION 0u
#define CYDEV_CHIP_REVISION_USED CYDEV_CHIP_REVISION_5B_PRODUCTION
#define CYDEV_CHIP_REV_EXPECT CYDEV_CHIP_REVISION_USED
#define CYDEV_CONFIG_FASTBOOT_ENABLED 1
#define CYDEV_CONFIG_UNUSED_IO_AllowButWarn 0
#define CYDEV_CONFIG_UNUSED_IO CYDEV_CONFIG_UNUSED_IO_AllowButWarn
#define CYDEV_CONFIG_UNUSED_IO_AllowWithInfo 1
#define CYDEV_CONFIG_UNUSED_IO_Disallowed 2
#define CYDEV_CONFIGURATION_COMPRESSED 1
#define CYDEV_CONFIGURATION_DMA 0
#define CYDEV_CONFIGURATION_ECC 1
#define CYDEV_CONFIGURATION_IMOENABLED CYDEV_CONFIG_FASTBOOT_ENABLED
#define CYDEV_CONFIGURATION_MODE_COMPRESSED 0
#define CYDEV_CONFIGURATION_MODE CYDEV_CONFIGURATION_MODE_COMPRESSED
#define CYDEV_CONFIGURATION_MODE_DMA 2
#define CYDEV_CONFIGURATION_MODE_UNCOMPRESSED 1
#define CYDEV_DEBUG_ENABLE_MASK 0x20u
#define CYDEV_DEBUG_ENABLE_REGISTER CYREG_MLOGIC_DEBUG
#define CYDEV_DEBUGGING_DPS_Disable 3
#define CYDEV_DEBUGGING_DPS_JTAG_4 1
#define CYDEV_DEBUGGING_DPS_JTAG_5 0
#define CYDEV_DEBUGGING_DPS_SWD 2
#define CYDEV_DEBUGGING_DPS_SWD_SWV 6
#define CYDEV_DEBUGGING_DPS CYDEV_DEBUGGING_DPS_SWD_SWV
#define CYDEV_DEBUGGING_ENABLE 1
#define CYDEV_DEBUGGING_XRES 0
#define CYDEV_DMA_CHANNELS_AVAILABLE 24u
#define CYDEV_ECC_ENABLE 0
#define CYDEV_HEAP_SIZE 0x80
#define CYDEV_INSTRUCT_CACHE_ENABLED 1
#define CYDEV_INTR_RISING 0x00000003u
#define CYDEV_IS_EXPORTING_CODE 0
#define CYDEV_IS_IMPORTING_CODE 0
#define CYDEV_PROJ_TYPE 0
#define CYDEV_PROJ_TYPE_BOOTLOADER 1
#define CYDEV_PROJ_TYPE_LAUNCHER 5
#define CYDEV_PROJ_TYPE_LOADABLE 2
#define CYDEV_PROJ_TYPE_LOADABLEANDBOOTLOADER 4
#define CYDEV_PROJ_TYPE_MULTIAPPBOOTLOADER 3
#define CYDEV_PROJ_TYPE_STANDARD 0
#define CYDEV_PROTECTION_ENABLE 0
#define CYDEV_STACK_SIZE 0x0800
#define CYDEV_USE_BUNDLED_CMSIS 1
#define CYDEV_VARIABLE_VDDA 0
#define CYDEV_VDDA 5.0
#define CYDEV_VDDA_MV 5000
#define CYDEV_VDDD 5.0
#define CYDEV_VDDD_MV 5000
#define CYDEV_VDDIO0 5.0
#define CYDEV_VDDIO0_MV 5000
#define CYDEV_VDDIO1 5.0
#define CYDEV_VDDIO1_MV 5000
#define CYDEV_VDDIO2 5.0
#define CYDEV_VDDIO2_MV 5000
#define CYDEV_VDDIO3 5.0
#define CYDEV_VDDIO3_MV 5000
#define CYDEV_VIO0 5.0
#define CYDEV_VIO0_MV 5000
#define CYDEV_VIO1 5.0
#define CYDEV_VIO1_MV 5000
#define CYDEV_VIO2 5.0
#define CYDEV_VIO2_MV 5000
#define CYDEV_VIO3 5.0
#define CYDEV_VIO3_MV 5000
#define CYIPBLOCK_ARM_CM3_VERSION 0
#define CYIPBLOCK_P3_ANAIF_VERSION 0
#define CYIPBLOCK_P3_CAN_VERSION 0
#define CYIPBLOCK_P3_CAPSENSE_VERSION 0
#define CYIPBLOCK_P3_COMP_VERSION 0
#define CYIPBLOCK_P3_DECIMATOR_VERSION 0
#define CYIPBLOCK_P3_DFB_VERSION 0
#define CYIPBLOCK_P3_DMA_VERSION 0
#define CYIPBLOCK_P3_DRQ_VERSION 0
#define CYIPBLOCK_P3_DSM_VERSION 0
#define CYIPBLOCK_P3_EMIF_VERSION 0
#define CYIPBLOCK_P3_I2C_VERSION 0
#define CYIPBLOCK_P3_LCD_VERSION 0
#define CYIPBLOCK_P3_LPF_VERSION 0
#define CYIPBLOCK_P3_OPAMP_VERSION 0
#define CYIPBLOCK_P3_PM_VERSION 0
#define CYIPBLOCK_P3_SCCT_VERSION 0
#define CYIPBLOCK_P3_TIMER_VERSION 0
#define CYIPBLOCK_P3_USB_VERSION 0
#define CYIPBLOCK_P3_VIDAC_VERSION 0
#define CYIPBLOCK_P3_VREF_VERSION 0
#define CYIPBLOCK_S8_GPIO_VERSION 0
#define CYIPBLOCK_S8_IRQ_VERSION 0
#define CYIPBLOCK_S8_SAR_VERSION 0
#define CYIPBLOCK_S8_SIO_VERSION 0
#define CYIPBLOCK_S8_UDB_VERSION 0
#define DMA_CHANNELS_USED__MASK0 0x00000000u
#define CYDEV_BOOTLOADER_ENABLE 0

#endif /* INCLUDED_CYFITTER_H */
