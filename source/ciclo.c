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
/*  U.mod.: 03/04/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#include <stdint.h>
#include "HardwareProfile.h"
#include "ciclo.h"
#include "digin.h"
#include "timer.h"
#include "digout.h"

uint8_t f_allarme_sonde = 0;
uint8_t f_allarme_configurazione = 0;



/* Funzione: gt_test
 * Gestione della modalita' test (sonda rilevata - stacca contatto corrispondente)

 */
void gt_test ()
{
    uint8_t read;
    
    read = digitalRead(SONDA1, &DI_P1);
    update_digout(LED1, read);
    update_digout(RELE1, read);

    read = digitalRead(SONDA2, &DI_P1);
    update_digout(LED2, read);
    update_digout(RELE2, read);
    
    read = digitalRead(SONDA3, &DI_P1);
    update_digout(LED3, read);
    update_digout(RELE3, read);
    
    read = digitalRead(SONDA4, &DI_P1);
    update_digout(LED4, read);
    update_digout(RELE4, read);
}



/* Funzione: gt_base
 * Gestione della modalita' base (sonda rilevata - stacca contatto corrispondente)
 * --------
 *  sonde: Due valori possibili, S_1_2 o S_3_4; gestisce il controllo della
 *          coppia di sonde corrispondente
 */
void gt_base (uint8_t sonde)
{
    uint8_t s;
    static uint8_t sonda_old[4] = {0,0,0,0};

    if (sonde == S_1_2) {
        /* SONDA 1 */
        s = digitalRead(SONDA1, &DI_P1);
        
        if (s == 0 && (sonda_old[SONDA1] == 0 || timer_sonde[SONDA1] == 0))
        {
            clear_digout(LED1);
            clear_digout(RELE1);
            sonda_old[SONDA1] = 0;
            timer_sonde[SONDA1] = DELAY;        /* Riattacca il contatto con un delay (1-2 secondi) */
        }
        else if (s == 1 && (timer_sonde[SONDA1] == 0 || sonda_old[SONDA1] == 1))
        {
            set_digout(LED1);
            set_digout(RELE1);
            sonda_old[SONDA1] = 1;
            timer_sonde[SONDA1] = DELAY;        /* Stacca il contatto con un delay (1-2 secondi) */
        }
        
        /* SONDA 2 */
        s = digitalRead(SONDA2, &DI_P1);
        
        if (s == 0 && (sonda_old[SONDA2] == 0 || timer_sonde[SONDA2] == 0))
        {
            clear_digout(LED2);
            clear_digout(RELE2);
            sonda_old[SONDA2] = 0;
            timer_sonde[SONDA2] = DELAY;        /* Riattacca il contatto con un delay (1-2 secondi) */
        }
        else if (s == 1 && (timer_sonde[SONDA2] == 0 || sonda_old[SONDA2] == 1))
        {
            set_digout(LED2);
            set_digout(RELE2);
            sonda_old[SONDA2] = 1;
            timer_sonde[SONDA2] = DELAY;        /* Stacca il contatto con un delay (1-2 secondi) */
        }
    }
    else if (sonde == S_3_4)
    {
        /* SONDA 3 */
        s = digitalRead(SONDA3, &DI_P1);
        
        if (s == 0 && (sonda_old[SONDA3] == 0 || timer_sonde[SONDA3] == 0))
        {
            clear_digout(LED3);
            clear_digout(RELE3);
            sonda_old[SONDA3] = 0;
            timer_sonde[SONDA3] = DELAY;        /* Riattacca il contatto con un delay (1-2 secondi) */
        }
        else if (s == 1 && (timer_sonde[SONDA3] == 0 || sonda_old[SONDA3] == 1))
        {
            set_digout(LED3);
            set_digout(RELE3);
            sonda_old[SONDA3] = 1;
            timer_sonde[SONDA3] = DELAY;        /* Stacca il contatto con un delay (1-2 secondi) */
        }
        
        /* SONDA 4 */
        s = digitalRead(SONDA4, &DI_P1);
        
        if (s == 0 && (sonda_old[SONDA4] == 0 || timer_sonde[SONDA4] == 0))
        {
            clear_digout(LED4);
            clear_digout(RELE4);
            sonda_old[SONDA4] = 0;
            timer_sonde[SONDA4] = DELAY;        /* Riattacca il contatto con un delay (1-2 secondi) */
        }
        else if (s == 1 && (timer_sonde[SONDA4] == 0 || sonda_old[SONDA4] == 1))
        {
            set_digout(LED4);
            set_digout(RELE4);
            sonda_old[SONDA4] = 1;
            timer_sonde[SONDA4] = DELAY;        /* Stacca il contatto con un delay (1-2 secondi) */
        }
    }
}





