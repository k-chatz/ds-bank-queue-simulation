#include "intType.h"

void TSetValue (Type *target, Type * source)
{
	*target=*source;
}

int TReadValue (FILE *from, Type *ElemPtr)
{
     return (fscanf_s(from, "%d", ElemPtr));
}

void TWriteValue (FILE *to, Type * Elem)
{
	fprintf(to, "%d", *Elem);
}

void TInitialize(Type * target)
{
	*target = 0;
}