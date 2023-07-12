#include <stdlib.h>
#include "minheap.h"
#include "elemtype.h"
#include <stdbool.h>
bool Pop(Heap *h, ElemType *e){
    if(h->size < 2){
        return false;
    }
    *e = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size-1]);
    h->data = realloc(h->data,h->size-- * sizeof(ElemType));
    HeapMinMoveDown(h, 0);
    return true;
}
