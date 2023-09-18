#include <stdio.h>
#include <stdlib.h>
#include "elemtype.h"
#include "doublelist.h"
#include "sum_dlist.h"
Item *DListCreateFromVector(const ElemType *v, size_t v_size) {
    Item *list = DListCreateEmpty();
    for (size_t i = 0; i < v_size; ++i) {
        list = DListInsertBack(list, &v[i]);
    }
    return list;
}
 
int main(void) {
    ElemType v[] = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    size_t v_size = sizeof(v) / sizeof(ElemType);
    const Item *list = DListCreateFromVector(v, v_size);
    DListWriteStdout(list);
    
    printf("+\n");
    
    ElemType v1[] = { 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
    size_t v1_size = sizeof(v1) / sizeof(ElemType);
    const Item *list1 = DListCreateFromVector(v1, v1_size);
    DListWriteStdout(list1);
    
    printf("=\n");
    
    DListWriteStdout(DListSum(list, list1));
    
    
    return 0;
    
}