/* Funzione: gt_trigger
 * Gestione della modalita' trigger (due livelli, stacca il contatto solo quando
 * si sente anche la seconda sonda, e lo riattacca quando entrambe sono aperte)
 * --------
 *  sonde: Due valori possibili, S_1_2 o S_3_4; gestisce il controllo della
 *          coppia di sonde corrispondente
 */
void gt_trigger (uint8_t sonde)
{
    uint8_t s1, s2;
    
    if (sonde == S_1_2)
    {
        s1 = digitalRead(SONDA1, &DI_P1);
        s2 = digitalRead(SONDA2, &DI_P1);
        
        if ((s1 == 1 && s2 == 1) || s2 == 1)
        {
            clear_digout(RELE1);
            clear_digout(RELE2);
            clear_digout(LED1);
            clear_digout(LED2);
        }
        else if ((s1 == 0 && s2 ==0) && timer_sonde[SONDA2] == 0)
        {
            
            set_digout(RELE1);
            set_digout(RELE2);
            set_digout(LED1);
            set_digout(LED2);
        }
        
        if (s1 == 1 || s2 == 1) {
            timer_sonde[SONDA2] = DELAY_TRIGGER;    /* Riattacca il contatto con un delay (1-2 secondi)*/
        }
    }
    else if (sonde == S_3_4)
    {
        s1 = digitalRead(SONDA3, &DI_P1);
        s2 = digitalRead(SONDA4, &DI_P1);
        
        if ((s1 == 1 && s2 == 1) || s2 == 1)
        {
            clear_digout(RELE3);
            clear_digout(RELE4);
            clear_digout(LED3);
            clear_digout(LED4);
        }
        else if ((s1 == 0 && s2 ==0) && timer_sonde[SONDA4] == 0)
        {
            
            set_digout(RELE3);
            set_digout(RELE4);
            set_digout(LED3);
            set_digout(LED4);
        }
        
        if (s1 == 1 || s2 == 1)
        {
            timer_sonde[SONDA4] = DELAY_TRIGGER;    /* Riattacca il contatto con un delay (1-2 secondi)*/
        }
    }   
}





/* Funzione: gt_temporizzata
 * Gestione della modalita' temporizzata con inibizione: al chiudersi di una sonda
 * aspetto ~5 secondi prima di attaccare il contatto; quando la sonda si riapre
 * mantengo un timer di inibizione (~1 minuto) prima di fare qualsiasi altra cosa.
 * --------
 *  sonde: Due valori possibili, S_1_2 o S_3_4; gestisce il controllo della
 *          coppia di sonde corrispondente
 */
