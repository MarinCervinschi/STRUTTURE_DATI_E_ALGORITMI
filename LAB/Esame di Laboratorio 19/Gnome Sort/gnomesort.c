#include <stdlib.h>
void Swap(int *e1, int *e2){
    int tmp = *e1;
    *e1 = *e2;
    *e2 = tmp;
}
void GnomeSort(int *v, size_t v_size){
    if (!v || v_size <=1) {
        return;
    }
    size_t index = 0;
    
    while (index < v_size) {
        if(index == 0){
            ++index;
        }
        if(v[index] >= v[index -1]){
            ++index;
            
        }else{
            Swap(&v[index], &v[index-1]);
            index--;
        }
    }
}
