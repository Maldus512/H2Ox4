/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: digout.c                                                          */
/*                                                                            */
/*      gestione OUTPUT                                                       */
/*                                                                            */
/*  Autore: Massimo ZANNA & Sabbiolino (Fabio BARALDI)                        */
/*                                                                            */
/*  Data  : 13/01/2012      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 14/05/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"
#include "variabili_parametri_sistema.h"
#include "digout.h"

#include "ciclo.h"



unsigned char           out_mom[16];
char                    fhw_agg_mom_out;







/*----------------------------------------------------------------------------*/
/*  void update_digout (unsigned char dig, val)                               */
/*----------------------------------------------------------------------------*/
void update_digout (unsigned char dig_out, unsigned char val)
{
    switch (dig_out)
    {
        case 1:
            OUT_01 = val;
            break;
            
        case 2:
            OUT_02 = val;
            break;
            
        case 3:
            OUT_03 = val;
            break;
            
        case 4:
            OUT_04 = val;
            break;
            
        case 5:
            OUT_05 = val;
            break;
            
        case 6:
            OUT_06 = val;
            break;
        
        case 7:
            OUT_07 = val;
            break;
            
        case 8:
            OUT_08 = val;
            break;
            
        case 9:
            OUT_09 = val;
            break;
            
        default:
            break;
    }
}





/*----------------------------------------------------------------------------*/
/*  void set_digout(unsigned char dig)                                        */
/*----------------------------------------------------------------------------*/
void set_digout (unsigned char dig)
{
    switch (dig)
    {
        case 1:
            OUT_01 = 1;
            break;
            
        case 2:
            OUT_02 = 1;
            break;
            
        case 3:
            OUT_03 = 1;
            break;
            
        case 4:
            OUT_04 = 1;
            break;
            
        case 5:
            OUT_05 = 1;
            break;
            
        case 6:
            OUT_06 = 1;
            break;
        
        case 7:
            OUT_07 = 1;
            break;
            
        case 8:
            OUT_08 = 1;
            break;
            
        case 9:
            OUT_09 = 1;
            break;
            
        default:
            break;
    }
}





/*----------------------------------------------------------------------------*/
/*  void clear_digout(unsigned char dig)                                      */
/*----------------------------------------------------------------------------*/
void clear_digout (unsigned char dig)
{
    switch (dig)
    {
        case 1:
            OUT_01 = 0;
            break;
            
        case 2: 
            OUT_02 = 0;
            break;
            
        case 3: 
            OUT_03 = 0;
            break;
            
        case 4: 
            OUT_04 = 0;
            break;
            
        case 5: 
            OUT_05 = 0;
            break;
            
        case 6:
            OUT_06 = 0;
            break;
        
        case 7:
            OUT_07 = 0;
            break;
            
        case 8:
            OUT_08 = 0;
            break;
            
        case 9:
            OUT_09 = 0;
            break;
            
        default:
            break;
    }
}





/*----------------------------------------------------------------------------*/
/*  char get_digout(unsigned char dig)                                        */
/*----------------------------------------------------------------------------*/
char get_digout (unsigned char dig)
{
    switch (dig)
    {
        case 1:
            return(OUT_01);
            
        case 2:
            return(OUT_02);
            
        case 3:
            return(OUT_03);
            
        case 4:
            return(OUT_04);
            
        case 5:
            return(OUT_05);
            
        case 6:
            return(OUT_06);
            
        case 7:
            return(OUT_07);
            
        case 8:
            return(OUT_08);
            
        case 9:
            return(OUT_09);
            
        default:
            return(0xFF);
    }
}





/*----------------------------------------------------------------------------*/
/*  void clear_digout_all                                                     */
/*                                                                            */
/*  azzera tutte le uscite                                                    */
/*                                                                            */
/*----------------------------------------------------------------------------*/
void clear_digout_all (void)
{
    OUT_01 = 0; // 01
    OUT_02 = 0; // 02
    OUT_03 = 0; // 03
    OUT_04 = 0; // 04
    OUT_05 = 0; // 04
    OUT_06 = 0; // 04
    OUT_07 = 0; // 04
    OUT_08 = 0; // 04
    OUT_09 = 0; // 04

}



/*----------------------------------------------------------------------------*/
/*  void set_digout_all                                                       */
/*                                                                            */
/*  setta tutte le uscite                                                     */
/*----------------------------------------------------------------------------*/
void set_digout_all (void)
{
    OUT_01 = 1; // 01
    OUT_02 = 1; // 02
    OUT_03 = 1; // 03
    OUT_04 = 1; // 04
    OUT_05 = 1; // 04
    OUT_06 = 1; // 04
    OUT_07 = 1; // 04
    OUT_08 = 1; // 04
    OUT_09 = 1; // 04


}

