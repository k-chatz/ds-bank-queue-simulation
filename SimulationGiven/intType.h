#ifndef __TStoixeioyStoivas_H__
#define __TStoixeioyStoivas_H__
#include <stdio.h>

typedef int Type;

void TSetValue (Type * target, Type * source);
void TInitialize(Type * target);
int TReadValue (FILE * from,  Type * Elem);
void TWriteValue (FILE * to, Type * Elem);
#endif
