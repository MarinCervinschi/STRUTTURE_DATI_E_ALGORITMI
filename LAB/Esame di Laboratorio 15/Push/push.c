#include <stdlib.h>
#include <string.h>
 #include "minheap.h"
#include "elemtype.h"
void Push(Heap *h, const ElemType *e){
    if(!h){
        return;
    }
    h->data = realloc(h->data, ++h->size * sizeof(ElemType));
    h->data[h->size-1] = ElemCopy(e);
    HeapMinMoveUp(h, (int)h->size-1);
}
