/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: ciclo.c                                                           */
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

#include <stdint.h>
#include "HardwareProfile.h"
#include "ciclo.h"

void gt_base (uint8_t sonde)
{
    uint8_t s;

    if (sonde == S_1_2) {
        s = SONDA1;
        
        LED1 = s;
        RELE1 = s;
        
        s = SONDA2;
        
        LED2 = s;
        RELE2 = s;
    }
    else if (sonde == S_3_4)
    {
        s = SONDA3;
        
        LED3 = s;
        RELE3 = s;
        
        s = SONDA4;
        
        LED4 = s;
        RELE4 = s;
    }
}


void gt_trigger (uint8_t sonde)
{
    uint8_t s1, s2;
    
    if (sonde == S_1_2)
    {
        s1 = SONDA1;
        s2 = SONDA2;
        
        if ((s1 == 1 && s2 == 1) || s2 == 1)
        {
            RELE1 = 0;
            RELE2 = 0;
            LED1 = 0;
            LED2 = 0;
        }
        else if (s1 == 0 && s2 ==0)
        {
            RELE1 = 1;
            RELE2 = 1;
            LED1 = 1;
            LED2 = 1;
        }
    }
    else if (sonde == S_3_4)
    {
        s1 = SONDA3;
        s2 = SONDA4;
        
        if ((s1 == 1 && s2 == 1) || s2 == 1)
        {
            RELE3 = 0;
            RELE4 = 0;
            LED3 = 0;
            LED4 = 0;
        }
        else if (s1 == 0 && s2 ==0)
        {
            RELE3 = 1;
            RELE4 = 1;
            LED3 = 1;
            LED4 = 1;
        }
    }   
}




void gt_ciclo(MODE mode)
{
    switch (mode)
    {
        case BASE:
            gt_base(S_1_2);
            gt_base(S_3_4);
            break;
            
        case TRIGGER:
            gt_trigger(S_1_2);
            gt_trigger(S_3_4);
            break;
            
        default:
            break;
    }
}


MODE readConfiguration()
{
    uint8_t d1, d2, d3, d4;
    d1 = DIPSWITCH1;
    d2 = DIPSWITCH2;
    d3 = DIPSWITCH3;
    d4 = DIPSWITCH4;

    if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0)
    {
        return BASE;
    }
    else if (d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0)
    {
        return TRIGGER;
    }
    else
    {
        return BASE;
    }
}
