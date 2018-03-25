#include "HardwareProfile.h"
#include "system.h"


/*----------------------------------------------------------------------------*/
/*  Timer Interrupt 1 - 1 msec                                                */
/*----------------------------------------------------------------------------*/
void __attribute__((interrupt, auto_psv)) _T1Interrupt (void)       //every 0.016384
{
    LATCbits.LATC0 = ~LATCbits.LATC0;

    IFS0bits.T1IF = 0;
}


void Init_Timer_1 (void)
{
    T1CON           = 0x0000;   // CONFIG TIMER 1mS
    PR1             = 2000-1;   // Load pediod register
    TMR1            = 0x00;     // clear counter
    T1CONbits.TCS = 0;          // get input from internal oscillator
    T1CONbits.TCKPS = 00;       // prescaler 1:1
    IPC0bits.T1IP = 0x01;       //Setup Timer1 interrupt for 1
    IFS0bits.T1IF = 0;          //Clear the Timer1 interrupt status flag
    IEC0bits.T1IE = 1;          //Enable Timer1 interrupts    
    T1CONbits.TON   = 1;        // START TIMER 1
}


int main(void) {
    Configure_Oscillator();
    TRISCbits.TRISC0 = 0;
    TRISBbits.TRISB3 = 0;
    LATBbits.LATB3 = 1;
    Init_Timer_1();
    int x = 0;
    
    while(1) {
        x ++;
        Nop();
        Nop();
        Nop();
    }
    return 0;
}
