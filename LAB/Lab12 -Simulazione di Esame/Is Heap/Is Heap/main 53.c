#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>
extern Heap *HeapMinHeapify(const ElemType *v, size_t v_size);
extern bool IsHeap(const Heap *h);
int main(void) {
    
    ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
    
    Heap *ret = NULL;
    ret = HeapMinHeapify(v, 10);
    
    bool k =true;
    k = IsHeap(ret);
    
    
    HeapDelete(ret);
    return 0;
}
