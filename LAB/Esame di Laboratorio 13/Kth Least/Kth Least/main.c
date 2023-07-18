#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
extern ElemType KthLeast(const Heap* h, int k);
int main(void) {
    
    ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
    
    size_t v_size = sizeof(v) / sizeof(ElemType);
       
    Heap* h = HeapCreateEmpty();
    for (unsigned i = 0; i < v_size; ++i) {
        HeapMinInsertNode(h, &v[i]);
    }
    HeapWriteStdout(h);
    int Kth = 0;
    Kth = KthLeast(h, 3);
    printf("il 3 numero più piccolo è %d\n", Kth);
    HeapDelete(h);
    
    
    
    return 0;
}
