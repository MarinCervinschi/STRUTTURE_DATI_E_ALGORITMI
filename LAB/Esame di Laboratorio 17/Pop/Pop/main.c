#include <stdlib.h>
#include "minheap.h"
#include "elemtype.h"
extern bool Pop(Heap *h, ElemType *e);
int main(void) {
    {
        ElemType v[] = { 0, 12, 4, 21, 2, 5, 18, 77, 8, -1 };
        size_t v_size = sizeof(v) / sizeof(ElemType);
        
        Heap* h = HeapCreateEmpty();
        for (unsigned i = 0; i < v_size; ++i) {
            HeapMinInsertNode(h, &v[i]);
        }
        HeapWriteStdout(h);
        ElemType e = 0;
        
        bool k = Pop(h, &e);
        HeapWriteStdout(h);
        HeapDelete(h);
    }
    printf("\n");
    {
        ElemType v[] = {1, 3 ,4, 6, 4 };
        size_t v_size = sizeof(v) / sizeof(ElemType);
        
        Heap* h = HeapCreateEmpty();
        for (unsigned i = 0; i < v_size; ++i) {
            HeapMinInsertNode(h, &v[i]);
        }
        HeapWriteStdout(h);
        ElemType e = 0;
        
        bool k = Pop(h, &e);
        HeapWriteStdout(h);
        HeapDelete(h);
    }
    
    return EXIT_SUCCESS;
}