void gt_temporizzata(uint8_t sonde)
{
    uint8_t s;
    
    /* sonda_on:
        0 = sonda aperta - tieni il contatto staccato
        1 = sonda chiusa - contatto attaccato, ma quando si riapre devo lanciare
            il timer di inibizione
        2 = sonda aperta o chiusa e tempo di inibizione passato; ri-setto il tempo
            di attesa e torno allo stato 0 */
    static uint8_t sonde_on[4] = {0,0,0,0};
    
    if (sonde == S_1_2)
    {
        /* SONDA 1 */
        s = digitalRead(SONDA1, &DI_P1);
        
        if (sonde_on[SONDA1] == 2 && timer_inibizione_sonde[SONDA1] == 0)
        {
            sonde_on[SONDA1] = 0;
            timer_sonde[SONDA1] = DELAY_TEMPORIZZATA;
        }
        
        if (s == 0)
        {
            clear_digout(LED1);
            clear_digout(RELE1);
            
            if (sonde_on[SONDA1] == 1)
            {
                timer_inibizione_sonde[SONDA1] = DELAY_INIBIZIONE;
                sonde_on[SONDA1] = 2;
            }
            timer_sonde[SONDA1] = DELAY_TEMPORIZZATA;
        }
        else if (s == 1 && timer_sonde[SONDA1] == 0 && timer_inibizione_sonde[SONDA1] == 0)
        {
            set_digout(LED1);
            set_digout(RELE1);
            sonde_on[SONDA1] = 1;
        }
        
        /* SONDA 2 */
        s = digitalRead(SONDA2, &DI_P1);  
        
        if (sonde_on[SONDA2] == 2 && timer_inibizione_sonde[SONDA2] == 0)
        {
            sonde_on[SONDA2] = 0;
            timer_sonde[SONDA1] = DELAY_TEMPORIZZATA;
        }
        
        if (s == 0)
        {
            clear_digout(LED2);
            clear_digout(RELE2);
            
            if (sonde_on[SONDA2] == 1)
            {
                timer_inibizione_sonde[SONDA2] = DELAY_INIBIZIONE;
                sonde_on[SONDA2] = 2;
            }
            timer_sonde[SONDA2] = DELAY_TEMPORIZZATA;
        }
        else if (s == 1 && timer_sonde[SONDA2] == 0 && timer_inibizione_sonde[SONDA2] == 0)
        {
            set_digout(LED2);
            set_digout(RELE2);
            sonde_on[SONDA2] = 1;
        }
    }
    else if (sonde == S_3_4)
    {
        /* SONDA 3 */
        s = digitalRead(SONDA3, &DI_P1);  
        
        if (sonde_on[SONDA3] == 2 && timer_inibizione_sonde[SONDA3] == 0)
        {
            sonde_on[SONDA3] = 0;
            timer_sonde[SONDA3] = DELAY_TEMPORIZZATA;
        }
        
        if (s == 0)
        {
            clear_digout(LED3);
            clear_digout(RELE3);
            
            if (sonde_on[SONDA3] == 1)
            {
                timer_inibizione_sonde[SONDA3] = DELAY_INIBIZIONE;
                sonde_on[SONDA3] = 2;
            }
            timer_sonde[SONDA3] = DELAY_TEMPORIZZATA;
        }
        else if (s == 1 && timer_sonde[SONDA3] == 0 && timer_inibizione_sonde[SONDA3] == 0)
        {
            set_digout(LED3);
            clear_digout(RELE3);
            sonde_on[SONDA3] = 1;
        }
        
        /* SONDA 4 */
        s = digitalRead(SONDA4, &DI_P1);  
        
        if (sonde_on[SONDA4] == 2 && timer_inibizione_sonde[SONDA4] == 0)
        {
            sonde_on[SONDA4] = 0;
            timer_sonde[SONDA4] = DELAY_TEMPORIZZATA;
        }
        
        if (s == 0)
        {
            clear_digout(LED4);
            clear_digout(RELE4);
            
            if (sonde_on[SONDA4] == 1)
            {
                timer_inibizione_sonde[SONDA4] = DELAY_INIBIZIONE;
                sonde_on[SONDA4] = 2;
            }
            timer_sonde[SONDA4] = DELAY_TEMPORIZZATA;
        }
        else if (s == 1 && timer_sonde[SONDA4] == 0 && timer_inibizione_sonde[SONDA4] == 0)
        {
            set_digout(LED4);
            set_digout(RELE4);
            sonde_on[SONDA4] = 1;
        }
    }
}





