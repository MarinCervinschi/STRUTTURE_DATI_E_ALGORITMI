#include <stdlib.h> // for size_t
void ElemSwap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void CocktailSort(int *v, size_t v_size){
    if(!v || v_size < 2){
        return;
    }
    int start = 0, end = (int)v_size - 1, done = 0;
    
    while (!done || end > start) {
        done = 1;
        for (int i = start; i < end; ++i) {
            if(v[i] > v[end]){
                ElemSwap(&v[i], &v[end]);
                done = 0;
            }
        }
        --end;
        for (int i = end; i > start; --i) {
            if(v[i] < v[start]){
                ElemSwap(&v[i], &v[start]);
                done = 0;
            }
        }
        ++start;
    }
}
