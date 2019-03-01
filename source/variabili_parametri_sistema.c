/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: variabili_parametri_sistema.c                                     */
/*                                                                            */
/*      ciclo macchina                                                        */
/*                                                                            */
/*  Autore: Massimo Zanna & Mattia Maldini                                    */
/*                                                                            */
/*  Data  : 30/06/2016      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 16/05/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#include "HardwareProfile.h"
#include "variabili_parametri_sistema.h"



unsigned char           f_in_test = 0;              // flag che segnala che sono nelle pagine di test
unsigned char           f_undefined = 0;