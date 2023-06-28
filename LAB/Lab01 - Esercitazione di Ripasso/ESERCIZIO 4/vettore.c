#include "vettore.h"
#include <stdlib.h>
void Push(struct vettore *v, int d){

    ++v->size;
    v->data = realloc(v->data, v->size * sizeof(int));
    v->data[v->size-1] = d;
    
}



int Pop(struct vettore *v){
    --v->size;
    int k = v->data[0];
    for (size_t i = 0; i != v->size; ++i) {
        v->data[i] = v->data[i+1];
    }
    
    v->data = realloc(v->data, v->size * sizeof(int));
    
    return k;
}
