/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: system.c                                                          */
/*                                                                            */
/*      configurazione OSCILLATORE SYS e CLK periferiche                      */
/*                                                                            */
/*  Autore: Maldus(Mattia MALDINI) & Massimo ZANNA                            */
/*                                                                            */
/*  Data  : 04/10/2017      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 29/03/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"
#include "system.h"

/* FSEC */
#pragma config BWRP = OFF               /* Boot Segment Write-Protect bit (Boot Segment may be written) */
#pragma config BSS = DISABLED           /* Boot Segment Code-Protect Level bits (No Protection (other than BWRP)) */
#pragma config BSEN = OFF               /* Boot Segment Control bit (No Boot Segment) */
#pragma config GWRP = OFF               /* General Segment Write-Protect bit (General Segment may be written) */
#pragma config GSS = DISABLED           /* General Segment Code-Protect Level bits (No Protection (other than GWRP)) */
#pragma config CWRP = OFF               /* Configuration Segment Write-Protect bit (Configuration Segment may be written) */
#pragma config CSS = DISABLED           /* Configuration Segment Code-Protect Level bits (No Protection (other than CWRP)) */
#pragma config AIVTDIS = OFF            /* Alternate Interrupt Vector Table bit (Disabled AIVT) */

/* FBSLIM */
#pragma config BSLIM = 0x1FFF           /* Boot Segment Flash Page Address Limit bits (Boot Segment Flash page address  limit) */

/* FSIGN */

/* FOSCSEL */
#pragma config FNOSC = OSCFDIV              /* Oscillator Source Selection (Internal Fast RC (FRC)) */
#pragma config PLLMODE = DISABLED       /* PLL Mode Selection (No PLL used; PLLEN bit is not available) */
#pragma config IESO = OFF               /* Two-speed Oscillator Start-up Enable bit (Start up with user-selected oscillator source) */

/* FOSC */
#pragma config POSCMD = NONE              /* Primary Oscillator Mode Select bits (XT Crystal Oscillator Mode) */
#pragma config OSCIOFCN = OFF           /* OSC2 Pin Function bit (OSC2 is clock output) */
#pragma config SOSCSEL = OFF             /* Digital mode */
#pragma config PLLSS = PLL_FRC          /* PLL Secondary Selection Configuration bit (PLL is fed by the on-chip Fast RC (FRC) oscillator) */
#pragma config IOL1WAY = OFF            /* Peripheral pin select configuration bit (Allow multiple reconfigurations) */
#pragma config FCKSM = CSECMD           /* Clock Switching Mode bits (Clock switching is enabled,Fail-safe Clock Monitor is disabled) */

/* FWDT */
/* Watchdog timer configurato per essere settato ogni 32 ms (pena il reset)*/
#pragma config WDTPS = PS32          /* Watchdog Timer Postscaler bits (1:32) */
#pragma config FWPSA = PR32            /* Watchdog Timer Prescaler bit (1:32) */
#pragma config FWDTEN = ON             /* Watchdog Timer Enable bits (WDT and SWDTEN enabled) */
#pragma config WINDIS = OFF             /* Watchdog Timer Window Enable bit (Watchdog Timer in Non-Window mode) */
#pragma config WDTWIN = WIN75           /* Watchdog Timer Window Select bits (WDT Window is 7s5% of WDT period) */
#pragma config WDTCMX = WDTCLK          /* WDT MUX Source Select bits (WDT clock source is determined by the WDTCLK Configuration bits) */
#pragma config WDTCLK = LPRC            /* WDT Clock Source Select bits (WDT uses LPRC) */

/* FPOR */
#pragma config BOREN = ON               /* Brown Out Enable bit (Brown Out Enable Bit) */
#pragma config LPCFG = OFF              /* Low power regulator control (No Retention Sleep) */
#pragma config DNVPEN = ENABLE          /* Downside Voltage Protection Enable bit (Downside protection enabled using ZPBOR when BOR is inactive) */

/* FICD */
#pragma config ICS = PGD3               /* ICD Communication Channel Select bits (Communicate on PGEC1 and PGED1) */
#pragma config JTAGEN = OFF             /* JTAG Enable bit (JTAG is disabled) */

/* FDEVOPT1 */
#pragma config ALTCMPI = DISABLE        /* Alternate Comparator Input Enable bit (C1INC, C2INC, and C3INC are on their standard pin locations) */
#pragma config TMPRPIN = OFF            /* Tamper Pin Enable bit (TMPRN pin function is disabled) */
#pragma config SOSCHP = ON              /* SOSC High Power Enable bit (valid only when SOSCSEL = 1 (Enable SOSC high power mode (default)) */
#pragma config ALTI2C1 = ALTI2CEN       /* Alternate I2C pin Location (SDA1 and SCL1 on RB9 and RB8) */





void Configure_Oscillator()
{
    OSCDIVbits.DIV = 1;
    CLKDIVbits.RCDIV = 0;
    OSCTUNbits.TUN = 0x019 /*0b011001*/;
    
    PMD3bits.CMPMD  = 1;        /* Alternate I2C pin Location (SDA1 and SCL1 on RB9 and RB8) */   
}
