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
/*  U.mod.: 29/03/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#include <xc.h>

#define OUT         0
#define IN          1



#define LED1_TRIS        TRISBbits.TRISB2
#define LED2_TRIS        TRISBbits.TRISB3
#define LED3_TRIS        TRISCbits.TRISC1
#define LED4_TRIS        TRISAbits.TRISA8
#define LED5_TRIS        TRISCbits.TRISC0
#define LED_RUN_TRIS     LED5_TRIS

#define LED1            LATBbits.LATB2
#define LED2            LATBbits.LATB3
#define LED3            LATCbits.LATC1
#define LED4            LATAbits.LATA8
#define LED5            LATCbits.LATC0
#define LED_RUN         LED5



#define SONDA1_TRIS     TRISCbits.TRISC5
#define SONDA2_TRIS     TRISCbits.TRISC4
#define SONDA3_TRIS     TRISCbits.TRISC3
#define SONDA4_TRIS     TRISAbits.TRISA9

#define SONDA1          (!PORTCbits.RC5)
#define SONDA2          (!PORTCbits.RC4)
#define SONDA3          (!PORTCbits.RC3)
#define SONDA4          (!PORTAbits.RA9)



#define DIPSWITCH1_TRIS TRISAbits.TRISA10
#define DIPSWITCH2_TRIS TRISAbits.TRISA7
#define DIPSWITCH3_TRIS TRISBbits.TRISB14
#define DIPSWITCH4_TRIS TRISBbits.TRISB1

#define DIPSWITCH1      (!PORTAbits.RA10)
#define DIPSWITCH2      (!PORTAbits.RA7)
#define DIPSWITCH3      (!PORTBbits.RB14)
#define DIPSWITCH4      (!PORTBbits.RB1)



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

#endif	/* HARDWAREPROFILE_H */
