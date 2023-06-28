#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
void HeapMinMoveDownRec(Heap *h, int i){
    
    if (i > (int)h->size/2 - 1){
           return;
       }

       size_t left = HeapLeft(i);
       size_t right = HeapRight(i);
       size_t smallest = i;

       if (left < h->size && ElemCompare(HeapGetNodeValue(h, (int)left), HeapGetNodeValue(h, (int)smallest)) < 0) {
           smallest = left;
       }

       if (right < h->size && ElemCompare(HeapGetNodeValue(h, (int)right), HeapGetNodeValue(h, (int)smallest)) < 0) {
           smallest = right;
       }

       if (smallest != i) {
           ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, (int)smallest));
           HeapMinMoveDownRec(h, (int)smallest);
       }

}
