#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>
bool HeapMinPop(Heap *h, ElemType *e){
    if(HeapIsEmpty(h)){
        return false;
    }
    *e = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size-1]);
    --h->size;
    h->data = realloc(h->data, h->size * sizeof(ElemType));
    HeapMinMoveDown(h, 0);
    return true;
}
