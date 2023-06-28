#include "vettore.h"
#include "elemtype.h"
#include <stdlib.h>
void VectorSort(Vector* v){
    if(!v){
        return;
    }
    for(size_t i = 0; i < v->size; ++i){
            size_t minpos = i;
            for (size_t j = i + 1; j < v->size; ++j) {
                if (v->data[j] < v->data[minpos]){
                    minpos = j;
                }
            }

            if (minpos != i){
                ElemSwap(&v->data[minpos], &v->data[i]);
            }
        }
    return;
}
