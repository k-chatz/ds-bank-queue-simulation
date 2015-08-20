/***********************************************************************
Header file			: Customer.h
Author				: <Costas Chatzopoulos -1115201300202- 20/03/2015>
Purpose				: Ylopoihsh pelatwn.
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#ifndef __Customer__ 
#define __Customer__

#include <stdio.h>

/*Domi pelati*/
typedef struct Customer{
	int EntryTime; /* Minute of entering q */
	int serviceTime;
} Customer;

/*Praxeis*/
void CustDestroy(Customer * target);
void CustSetEntryTime(Customer * target, int t);
void CustSetServiseTime(Customer * target, int t);
void CustAssign(Customer * target, Customer * source);
void CustInitialize(Customer * target);
void CustWriteValue(FILE * stream, Customer * source);
int CustGetServiseTime(Customer * source);
int CustGetEntryTime(Customer * source);

#endif
