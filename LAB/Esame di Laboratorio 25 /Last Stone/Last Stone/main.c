#include "elemtype.h"
#include "maxheap.h"
#include <stdlib.h>
extern Heap *HeapMinHeapify(const ElemType *v, size_t v_size);
extern int LastStoneWeight(Heap *h);
int main(void) {
    {
        ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
        
        Heap *ret = NULL;
        ret = HeapMinHeapify(v, 10);
        HeapWriteStdout(ret);
        int last = 0;
        last = LastStoneWeight(ret);
        printf("Last stone is : %d\n", last);
    }
    {
        ElemType v[] = { 77,21,18} ;
        
        Heap *ret = NULL;
        ret = HeapMinHeapify(v, 3);
        HeapWriteStdout(ret);
        int last = 0;
        last = LastStoneWeight(ret);
        printf("Last stone is : %d\n", last);
        return 0;
    }
}
