#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
void HeapMinMoveUpRec(Heap *h, int i){
    if (i == 0) {
        return;
    }
    if(ElemCompare(HeapGetNodeValue(h, i),  HeapGetNodeValue(h, HeapParent(i))) < 0){
        ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
    }
    
    HeapMinMoveUpRec(h, HeapParent(i));
}
