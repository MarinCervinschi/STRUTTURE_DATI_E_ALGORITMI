#include <stdlib.h>
#include "elemtype.h"
#include "minheap.h"
Heap* MergeHeap(const Heap* h1, const Heap* h2){
    if(!h1 || !h2){
        return NULL;
    }
    Heap *ret = HeapCreateEmpty();
    for (size_t i = 0; i < h1->size; ++i) {
        HeapMinInsertNode(ret, &h1->data[i]);
    }
    for (size_t i = 0; i < h2->size; ++i) {
        HeapMinInsertNode(ret, &h2->data[i]);
    }
    return ret;
}
