#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>
bool IsHeap(const Heap *h){
    if(HeapIsEmpty(h) || h->size == 1){
        return true;
    }
    if(h == NULL){
        return false;
    }
    HeapWriteStdout(h);
    for (size_t i = 0; i != h->size/2-1; ++i) {
        if(ElemCompare(&h->data[i], &h->data[HeapLeft((int)i)]) > 0 ||
                    ElemCompare(&h->data[i], &h->data[HeapRight((int)i)]) > 0){
            return false;
        }
    }
    return true;
}
   
