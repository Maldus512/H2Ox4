/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: GPIO.c                                                            */
/*                                                                            */
/*      SetUp STATO di tutti i BIT utilizzati nell' HW                        */
/*                                                                            */
/*  Autore: Sabbiolino (Fabio BARALDI) & Massimo ZANNA                        */
/*                                                                            */
/*  Data  : 01/05/2016      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 29/03/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"





void Init_GPIO(void)
{
    SONDA1_TRIS = IN;
    SONDA2_TRIS = IN;
    SONDA3_TRIS = IN;
    SONDA4_TRIS = IN;
    
    DIPSWITCH1_TRIS = IN;
    DIPSWITCH2_TRIS = IN;
    DIPSWITCH3_TRIS = IN;
    DIPSWITCH4_TRIS = IN;

    
    
    RELE1_TRIS = OUT;
    RELE2_TRIS = OUT;
    RELE3_TRIS = OUT;
    RELE4_TRIS = OUT;
    RELE1 = 0;
    RELE2 = 0;
    RELE3 = 0;
    RELE4 = 0;
    
    LED1_TRIS = OUT;
    LED2_TRIS = OUT;
    LED3_TRIS = OUT;
    LED4_TRIS = OUT;
    LED5_TRIS = OUT;    
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;

    PWM1_TRIS = OUT;
    PWM2_TRIS = OUT;
    PWM3_TRIS = OUT;
    PWM4_TRIS = OUT;
    PWM1 = 0;
    PWM2 = 0;
    PWM3 = 0;
    PWM4 = 0;
    
    
    
    // DISABILITO AD NEI BIT CHE USO COME INPUT
    ANSBbits.ANSB1 = 0;
    ANSBbits.ANSB14 = 0;
    ANSCbits.ANSC3 = 0;
    ANSBbits.ANSB9 = 0;
}
