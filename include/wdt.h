/* 
 * File:   wdt.h
 * Author: Maldus
 *
 * Created on 16 settembre 2016, 12.05
 */

#ifndef WDT_H
#define	WDT_H

#ifdef	__cplusplus
extern "C" {
#endif


#include "HardwareProfile.h"
    
#define     WDI_PIN         EXT_RESET
#define     CHECK_NUM       2

#define     MAIN            0
#define     T1INT           1
    
    
void refresh_stamp_int(unsigned char x);
void disableWDT();
void enableWDT();

#ifdef	__cplusplus
}
#endif

#endif	/* WDT_H */

