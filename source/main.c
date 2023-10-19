/******************************************************************************/
/*                                                                            */
/*      H   H      SSSS     W   W                                             */
/*      H   H     S         W   W                                             */
/*      HHHHH      SSS      W   W                                             */
/*      H   H         S     W W W                                             */
/*      H   H  *  SSSS   *   W W   *  snc                                     */
/*                                                                            */
/*      *********************************                                     */
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  programma:  Centralina H2Ox4 controllo 4 livelli H2O                      */
/*                                                                            */
/*  cliente:    Union Spa - Sala Bolognese (BO) & HSW                         */
/*                                                                            */
/*  ver. 00:    25/03/2018  00.0 (base: H2Ox4 Renesas v.04.0 del 14/12/2017)  */
/*                                                                            */
/*  ver. att.:  24/06/2019  03.1                                              */
/*                                                                            */
/*  BY:         Maldus (Mattia MALDINI) & Massimo ZANNA                       */
/*                                                                            */
/*  NNB:        SENSO DEGLI INGRESSI: INVERTITO                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  micro:      MicroChip PIC PIC24FJ128GA704 - 4 MHz - 44 Pin ????????       */
/*              128K Flash - 16 Ram                                           */
/*              131.072 b ?  16.384 b ?                                       */
/*                                                                            */
/*============================================================================*/



// <editor-fold defaultstate="collapsed" desc=" ####    REVISIONI    #### ">

/*============================================================================*/
/*                                                                            */
/*  ver. 00.0: 25/03/2018 (base: H2Ox4 Renesas v.04.0 del 14/12/2018)         */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  ver. 00.1: 25/03/2018                                                     */
/*                                                                            */
/*      - VERSIONE CON HW SETTATO E FUNZIONANTE                               */
/*      - PRIMA STESURA DI 2 MODALITA' DI FUNZIONAMENTO SU 3                  */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  ver. 01.0: 03/04/2018                                                     */
/*                                                                            */
/*      - COMPLETATA PROGRAMMAZIONE "LAVAGGIO" STEP/NOME/PREZZO/TIPO          */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  ver. 02.0: 01/06/2018                                                     */
/*                                                                            */
/*      - WDT E MODALITA' TEST (dipswitch 0000)                               */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  ver. 03.0: 01/03/2019                                                     */
/*                                                                            */
/*      - IN MODALITA' TEST (dipswitch 0000) INTRODOTTO TEST SW (DIP 1/OUT 1) */
/*                                                                            */
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*  ver. 03.1: 24/06/2019                                                     */
/*                                                                            */
/*      - Corretto imprecisioni sulla configurazione del clock (a volte OSC   */
/*        partiva male e sembrava scheda sprogrammata (da errata)             */
/*                                                                            */
/*      - corretta velocita' del timer                                        */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"
#include "system.h"
#include "timer.h"
#include "GPIO.h"
#include "ciclo.h"
#include "digin.h"
#include "wdt.h"
#include "variabili_parametri_sistema.h"





// ========================================================================== //
//  MAIN                                                                      //
// ========================================================================== //
int main(void)
{
    int i;
    MODE operatingMode;
    
    Configure_Oscillator();
    Init_GPIO();
    
    LED_RUN = 1;
    Init_Digin_Filter(&DI_P1, 0, 0, DEBOUNCE);
    initTimer1();
    
    /* Aspetta 500ms che si inizializzi il sistema, ma continuando a gestire il wdt*/
    for (i = 0; i<25; i++)
    {
        refresh_stamp_int(MAIN);
        delay_ms(20);
    }
   
    
    
    
    /*
     * Modalita' di funzionamento: =============================================
     * 
     *  0000: TEST
     *  0001: Base - Base
     *  0010: Trigger - Trigger
     *  0011: Temporizzato - Temporizzato
     *  0100: Trigger - Base
     * 
     *  ======================================================================== 
    */
    
    
    
    
    
    operatingMode = readConfiguration();
    
    if (operatingMode == TEST)
    {
        f_in_test = 1;
    }
    else if (operatingMode == UNDEFINED)
    {
        f_undefined = 1;
    }
    
    while(1)
    {
        /* Decommentare per fare resettare la macchina nella modalita' test*/
        /*if (f_in_test == 0) */
        refresh_stamp_int(MAIN);

        
        gt_ciclo(operatingMode);
        gt_allarmi(operatingMode);
    }
    return 0;
}
