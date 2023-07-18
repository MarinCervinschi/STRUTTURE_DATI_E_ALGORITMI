#include "elemtype.h"
#include "minheap.h"
#include <stdlib.h>
#include <limits.h>
int TrovaMin(const Heap *h, int *used){
    int min = INT_MAX, index = 0;
    for (size_t i = 0; i < h->size; ++i) {
        if(!used[i]){
            if(h->data[i] < min){
                min = h->data[i];
                index = (int)i;
            }
        }
        
    }
    used[index] = 1;
    return min;
}
ElemType KthLeast(const Heap* h, int k){
    int *used = calloc(h->size, sizeof(int));
    ElemType tmp = 0;
    for (int i = 0; i != k; ++i){
        tmp = TrovaMin(h, used);
    }
    
    free(used);
    return tmp;
}
