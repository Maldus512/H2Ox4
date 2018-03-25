/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: system.h                                                          */
/*                                                                            */
/*      configurazione OSCILLATORE SYS e CLK periferiche                      */
/*                                                                            */
/*  Autore: Maldus(Mattia MALDINI) & Massimo ZANNA                            */
/*                                                                            */
/*  Data  : 04/10/2017      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 04/10/2017      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#ifndef __SYSTEM_H__
#define __SYSTEM_H__

/********************************************************************/
/** System Timing ***************************************************/
/********************************************************************/

#define FOSC        4000000LL                     // clock-frequecy in Hz with suffix LL (64-bit-long), eg. 32000000LL for 32MHz
#define FCY         (FOSC/2)                        // MCU is running at FCY MIPS

#define delay_us(x) __delay32(((x*FCY)/1000000L))   // delays x us
#define delay_ms(x) __delay32(((x*FCY)/1000L))      // delays x ms
#define delay_60ns() delay_us(1)//Nop(); Nop(); Nop(); Nop();Nop(); Nop(); Nop(); Nop();




void Configure_Oscillator();

#endif
