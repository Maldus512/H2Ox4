/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: wdt.h                                                             */
/*                                                                            */
/*      gestione Voltage Supervisor MCP1316T (WDT esterno)                    */
/*      e WatchDog timer interno                                              */
/*                                                                            */
/*  Autore: Mattia Maldini                                                    */
/*                                                                            */
/*  Data  : 16/09/2016     REV  : 00.0                                        */
/*                                                                            */
/*  U.mod.: 01/03/2019     REV  : 03.0                                        */
/*                                                                            */
/******************************************************************************/

#ifndef WDT_H
#define	WDT_H

#include "HardwareProfile.h"
    
#define     WDI_PIN         EXT_RESET
#define     CHECK_NUM       2

#define     MAIN            0
#define     T1INT           1


    
void refresh_stamp_int(unsigned char x);
void disableWDT();
void enableWDT();

#endif	/* WDT_H */
