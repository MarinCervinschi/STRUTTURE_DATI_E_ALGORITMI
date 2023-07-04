#include <stdlib.h>
#include <stdbool.h>
int Max(int *v, size_t v_size){
    int max = 0;
    for (size_t i = 0; i != v_size; ++i) {
        if(max < v[i]){
            max = v[i];
        }
    }
    return max;
}
int Min(int *v, size_t v_size){
    int min = v[0];
    for (size_t i = 1; i != v_size; ++i) {
        if(min > v[i]){
            min = v[i];
        }
    }
    return min;
}
void CountingSort(int *v, size_t v_size){
    if (!v || v_size == 0) {
        return;
    }
    int num = Max(v, v_size) - Min(v, v_size) + 1;
    int *tmp = calloc(num, sizeof(int));
    bool *vccur =calloc(v_size, sizeof(bool));
    int tmp2 = Min(v, v_size);
    for (int i = 0; i != num; ++i) {
        for (size_t j = 0; j != v_size; ++j){
            if(v[j] == tmp2 && !vccur[j]){
                ++tmp[i];
                vccur[j] = true;
            }
        }
        ++tmp2;
    }
    int index = 0;
    for (int i = 0; i != num; ++i) {
        for (int j = 0; j != tmp[i]; ++j){
            v[index] = (int)i + Min(v, v_size);
            ++index;
        }
    }
    free(tmp);
    free(vccur);
}
