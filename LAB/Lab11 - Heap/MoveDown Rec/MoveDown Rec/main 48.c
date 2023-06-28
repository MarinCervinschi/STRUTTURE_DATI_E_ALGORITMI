#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
extern Heap *HeapMinHeapify(const ElemType *v, size_t v_size);
extern void HeapMinMoveDownRec(Heap *h, int i);
int main(void) {
    
    ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
    
    Heap *ret = NULL;
    ret = HeapMinHeapify(v, 10);
    ElemSwap(&ret->data[3], &ret->data[7]);
    
    
    return 0;
}
