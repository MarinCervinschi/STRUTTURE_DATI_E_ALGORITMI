#include <stdlib.h> // for size_t
void ElemSwap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void InsertionSort(int *v, size_t v_size){
    if (!v || v_size < 2) {
        return;
    }
    for (size_t i = 1; i < v_size; ++i) {
        for (size_t j = 0; j < i; ++j) {
            if(v[j] > v[i]){
                ElemSwap(&v[j], &v[i]);
            }
        }
    }
}
