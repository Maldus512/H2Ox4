/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: ciclo.h                                                           */
/*                                                                            */
/*      gestione CICLO centralina                                             */
/*                                                                            */
/*  Autore: Maldus (Mattia MALDINI) & Massimo ZANNA                           */
/*                                                                            */
/*  Data  : 25/03/2018      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 27/03/2018      REV  : 00.2                                       */
/*                                                                            */
/******************************************************************************/

#ifndef __CICLO_H__
#define	__CICLO_H__

typedef enum
{
            BASE = 0,
            TRIGGER,
} MODE;

#define S_1_2       0
#define S_3_4       1



void gt_ciclo(MODE mode);
MODE readConfiguration();

#endif
