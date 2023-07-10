#include <stdlib.h>
#include <stdbool.h>
bool prova(int *v, size_t v_size){
    for (size_t i = 0; i != v_size-1; ++i) {
        if(v[i] > v[i+1]){
            return false;
        }
    }
    return true;
}
void ElemSwap(int *e1, int *e2){
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}
void BrickSort(int* v, size_t v_size){
    if(!v || v_size == 0){
        return;
    }
    while (!prova(v, v_size)) {
        for (size_t i = 1; i < v_size-1; i += 2) {
            if(v[i] > v[i+1]){
                ElemSwap(&v[i], &v[i+1]);
            }
        }
        for (size_t i = 0; i < v_size-1; i += 2) {
            if(v[i] > v[i+1]){
                ElemSwap(&v[i], &v[i+1]);
            }
        }
    }
}
