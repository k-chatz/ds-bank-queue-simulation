/***********************************************************************
Header file			: Cashier.h
Author				: <Costas Chatzopoulos -1115201300202- 21/03/2015>
Purpose				: Ylopoiisi tamia
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#ifndef __cashier__ 
#define __cashier__

#include <stdio.h>

/*Domi tamia*/
typedef struct
{
	int tBusy;		/*Xronos apasxolisis*/
	int tInactive;	/*Xronos adranias*/
	int customers;	/*Arithmos pelaton pou exoyn perasei apo ton sygekrimeno tamia*/
	int tRemaining; /*Enapominon xronos gia exipiretisi tou trexon pelati*/
} Cashier;

/*Praxeis tamia*/
void CashCreate(Cashier * c);
void CashNewCust(Cashier * c);
void CashSetRemTime(Cashier * c, int duration);
void CashInactive(Cashier * c);
void CashBusy(Cashier * c);
int CashFree(Cashier * c);
int CashGetNoCustomers(Cashier * c);
int CashGetRemTime(Cashier * c);
int CashGetInactiveTime(Cashier * c);
int CashGetBusyTime(Cashier * c);
#endif