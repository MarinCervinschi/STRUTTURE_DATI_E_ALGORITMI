#include <stdio.h>
void BinarySearchRec(const int *v, size_t v_size, int value, int i, int *pos, int size){
    if(v_size == 0 || i == size){
        return;
    }
    
    if(value == v[v_size/2]){
        *pos = (int)v_size/2;
        return;
    }
    
    if(value < v[v_size/2]){
        BinarySearchRec(v, v_size/2, value, i+1, pos, size);
    }else{
        BinarySearchRec(v, v_size*2-1, value, i+1, pos, size);
    }
    
}
int BinarySearch(const int *v, size_t v_size, int value){
    
    int pos = -1;
    if(v[v_size-1] < value || !v){
        return pos;
    }
    BinarySearchRec(v, v_size, value,0, &pos, (int)v_size);
    
    return pos;
}
