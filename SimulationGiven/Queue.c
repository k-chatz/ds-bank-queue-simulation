/***********************************************************************
implementation file	: Queue.c
Author				: Y. Cotronis 14/03/2015
Purpose				: Ylopoihsh ouras.
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

/*Domi Ouras*/
typedef struct Q
{
	int front;
	int rear;
	int counter;
	Customer array[QSIZE];
} Q;

Queue QCreate()
{
	Queue q = (Queue)malloc(sizeof(Q));
	QInitialize(q);
	return q;
}

void QDestroy(Queue q)
{
	free(q);
}

int QEmpty(Queue q)
{
	return (q->counter == 0);
}

int QSize(Queue q)
{
	return q->counter;
}

int QFull(Queue q)
{
	return (q->counter == QSIZE);
}

void QInitialize(Queue q)
{
	int i;
	q->counter = 0;
	q->front = 0;
	q->rear = 0;
	for (i = 0; i < QSIZE; i++)
		CustInitialize( &(q->array[i]) ); /* abstraction of = for any type */
}

int QInsert(Queue q, Customer * item)
{
	if (QFull(q))
		return 0;
	else
	{
		q->counter++;
		CustAssign( &(q->array[q->rear]) ,item); /* abstraction of = for any type */
		q->rear = ( q->rear + 1 )% QSIZE;
	}
	return 1;
}

int QRemove(Queue q, Customer * item)
{
	if (QEmpty(q))
		return 0;
	else
	{
		q->counter--;
		CustAssign(item, &(q->array[q->front]) ); /* abstraction of = for any type */
		q->front = ( q->front + 1 )% QSIZE;
	}
	return 1;
}

void inspectQbyOrder(Queue q)
{
	int current = q->front;
	if (!QEmpty(q))
	{
		do
		{
			CustWriteValue(stdout, &(q->array[current]) );
			printf("-");
			current = (current + 1) % QSIZE;
		} while (current != q->rear);
		printf("\n");
	}
}

void inspectQbyArray(Queue q)
{
	int i;
	for (i = 0; i < QSIZE; i++){
		CustWriteValue(stdout, &(q->array[i]) );
		printf("-");
	}
	printf("\n");
}
