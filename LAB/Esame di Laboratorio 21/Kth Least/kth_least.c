#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
void Pop(Heap* h, ElemType *popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMinMoveDown(h, 0);
    return;
}
int KthLeast(const int* v, size_t n, int k){
    Heap *ret = HeapCreateEmpty();
    for (size_t i = 0; i != n; ++i) {
        HeapMinInsertNode(ret, &v[i]);
    }
    ElemType tmp = 0;
    for (int i = 0; i != k; ++i){
        Pop(ret, &tmp);
    }
    HeapDelete(ret);
    return tmp;
}
