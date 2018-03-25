#include "HardwareProfile.h"
#include "system.h"
#include "timer.h"
#include "GPIO.h"
#include "ciclo.h"
#include "digin.h"



int main(void) {
    MODE operatingMode;
    
    Configure_Oscillator();
    Init_GPIO();
    initTimer1();
//    Init_Digin_Filter(DI_P1);
    
    operatingMode = readConfiguration();

    while(1) {
       gt_ciclo(operatingMode);
    }
    return 0;
}


/*
 if (DIPSWITCH1 || SONDA1) {
            LED1 = 1;
            RELE1 = 1;
        }
        else {
            LED1 = 0;
            RELE1 = 0;
        }
        
        if (DIPSWITCH2 || SONDA2) {
            LED2 = 1;
            RELE2 = 1;
        }
        else {
            LED2 = 0;
            RELE2 = 0;
        }
        
        if (DIPSWITCH3 || SONDA3) {
            LED3 = 1;
            RELE3 = 1;
        }
        else {
            LED3 = 0;
            RELE3 = 0;
        }
        
        if (DIPSWITCH4 || SONDA4) {
            LED4 = 1;
            RELE4 = 1;
        }
        else {
            LED4 = 0;
            RELE4 = 0;
        }*/