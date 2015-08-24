/***********************************************************************
implementation file	: Cashier.c
Author				: <Costas Chatzopoulos -1115201300202- 21/03/2015>
Purpose				: Implementation tamia
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "cashier.h"

void CashCreate(Cashier * c)
{

	c->customers = 0;
	c->tBusy = 0;
	c->tInactive = 0;
	c->tRemaining = 0;
}

void CashNewCust(Cashier * c)
{
	c->customers++;
	//c->tBusy++;
}

void CashSetRemTime(Cashier * c, int duration)
{
	c->tRemaining = duration;
}

void CashInactive(Cashier * c)
{
	c->tInactive++;
}

void CashBusy(Cashier * c)
{
	c->tBusy++;
	c->tRemaining--;
}

int CashFree(Cashier * c)
{
	return c->tRemaining == 0;
}

int CashGetNoCustomers(Cashier * c)
{
	return c->customers;
}

int CashGetRemTime(Cashier * c)
{
	return c->tRemaining;
}

int CashGetInactiveTime(Cashier * c)
{
	return c->tInactive;
}

int CashGetBusyTime(Cashier * c)
{
	return c->tBusy;
}