#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
bool HeapMinPop(Heap *h, ElemType *e){
    if(HeapIsEmpty(h)){
        return false;
    }
    *e = h->data[0];
    ElemSwap(&h->data[0], &h->data[h->size-1]);
    --h->size;
    HeapMinMoveDown(h, 0);
    return true;
}
