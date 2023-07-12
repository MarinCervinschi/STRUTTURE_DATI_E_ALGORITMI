#include <stdlib.h>
void Swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void flip(int *v, size_t i){
    for (size_t h = 0; h < i; ++h){
        for (size_t j = 0 ; j < i-h ; ++j) {
            Swap(&v[j], &v[j+1]);
        }
    }
    
}
void PancakeSort(int *v, size_t v_size){
    if(!v || v_size < 2){
        return;
    }
    size_t curr_size = v_size;
    while (curr_size != 1) {
        //trova max
        size_t max_pos = 0;
        for (size_t i = 0; i < curr_size; ++i) {
            if(v[max_pos] < v[i]){
                max_pos = i;
            }
        }
        //chiama flip per max_pos
        flip(v, max_pos);
        //chiama flip per curr_size -1
        flip(v, curr_size-1);
        --curr_size;
    }
}
