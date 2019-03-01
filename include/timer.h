/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: timers.h                                                          */
/*                                                                            */
/*      gestione TIMERS                                                       */
/*                                                                            */
/*  Autore: Maldus (Mattia MALDINI) & Massimo ZANNA                           */
/*                                                                            */
/*  Data  : 25/03/2018      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 01/03/2019      REV  : 03.0                                       */
/*                                                                            */
/******************************************************************************/

#ifndef __TIMER_H__
#define	__TIMER_H__

void initTimer1 (void);

extern unsigned int timer_sonde[4];
extern unsigned long timer_inibizione_sonde[4];

#endif
