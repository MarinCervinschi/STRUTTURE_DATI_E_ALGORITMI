#include "elemtype.h"
#include "minheap.h"
#include <stdbool.h>
void HeapMinHeapsort(Heap *h){
    if(HeapIsEmpty(h)){
        return;
    }
    HeapWriteStdout(h);
    for (size_t i = 0; i != h->size; ++i) {
        size_t minpos = i;
        for (size_t j = i +1; j != h->size; ++j) {
            if(h->data[j] > h->data[minpos]){
                minpos = j;
            }
        }
        if(minpos != i){
            ElemSwap(&h->data[minpos], &h->data[i]);
        }
    }
    return;
}