/* Funzione: gt_ciclo
 * Gestione del ciclo della macchina.
 * --------
 * mode: modalita' operativa della macchina. A seconda del valore le coppie di sonde-contatti
 *       (1,2) e (3,4) possono avere diversi comportamenti, indipendenti tra loro
 */
void gt_ciclo(MODE mode)
{
    switch (mode)
    {
        case TEST:
            gt_test();
            break;
        
        case BASE:
            gt_base(S_1_2);
            gt_base(S_3_4);
            break;
            
        case TRIGGER:
            gt_trigger(S_1_2);
            gt_trigger(S_3_4);
            break;
            
        case TEMPORIZZATA:
            gt_temporizzata(S_1_2);
            gt_temporizzata(S_3_4);
            break;
            
        case TRIGGER_BASE:
            gt_trigger(S_1_2);
            gt_base(S_3_4);
            break;
            
        case UNDEFINED:
            break;
            
        default:
            break;
    }
}





/* Funzione: gt_allarmi
 * Gestione degli allarmi; c'e' una sola situazione anomala riscontrabile: il caso
 * in cui la sonda bassa e' aperta e quella alta e' chiusa. In tal caso una delle due
 * e' rotta, o sono state montate al contrario
 * --------
 * mode: modalita' operativa della macchina. Serve nel controllo degli allarmi
 *      perche' le sonde sono arrangiate come alte/basse solo nella modalita' trigger.
 */
void gt_allarmi(MODE mode)
{
    int s1, s2, s3, s4;
    
    switch (mode)
    {
        case UNDEFINED:
            f_allarme_configurazione = 1;
            break;
            
        case TRIGGER:
            s1 = digitalRead(SONDA1, &DI_P1);
            s2 = digitalRead(SONDA2, &DI_P1);
            s3 = digitalRead(SONDA3, &DI_P1);
            s4 = digitalRead(SONDA4, &DI_P1);

            if ((s1 == 0 && s2 == 1) || (s3 == 0 && s4 == 1))
            {
                f_allarme_sonde = 1;
            }
            else
            {
                f_allarme_sonde = 0;
            }
            break;
            
        case TRIGGER_BASE:
            s1 = digitalRead(SONDA1, &DI_P1);
            s2 = digitalRead(SONDA2, &DI_P1);
            
            if (s1 == 0 && s2 == 1)
            {
                f_allarme_sonde = 1;
            }
            else
            {
                f_allarme_sonde = 0;
            }
            break;
            
        default:
            break;
    }
}





/* Funzione: readConfiguration
 * Lettura della configurazione del dipswitch.
 * --------
 * return: modalita' codificata dai 4 switch.
 */
MODE readConfiguration()
{
    uint8_t d1, d2, d3, d4;
    d1 = digitalRead(DIPSWITCH1, &DI_P1);
    d2 = digitalRead(DIPSWITCH2, &DI_P1);
    d3 = digitalRead(DIPSWITCH3, &DI_P1);
    d4 = digitalRead(DIPSWITCH4, &DI_P1);

    if (d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0)
    {
        return TEST;
    }
    else if (d1 == 1 && d2 == 0 && d3 == 0 && d4 == 0)
    {
        return BASE;
    }
    else if (d1 == 0 && d2 == 1 && d3 == 0 && d4 == 0)
    {
        return TRIGGER;
    }
    else if (d1 == 1 && d2 == 1 && d3 == 0 && d4 == 0)
    {
        return TEMPORIZZATA;
    }
    else if (d1 == 0 && d2 == 0 && d3 == 1 && d4 == 0)
    {
        return TRIGGER_BASE;
    }
    else
    {
        return UNDEFINED;
    }
}
