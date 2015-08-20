/***********************************************************************
Header file			: Queue.h
Author				: Y. Cotronis 14/03/2015
Purpose				: Ylopoihsh ouras.
Revision			: <Costas Chatzopoulos -1115201300202- 22/03/2015>
***********************************************************************/

#ifndef __CH2_QUEUE_H_
#define __CH2_QUEUE_H_

#include "Customer.h"

#define QSIZE 10

typedef struct Q  * Queue;

/*Praxeis ouras*/
Queue QCreate();
void QDestroy(Queue q);
int QEmpty(Queue q);
int QSize(Queue q);
int QFull(Queue q);
void QInitialize(Queue q);
int QInsert(Queue q, Customer * item);
int QRemove(Queue q, Customer * item);
void inspectQbyOrder(Queue q);
void inspectQbyArray(Queue q);

#endif