#include "elemtype.h"
#include "tree.h"
#include <stdlib.h>
Node *CreateMaxBinTree(const ElemType *v, size_t v_size){
    if(!v || v_size == 0){
        return NULL;
    }
    size_t max_pos = 0;
    
    for (size_t i = 0; i < v_size; ++i) {
        if(v[max_pos] < v[i]){
            max_pos = i;
        }
    }
    
    Node *l = CreateMaxBinTree(v, max_pos);
    
    Node *r = CreateMaxBinTree(v + max_pos + 1, v_size - max_pos - 1);
    
    return TreeCreateRoot(&v[max_pos], l, r);
}
