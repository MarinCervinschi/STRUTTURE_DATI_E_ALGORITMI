#ifndef ELEMTYPE_H_
#define ELEMTYPE_H_

#include <stdint.h>

typedef int ElemType;

ElemType ElemCopy(const ElemType *e);
void ElemSwap(ElemType *a, ElemType *b);
int ElemCompare(const ElemType *a, const ElemType *b);
void ElemDelete(ElemType *e);

#endif // !ELEMTYPE_H_
