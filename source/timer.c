/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: timers.c                                                          */
/*                                                                            */
/*      gestione TIMERS                                                       */
/*                                                                            */
/*  Autore: Maldus (Mattia MALDINI) & Massimo ZANNA                           */
/*                                                                            */
/*  Data  : 25/03/2018      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 27/03/2018      REV  : 00.2                                       */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"
#include "digin.h"
#include "ciclo.h"



unsigned int timer_sonde[4] = {0,0,0,0};
unsigned long timer_inibizione_sonde[4] = {0,0,0,0};



void initTimer1 (void)
{
    T1CON           = 0x0000;   /* CONFIG TIMER 1mS */
    PR1             = 2000-1;   /* Load pediod register */
    TMR1            = 0x00;     /* clear counter */

    T1CONbits.TON   = 1;        /* START TIMER 1 */
    T1CONbits.TCS   = 0;        /* get input from internal oscillator */
    
    T1CONbits.TCKPS = 00;       /* prescaler 1:1 */
    
    
    IPC0bits.T1IP   = 0x06;     /* Setup Timer1 interrupt for 1 */
    IFS0bits.T1IF   = 0;        /* Clear the Timer1 interrupt status flag */
    IEC0bits.T1IE   = 1;        /* Enable Timer1 interrupts     */
    
}




/*----------------------------------------------------------------------------*/
/*  Timer Interrupt 1 - 1 msec                                                */
/*----------------------------------------------------------------------------*/
void __attribute__((interrupt, auto_psv)) _T1Interrupt (void)       
{
    int led_blink;
    static int pwm_counter = 0;
    static int counter_led = 0;
    static int counter_1s = 0;
    static unsigned char  turno = 0;
    int i;
    uint8_t P1_BUF;
    
    if (pwm_counter++ > 4)
    {
        pwm_counter  = 0;
        
        PWM4 = turno;
        PWM1 = turno;
        PWM2 = turno;
        PWM3 = turno;
        
        if (turno != 0)
        {
            turno = 0;
        }
        else
        {
            turno = 1;
        }
    }
    
    for (i = 0; i < 4; i++) {
        if (timer_sonde[i] > 0) {
            timer_sonde[i]--;
        }
        if (timer_inibizione_sonde[i] > 0) {
            timer_inibizione_sonde[i]--;
        }
    }
    
    
    if (f_allarme_configurazione) {
        led_blink = 100;
    }
    else if (f_allarme_sonde) {
        led_blink = 0;
    }
    else {
        led_blink = 500;
    }
    
    if (counter_led++ >= led_blink && led_blink != 0)
    {
        LED5 = ~LED5;
        counter_led = 0;
    }
    else if (led_blink == 0) {
        LED5 = 1;
    }
    
    if (counter_1s++ >= 1000)
    {
        LED_RUN = ~LED_RUN;
        counter_1s = 0;
    }
    
     /* GT ms ANTIRIMBALZO BIT DI INPUT ====================================== */
    P1_BUF = 0;
    
    P1_BUF |= IN_08; // Leggo IN 08
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_07; // Leggo IN 07
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_06; // Leggo IN 06
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_05; // Leggo IN 05
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_04; // Leggo IN 04
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_03; // Leggo IN 03
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_02; // Leggo IN 02
    P1_BUF = P1_BUF << 1;
    P1_BUF |= IN_01; // Leggo IN 01
    
    Digin_filter ((DI_FILTER *) &DI_P1, P1_BUF);
    
    IFS0bits.T1IF = 0;
}

