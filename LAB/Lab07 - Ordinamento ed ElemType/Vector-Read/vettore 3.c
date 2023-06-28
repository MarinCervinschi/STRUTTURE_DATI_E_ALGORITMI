#include "vettore.h"
#include "elemtype.h"
#include <stdio.h>
#include <stdlib.h>
Vector *VectorRead(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        return NULL;
    }
    
    Vector *ret = calloc(1, sizeof(Vector));
    ret->capacity = 1;
    ret->size = 0;
    ret->data = calloc(1, sizeof(ElemType));
    
    for (int i  = 0; ElemRead(f, &ret->data[i]) != EOF; ++i) {
        if(ret->capacity == ret->size + 1){
            ret->capacity *= 2;
            ret->data = realloc(ret->data, ret->capacity  * sizeof(ElemType));
        }
        ret->size++;
    }
    
    ret->capacity = ret->size;
    ret->data = realloc(ret->data, ret->capacity * sizeof(ElemType));
    
    fclose(f);
    return ret;
}

Vector *VectorReadSorted(const char *filename){
    FILE *f = fopen(filename, "r");
    if(!f){
        return NULL;
    }
    
    ElemType tmp = 0;
    Vector *ret = calloc(1, sizeof(Vector));
    while (ElemRead(f, &tmp) != EOF) {
        ret->size++;
    }
    rewind(f);
    ret->data = calloc(ret->size, sizeof(ElemType));
    
    for (size_t i = 0; i != ret->size; ++i) {
        ElemRead(f, &tmp);
        ret->data[i] = tmp;
        if(i == 0 ){
            continue;
        }
        
        size_t minpos = i;
        for (size_t j = 0; j != i; ++j) {
            for (size_t k = i; k != ret->size; ++k) {
                if (ret->data[k] == 0) {
                    continue;
                }
                if(ElemCompare(&ret->data[k], &ret->data[j]) <= 0){
                    minpos = j;
                }
            }
            if( i!= minpos){
                ElemSwap(&ret->data[minpos], &ret->data[i]);
            }
        }
    }
    
    fclose(f);
    return ret;
}
