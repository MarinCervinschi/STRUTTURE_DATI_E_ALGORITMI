#include <stdio.h>
#include "elemtype.h"
#include "list.h"
#include <stdlib.h>

typedef struct {
    ElemType *dati;
    int size;
}Vector;

Vector *CreateVector(const Item *i1){
    int k = 5;
    Vector *v = calloc(1, sizeof(Vector));
    v->dati = calloc(k, sizeof(ElemType));
    int i = 0;
    while (!ListIsEmpty(i1)) {
        if(i == k){
            k *= 2;
            v->dati = realloc(v->dati, k * sizeof(ElemType));
        }
        v->dati[i] = *ListGetHeadValue(i1);
        i1 = ListGetTail(i1);
        ++i;
    }
    v->dati = realloc(v->dati, i * sizeof(ElemType));
    v->size = i;
    return v;
}

int cmpfunc(const void *a, const void *b){
    return (*(int*)a - *(int*)b);
}

Item *IntersectNoRep(const Item *i1, const Item *i2){
    
    Item *list_ret = ListCreateEmpty();
    
    Vector *v1 = CreateVector(i1);
    Vector *v2 = CreateVector(i2);
    qsort(v1->dati, v1->size, sizeof(ElemType), cmpfunc);
    qsort(v2->dati, v2->size, sizeof(ElemType), cmpfunc);
    
    for (int i = 0; i != v1->size; ++i) {
        if(v1->dati[i] == v1->dati[i-1] && i != 0){
            continue;
        }
        for (int j = 0; j != v2->size; ++j) {
            if(v1->dati[i] == v2->dati[j]){
                list_ret = ListInsertBack(list_ret, &v1->dati[i]);
                break;
            }
        }
    }
    
    free(v1->dati);
    free(v2->dati);
    free(v1);
    free(v2);
    return list_ret;
}
Item *DiffNoRep(const Item *i1, const Item *i2){
    
    Item *list_ret = ListCreateEmpty();
    
    Vector *v1 = CreateVector(i1);
    Vector *v2 = CreateVector(i2);
    qsort(v1->dati, v1->size, sizeof(ElemType), cmpfunc);
    qsort(v2->dati, v2->size, sizeof(ElemType), cmpfunc);
    
    for (int i = 0; i != v1->size; ++i) {
        if(v1->dati[i] == v1->dati[i-1] && i != 0){
            continue;
        }
        bool k = true;
        for (int j = 0; j != v2->size; ++j) {
            if(v1->dati[i] == v2->dati[j]){
                k = false;
                break;
            }
        }
        if(k){
            list_ret = ListInsertBack(list_ret, &v1->dati[i]);
        }
        
    }
    
    free(v1->dati);
    free(v2->dati);
    free(v1);
    free(v2);
    return list_ret;
}
