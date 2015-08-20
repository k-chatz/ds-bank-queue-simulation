/***********************************************************************
implementation file	: Customer.c
Author				: <Costas Chatzopoulos -1115201300202- 20/03/2015>
Purpose				: Ylopoihsh pelatwn.
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#include "Customer.h"

void CustSetEntryTime(Customer * target, int t)
{
	target->EntryTime = t;
}

void CustSetServiseTime(Customer * target, int t)
{
	target->serviceTime = t;
}

void CustAssign(Customer * target, Customer * source)
{
	target->EntryTime = source->EntryTime;
	target->serviceTime = source->serviceTime;
}

void CustInitialize(Customer * target)
{
	target->EntryTime = 0;
	target->serviceTime = 0;
}

void CustWriteValue(FILE * stream, Customer * source)
{
	printf("|Entry Time = %d ", source->EntryTime);
	printf("Service Time = %d|", source->serviceTime);
}

int CustGetServiseTime(Customer * source)
{
	return source->serviceTime;
}

int CustGetEntryTime(Customer * source)
{
	return source->EntryTime;
}

