#include "elemtype.h"
#include "maxheap.h"
#include <stdbool.h>
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
    HeapMaxMoveDown(h, 0);
    return;
}
int LastStoneWeight(Heap *h){
    if(h->size == 0){
        return 0;
    }
    
    while (1) {
        if(h->size == 1){
            break;
        }
        if(h->size == 0){
            break;
        }
        int y = 0;
        Pop(h, &y);
        int x = 0;
        Pop(h, &x);
        if(x == y){
            continue;
        }
        y -= x;
        HeapMaxInsertNode(h, &y);
    }
    if(h->size == 0){
        return 0;
    }else{
        return h->data[0];
    }
}

