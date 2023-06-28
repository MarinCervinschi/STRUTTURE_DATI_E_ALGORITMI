#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <stdbool.h>
extern Heap *HeapMinHeapify(const ElemType *v, size_t v_size);
extern bool HeapMinPop(Heap *h, ElemType *e);
int main(void) {
    
    ElemType v[] = { 15, 2, 3, 23, 10, 16, 9, 8, 17, 12} ;
    
    Heap *ret = NULL;
    ret = HeapMinHeapify(v, 10);
    ElemType e = 0;
    bool k = HeapMinPop(ret, &e);
    
    if(!k){
        printf("error, è stato passato un heap vuoto!");
    }else{
        printf("il minimo di ret è: %d", e);
    }
    
    
    return 0;
}
