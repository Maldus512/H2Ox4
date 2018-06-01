/******************************************************************************/
/*                                                                            */
/*  HSW snc - Casalecchio di Reno (BO) ITALY                                  */
/*  ----------------------------------------                                  */
/*                                                                            */
/*  modulo: digout.h                                                          */
/*                                                                            */
/*      gestione OUTPUT                                                       */
/*                                                                            */
/*  Autore: Massimo ZANNA & Sabbiolino (Fabio BARALDI)                        */
/*                                                                            */
/*  Data  : 13/01/2012      REV  : 00.0                                       */
/*                                                                            */
/*  U.mod.: 12/05/2018      REV  : 01.0                                       */
/*                                                                            */
/******************************************************************************/

#ifndef DIGOUT_H
#define	DIGOUT_H



#define     LED1    1
#define     LED2    2
#define     LED3    3
#define     LED4    4
#define     LED5    5

#define     RELE1    6
#define     RELE2    7
#define     RELE3    8
#define     RELE4    9







void init_Digout(void);

void Read_stato_out(void);

void set_digout(unsigned char dig);

void update_digout(unsigned char dig, unsigned char val);

void clear_digout(unsigned char dig);

char get_digout(unsigned char dig);

void clear_digout_all(void);

void set_digout_all(void);



void clear_digout_mirato(void);

#endif	/* DIGOUT_H */
