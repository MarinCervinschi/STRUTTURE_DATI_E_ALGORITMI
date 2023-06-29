#include <stdio.h>
#include <stdbool.h>
bool k =true;
void ElemSwap( int *e1, int *e2){
    int tmp = *e2;
    *e2 = *e1;
    *e1 = tmp;
}void CircleSortRec(int *v, size_t v_size, int i, int size){
    if(size == 0){
        if(!k){
            size = (int)v_size /2 + 1;
        }
        size = (int)v_size /2;
        k = false;
        return;
    }
    if(v[i] < v[size-1]){
        ElemSwap(&v[i], &v[size-1]);
    }
    
    
    
    CircleSortRec(v, v_size, i+1, size-1);
}
void CircleSort(int *v, size_t v_size){
    if(v_size == 0){
        return;
    }
    return CircleSortRec(v, v_size, 0, (int)v_size);
}
