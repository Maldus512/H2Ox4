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
    // DISABILITO AD NEI BIT CHE USO COME INPUT
    ANSBbits.ANSB1 = 0;
    ANSBbits.ANSB14 = 0;
    ANSCbits.ANSC3 = 0;
    ANSBbits.ANSB9 = 0;
    
    IN_01_TRIS = IN;
    IN_02_TRIS = IN;
    IN_03_TRIS = IN;
    IN_04_TRIS = IN;
    
    IN_05_TRIS = IN;
    IN_06_TRIS = IN;
    IN_07_TRIS = IN;
    IN_08_TRIS = IN;

    
    
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
    LED_RUN_TRIS = OUT;
    LED1 = 0;
    LED2 = 0;
    LED3 = 0;
    LED4 = 0;
    LED5 = 0;
    LED_RUN = 0;

    PWM1_TRIS = OUT;
    PWM2_TRIS = OUT;
    PWM3_TRIS = OUT;
    PWM4_TRIS = OUT;
    PWM1 = 0;
    PWM2 = 0;
    PWM3 = 0;
    PWM4 = 0;
    
    /* Tiro a massa tutti i pin del micro che non utilizziamo */
    UNUSED0_TRIS = OUT;
    UNUSED1_TRIS = OUT;
    UNUSED2_TRIS = OUT;
    UNUSED3_TRIS = OUT;
    UNUSED4_TRIS = OUT;
    UNUSED5_TRIS = OUT;
    UNUSED6_TRIS = OUT;
    UNUSED7_TRIS = OUT;
    UNUSED8_TRIS = OUT;
    UNUSED9_TRIS = OUT;
    UNUSED10_TRIS = OUT;
    UNUSED11_TRIS = OUT;
    UNUSED12_TRIS = OUT;
    UNUSED13_TRIS = OUT;

    UNUSED0 = 0;
    UNUSED1 = 0;
    UNUSED2 = 0;
    UNUSED3 = 0;
    UNUSED4 = 0;
    UNUSED5 = 0;
    UNUSED6 = 0;
    UNUSED7 = 0;
    UNUSED8 = 0;
    UNUSED9 = 0;
    UNUSED10 = 0;
    UNUSED11 = 0;
    UNUSED12 = 0;
    UNUSED13 = 0;

}
