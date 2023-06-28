#include "vettore.h"
#include "elemtype.h"
#include <stdlib.h>
int VectorFind(const Vector *v, const ElemType *e){
    if (!(*e) || !v) {
        return -1;
    }
    for (size_t i = 0; i != v->size; ++i) {
        if(v->data[i] == *e){
            return (int)i;
        }
    }
    
    return -1;
}
