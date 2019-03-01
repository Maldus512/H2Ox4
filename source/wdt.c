/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: wdt.c                                                             */
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

#include "wdt.h"

unsigned char stamp_int[CHECK_NUM];

void refresh_stamp_int(unsigned char x)
{
    unsigned char i = 0;
    
    stamp_int[x] = 1;
    
    for (i = 0; i < CHECK_NUM; i++)
    {
        if (stamp_int[i] != 1)
        {
            return;
        }
    }
    
    /*Set the WDT enable bit if it's the first time*/
    if (RCONbits.SWDTEN == 0)
    {
        RCONbits.SWDTEN = 1;
    }
    
    /*Clear the timer once every party has set their stamp*/
    /*Clear internal WDT module*/
    ClrWdt (); 
    for (i = 0; i < CHECK_NUM; i++)
    {
        stamp_int[i] = 0;
    }
}



void disableWDT()
{
    int i =0;
    
    for (i = 0; i < CHECK_NUM; i++)
    {
        stamp_int[i] = 0;
    }
    RCONbits.SWDTEN = 0;
}



void enableWDT()
{
    int i =0;
    
    for (i = 0; i < CHECK_NUM; i++)
    {
        stamp_int[i] = 0;
    }
    RCONbits.SWDTEN = 1;
    ClrWdt (); 
}
