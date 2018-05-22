/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: HardwareProfile.h                                                 */
/*                                                                            */
/*      definizione di tutti i BIT utilizzati nell' HW                        */
/*                                                                            */
/*  Autore: Sabbiolino(Fabio BARALDI) & Madus(Mattia MALDINI) & Massimo ZANNA */
/*                                                                            */
/*  Data  : 01/05/2016      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 03/04/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#include <xc.h>

#define OUT             0
#define IN              1

#define DEBOUNCE        5   // 5msec



#define LED1_TRIS       TRISBbits.TRISB2
#define LED2_TRIS       TRISBbits.TRISB3
#define LED3_TRIS       TRISCbits.TRISC1
#define LED4_TRIS       TRISAbits.TRISA8
#define LED5_TRIS       TRISCbits.TRISC0
#define LED_RUN_TRIS    TRISAbits.TRISA4

#define LED1            LATBbits.LATB2
#define LED2            LATBbits.LATB3
#define LED3            LATCbits.LATC1
#define LED4            LATAbits.LATA8
#define LED5            LATCbits.LATC0
#define LED_RUN         LATAbits.LATA4



#define IN_01_TRIS      TRISCbits.TRISC5
#define IN_02_TRIS      TRISCbits.TRISC4
#define IN_03_TRIS      TRISCbits.TRISC3
#define IN_04_TRIS      TRISAbits.TRISA9

#define IN_01           (!PORTCbits.RC5)
#define IN_02           (!PORTCbits.RC4)
#define IN_03           (!PORTCbits.RC3)
#define IN_04           (!PORTAbits.RA9)

#define IN_05_TRIS      TRISAbits.TRISA10
#define IN_06_TRIS      TRISAbits.TRISA7
#define IN_07_TRIS      TRISBbits.TRISB14
#define IN_08_TRIS      TRISBbits.TRISB1

#define IN_05           (!PORTAbits.RA10)
#define IN_06           (!PORTAbits.RA7)
#define IN_07           (!PORTBbits.RB14)
#define IN_08           (!PORTBbits.RB1)



#define RELE1_TRIS      TRISBbits.TRISB13
#define RELE2_TRIS      TRISBbits.TRISB12
#define RELE3_TRIS      TRISBbits.TRISB11
#define RELE4_TRIS      TRISBbits.TRISB10

#define RELE1           LATBbits.LATB13
#define RELE2           LATBbits.LATB12
#define RELE3           LATBbits.LATB11
#define RELE4           LATBbits.LATB10



#define PWM1_TRIS       TRISBbits.TRISB9
#define PWM2_TRIS       TRISCbits.TRISC6
#define PWM3_TRIS       TRISCbits.TRISC7
#define PWM4_TRIS       TRISCbits.TRISC8

#define PWM1            LATBbits.LATB9
#define PWM2            LATCbits.LATC6
#define PWM3            LATCbits.LATC7
#define PWM4            LATCbits.LATC8





/* Pin inutilizzati ========================================================= */

#define UNUSED0_TRIS    TRISCbits.TRISC9
#define UNUSED1_TRIS    TRISCbits.TRISC2
#define UNUSED2_TRIS    TRISBbits.TRISB0
#define UNUSED3_TRIS    TRISBbits.TRISB4
#define UNUSED4_TRIS    TRISBbits.TRISB5
#define UNUSED5_TRIS    TRISBbits.TRISB6
#define UNUSED6_TRIS    TRISBbits.TRISB7
#define UNUSED7_TRIS    TRISBbits.TRISB8
#define UNUSED8_TRIS    TRISBbits.TRISB15
#define UNUSED9_TRIS    TRISBbits.TRISB15
#define UNUSED10_TRIS   TRISAbits.TRISA0
#define UNUSED11_TRIS   TRISAbits.TRISA1
#define UNUSED12_TRIS   TRISAbits.TRISA2
#define UNUSED13_TRIS   TRISAbits.TRISA3

#define UNUSED0         LATCbits.LATC9
#define UNUSED1         LATCbits.LATC2
#define UNUSED2         LATBbits.LATB0
#define UNUSED3         LATBbits.LATB4
#define UNUSED4         LATBbits.LATB5
#define UNUSED5         LATBbits.LATB6
#define UNUSED6         LATBbits.LATB7
#define UNUSED7         LATBbits.LATB8
#define UNUSED8         LATBbits.LATB15
#define UNUSED9         LATBbits.LATB15
#define UNUSED10        LATAbits.LATA0
#define UNUSED11        LATAbits.LATA1
#define UNUSED12        LATAbits.LATA2
#define UNUSED13        LATAbits.LATA3

#endif	/* HARDWAREPROFILE_H */
